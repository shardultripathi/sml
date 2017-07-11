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
            else:
                print('I will do this later')
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
                else:
                    print('I will do this later')

            elif isinstance(rhs, UnOp):
                expr = self.codeGen(rhs.expr)
                print(varname,'=',end=' ')
                print('circ->PutINVGate(',expr,');')

            elif isinstance(rhs, CondExpr):
                print(varname,'=',end=' ')
                print('I will do this later')

            elif isinstance(rhs, InpExpr):
                print(varname,'=',end=' ')
                print('I will do this later')

            else:
                print('I should not be here')

        else:
            pass