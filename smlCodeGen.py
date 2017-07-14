import sys
from antlr4 import *
from smlLexer import smlLexer
from smlParser import smlParser
from smlAST import *
from enum import Enum

ckt = Enum('ckt', 'ycirc acirc bcirc')
convert = {
            ('ycirc','acirc') : 'PutY2AGate',
            ('ycirc','bcirc') : 'PutY2BGate',
            ('acirc','ycirc') : 'PutA2YGate',
            ('acirc','bcirc') : 'PutA2BGate',
            ('bcirc','acirc') : 'PutB2AGate',
            ('bcirc','ycirc') : 'PutB2YGate'
}

class smlCodeGen:
    def __init__(self):
        print('ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg);')
        print('vector<Sharing*>& sharings = party->GetSharings();')
        print('Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();')
        print('Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();')
        print('Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();')
        self.dict = {}
        self.counter = 0
        self.defckt = 'ycirc'
        self.circ = 'acirc'

    def checkType(self, expr, target):
        if self.dict[expr] != target:
            pair = (self.dict[expr],target)
            x = ''
            if pair == ('acirc','bcirc'):
                x = ',ycirc'
            elif pair == ('ycirc','acirc'):
                x = ',bcirc'
            print(expr,'=',target+'->'+convert[pair]+'(',expr,x+');')
            self.dict[expr] = target

    def codeGen(self, node, circ=None):
        if isinstance(node, CommSeq):
            for com in node.children:
                self.codeGen(com)

        elif isinstance(node, Block):
            print('{')
            for bcom in node.children:
                self.codeGen(bcom)
            print('}')

        elif isinstance(node, Decl):
            name = node.idname.name
            print(node.data_type.idtype, name + ';')
            print('share *s_' + name + ';')

        elif isinstance(node, Ident):
            return 's_'+node.name

        elif isinstance(node, Constant):
            varname = 's_tmp_'+str(self.counter)
            tmpvar = '_tmp_'+str(self.counter)
            self.counter += 1
            print(node.idtype, tmpvar, '=', node.value,';')
            if circ == None:
                circ = self.circ # or defckt?
            print('share *',varname,'=',circ+'->PutCONSGate(',tmpvar,',bitlen);')
            self.dict[varname] = circ
            return varname

        elif isinstance(node, UnOp):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            if circ == None:
                circ = self.circ
            expr = self.codeGen(node.expr, circ) # check expr type
            self.checkType(expr, circ)
            print('share *',varname,'=',circ+'->PutINVGate(', expr,');')
            self.dict[varname] = circ
            return varname

        elif isinstance(node, BinOp):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            if node.op == '+':
                circ = 'acirc'
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutADDGate(',lhs,',',rhs,');')
                self.dict[varname] = circ
            elif node.op == '*':
                circ = 'acirc'
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutMULGate(',lhs,',',rhs,');')
                self.dict[varname] = circ
            elif node.op == '-':
                circ = 'acirc'
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutSUBGate(',lhs,',',rhs,');')
                self.dict[varname] = circ
            elif node.op == '>':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutGTGate(',lhs,',',rhs,');')
                self.dict[varname] = circ
            elif node.op == '<':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutGTGate(',rhs,',',lhs,');')
                self.dict[varname] = circ
            elif node.op == '&&' or node.op == '&':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutANDGate(',lhs,',',rhs,');')
                self.dict[varname] = circ
            elif node.op == '|' or node.op == '||':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutORGate(',lhs,',',rhs,');')
                self.dict[varname] = circ
            elif node.op == '^':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutXORGate(',lhs,',',rhs,');')
                self.dict[varname] = circ
            else:
                print('I will do this later:', node.op)
            return varname

        elif isinstance(node, Assign):
            varname = 's_'+node.lhs.name
            rhs = node.rhs
            if circ == None:
                circ = self.circ

            if isinstance(rhs, Ident):
                print(varname,'= create_new_share(s_'+rhs.name,'->get_wire_ids(),',circ,');')

            elif isinstance(rhs, Constant):
                print(node.lhs.name,'=',rhs.value,';')
                print(varname,'=',circ+'->PutCONSGate(',node.lhs.name,',bitlen);')

            elif isinstance(rhs, BinOp):
                if rhs.op == '+':
                    circ = 'acirc'
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutADDGate(',binlhs,',',binrhs,');')
                    self.dict[varname] = circ
                elif rhs.op == '*':
                    circ = 'acirc'
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutMULGate(',binlhs,',',binrhs,');')
                    self.dict[varname] = circ
                elif rhs.op == '-':
                    circ = 'acirc'
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutSUBGate(',binlhs,',',binrhs,');')
                    self.dict[varname] = circ
                elif rhs.op == '>':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutGTGate(',binlhs,',',binrhs,');')
                    self.dict[varname] = circ
                elif rhs.op == '<':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutGTGate(',binrhs,',',binlhs,');')
                    self.dict[varname] = circ
                elif rhs.op == '&&' or rhs.op == '&':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutANDGate(',binlhs,',',binrhs,');')
                    self.dict[varname] = circ
                elif rhs.op == '||' or rhs.op == '|':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutORGate(',binlhs,',',binrhs,');')
                    self.dict[varname] = circ
                elif rhs.op == '^':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutXORGate(',binlhs,',',binrhs,');')
                    self.dict[varname] = circ
                else:
                    print('I will do this later:', node.op)

            elif isinstance(rhs, UnOp):
                expr = self.codeGen(rhs.expr, circ)
                circ = self.dict[expr]
                print(varname,'=',circ+'->PutINVGate(',expr,');')
                self.dict[varname] = circ

            elif isinstance(rhs, CondExpr):
                circ = self.defckt
                sel = self.codeGen(rhs.condition, circ)
                ina = self.codeGen(rhs.expr1, circ)
                inb = self.codeGen(rhs.expr2, circ)
                self.checkType(sel, circ)
                self.checkType(ina, circ)
                self.checkType(inb, circ)
                print(varname,'=',circ+'->PutMUXGate(',ina,',',inb,',',sel,');')

            elif isinstance(rhs, InpExpr):
                print(node.lhs.name,'=',rhs.exprText,';')
                if rhs.partynum == 'input1':
                    print('if (role == SERVER) {')
                    print(varname,'=',circ+'->PutINGate(',node.lhs.name,',bitlen,SERVER);')
                    print('} else {')
                    print(varname,'=',circ+'->PutDummyINGate(bitlen);\n}')
                else:
                    print('if (role == CLIENT) {')
                    print(varname,'=',circ+'->PutINGate(',node.lhs.name,',bitlen,CLIENT);')
                    print('} else {')
                    print(varname,'=',circ+'->PutDummyINGate(bitlen);\n}')
                self.dict[varname] = circ

            else:
                print('I should not be here')
            self.circ = circ

        elif isinstance(node, CondExpr):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            circ = self.defckt
            sel = self.codeGen(node.condition, circ)
            ina = self.codeGen(node.expr1, circ)
            inb = self.codeGen(node.expr2, circ)
            self.checkType(sel, circ)
            self.checkType(ina, circ)
            self.checkType(inb, circ)
            print('share *', varname,'=',circ+'->PutMUXGate(',ina,',',inb,',',sel,');')
            self.dict[varname] = circ
            return varname

        elif isinstance(node, OutExpr):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            expr = self.codeGen(node.expr)
            circ = self.dict[expr]
            print('share *',varname,'=',circ+'->PutOUTGate(',expr,', ALL);')
            self.dict[varname] = circ
            print('party->ExecCircuit();')
            print('uint32_t _output =', varname + '->get_clear_value<uint32_t>();')

        else:
            pass