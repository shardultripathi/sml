import sys
from antlr4 import *
from smlLexer import smlLexer
from smlParser import smlParser
from smlAST import *

class smlCodeGen:
    def __init__(self):
        print('<insert boilerplate code>')
        self.shareSet = set()
        self.counter = 0

    def codeGen(self, node):
        if isinstance(node, CommSeq):
            for com in node.children:
                self.codeGen(com)

        elif isinstance(node, Block):
            print('{')
            for bcom in node.children:
                self.codeGen(bcom)
            print('}')

        elif isinstance(node, Decl):
            print(node.data_type.idtype + ' ' + node.idname.name + ';')
            print('share *s_' + node.idname.name + ';')
            self.shareSet.add('s_'+node.idname.name)

        elif isinstance(node, Ident):
            return 's_'+node.name

        elif isinstance(node, Constant):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            print('share *',varname,'=','circ->PutCONSGate(',node.value,',bitlen);')
            return varname

        elif isinstance(node, UnOp):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            expr = self.codeGen(node.expr)
            print('share *',varname,'=','circ->PutINVGate(', expr,');')
            return varname

        elif isinstance(node, BinOp):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            rhs = self.codeGen(node.rhs)
            lhs = self.codeGen(node.lhs)
            print('share *',varname,'=','circ->', end='')
            if node.op == '+':
                print('PutADDGate(',lhs,',',rhs,');')
            elif node.op == '*':
                print('PutMULGate(',lhs,',',rhs,');')
            elif node.op == '-':
                print('PutSUBGate(',lhs,',',rhs,');')
            elif node.op == '>':
                print('PutGTGate(',lhs,',',rhs,');')
            elif node.op == '<':
                print('PutGTGate(',rhs,',',lhs,');')
            elif node.op == '&&' or node.op == '&':
                print('PutANDGate(',lhs,',',rhs,');')
            elif node.op == '|' or node.op == '||':
                print('PutORGate(',lhs,',',rhs,');')
            elif node.op == '^':
                print('PutXORGate(',lhs,',',rhs,');')
            else:
                print('I will do this later:', node.op)
            return varname

        elif isinstance(node, Assign):
            varname = 's_'+node.lhs.name
            rhs = node.rhs
            if isinstance(rhs, Ident):
                print(varname,'=',end=' ')
                print('create_new_share(','s_'+rhs.name,'->get_wire_ids(),circ);')

            elif isinstance(rhs, Constant):
                print(node.lhs.name,'=',rhs.value,';')
                print(varname,'=',end=' ')
                print('circ->PutCONSGate(',rhs.value,',bitlen);')

            elif isinstance(rhs, BinOp):
                binlhs = self.codeGen(rhs.lhs)
                binrhs = self.codeGen(rhs.rhs)
                print(varname,'=',end=' ')
                if rhs.op == '+':
                    print('circ->PutADDGate(',binlhs,',',binrhs,');')
                elif rhs.op == '*':
                    print('circ->PutMULGate(',binlhs,',',binrhs,');')
                elif rhs.op == '-':
                    print('circ->PutSUBGate(',binlhs,',',binrhs,');')
                elif rhs.op == '>':
                    print('circ->PutGTGate(',binlhs,',',binrhs,');')
                elif rhs.op == '<':
                    print('circ->PutGTGate(',binrhs,',',binlhs,');')
                elif rhs.op == '&&' or rhs.op == '&':
                    print('circ->PutANDGate(',binlhs,',',binrhs,');')
                elif rhs.op == '||' or rhs.op == '|':
                    print('circ->PutORGate(',binlhs,',',binrhs,');')
                elif rhs.op == '^':
                    print('circ->PutXORGate(',binlhs,',',binrhs,');')
                else:
                    print('I will do this later:', node.op)

            elif isinstance(rhs, UnOp):
                expr = self.codeGen(rhs.expr)
                print(varname,'=',end=' ')
                print('circ->PutINVGate(',expr,');')

            elif isinstance(rhs, CondExpr):
                sel = self.codeGen(rhs.condition)
                ina = self.codeGen(rhs.expr1)
                inb = self.codeGen(rhs.expr2)
                print(varname,'=',end=' ')
                print('circ->PutMUXGate(',ina,',',inb,',',sel,');')

            elif isinstance(rhs, InpExpr):
                print(node.lhs.name,'=',rhs.exprText,';')
                if rhs.partynum == 'input1':
                    print('if (role == SERVER) {')
                    print(varname,'= circ->PutINGate(',node.lhs.name,',bitlen,SERVER);')
                    print('} else {')
                    print(varname,'= circ->PutDummyINGate(bitlen);\n}')
                else:
                    print('if (role == CLIENT) {')
                    print(varname,'= circ->PutINGate(',node.lhs.name,',bitlen,CLIENT);')
                    print('} else {')
                    print(varname,'= circ->PutDummyINGate(bitlen);\n}')

            else:
                print('I should not be here')

        elif isinstance(node, CondExpr):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            sel = self.codeGen(node.condition)
            ina = self.codeGen(node.expr1)
            inb = self.codeGen(node.expr2)
            print('share *', varname,'=',end=' ')
            print('circ->PutMUXGate(',ina,',',inb,',',sel,');')
            return varname

        elif isinstance(node, OutExpr):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            expr = self.codeGen(node.expr)
            print(varname,'= circ->PutOUTGate(',expr,', ALL);')
            print('party->ExecCircuit();')
            print('uint64_t _output =', varname + '->get_clear_value<uint64_t>();')

        else:
            pass