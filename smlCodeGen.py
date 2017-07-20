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
        self.dict = {}
        self.counter = 0
        self.defckt = 'ycirc'
        self.circ = 'acirc'
        self.file = open('output.txt', 'a')
        print('ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg);', file=self.file)
        print('vector<Sharing*>& sharings = party->GetSharings();', file=self.file)
        print('Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();', file=self.file)
        print('Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();', file=self.file)
        print('Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();', file=self.file)

    def checkType(self, expr, target):
        if '[' in expr:
            return
        if self.dict[expr] != target:
            pair = (self.dict[expr],target)
            x = ''
            if pair == ('acirc','bcirc'):
                x = ',ycirc'
            elif pair == ('ycirc','acirc'):
                x = ',bcirc'
            print(expr,'=',target+'->'+convert[pair]+'(',expr,x+');', file=self.file)
            self.dict[expr] = target

    def codeGen(self, node, circ=None):
        if isinstance(node, CommSeq):
            for com in node.children:
                self.codeGen(com)

        elif isinstance(node, Block):
            print('{', file=self.file)
            for bcom in node.children:
                self.codeGen(bcom)
            print('}', file=self.file)

        elif isinstance(node, Decl):
            name = ''
            if isinstance(node.idname, Ident):
                name = node.idname.name
            else:
                name = node.idname.idname.name + node.idname.ref
            print(node.data_type.idtype, name + ';', file=self.file)
            print('share *s_' + name + ';', file=self.file)

        elif isinstance(node, Ident):
            return 's_'+node.name

        elif isinstance(node, ArrayPub):
            return 's_'+node.idname.name+node.ref

        elif isinstance(node, ForLoop):
            name = node.idname.name
            step = ''
            if node.step == '1':
                step = name + '++'
            else:
                step = name + ' += ' + node.step
            print('for (uint32_t',name,'=',node.start+';',name,'<',node.end+';',step+')', file=self.file)
            self.codeGen(node.block)

        elif isinstance(node, Constant):
            varname = 's_tmp_'+str(self.counter)
            tmpvar = '_tmp_'+str(self.counter)
            self.counter += 1
            print(node.idtype, tmpvar, '=', node.value,';', file=self.file)
            if circ == None:
                circ = self.circ # or defckt?
            print('share *',varname,'=',circ+'->PutCONSGate(',tmpvar,',bitlen);', file=self.file)
            self.dict[varname] = circ
            return varname

        elif isinstance(node, UnOp):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            if circ == None:
                circ = self.circ
            expr = self.codeGen(node.expr, circ) # check expr type
            self.checkType(expr, circ)
            print('share *',varname,'=',circ+'->PutINVGate(', expr,');', file=self.file)
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
                print('share *',varname,'=',circ+'->PutADDGate(',lhs,',',rhs,');', file=self.file)
                self.dict[varname] = circ
            elif node.op == '*':
                circ = 'acirc'
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutMULGate(',lhs,',',rhs,');', file=self.file)
                self.dict[varname] = circ
            elif node.op == '-':
                circ = 'acirc'
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutSUBGate(',lhs,',',rhs,');', file=self.file)
                self.dict[varname] = circ
            elif node.op == '>':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutGTGate(',lhs,',',rhs,');', file=self.file)
                self.dict[varname] = circ
            elif node.op == '<':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutGTGate(',rhs,',',lhs,');', file=self.file)
                self.dict[varname] = circ
            elif node.op == '&&' or node.op == '&':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutANDGate(',lhs,',',rhs,');', file=self.file)
                self.dict[varname] = circ
            elif node.op == '|' or node.op == '||':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutORGate(',lhs,',',rhs,');', file=self.file)
                self.dict[varname] = circ
            elif node.op == '^':
                circ = self.defckt
                lhs = self.codeGen(node.lhs, circ)
                rhs = self.codeGen(node.rhs, circ)
                self.checkType(lhs, circ)
                self.checkType(rhs, circ)
                print('share *',varname,'=',circ+'->PutXORGate(',lhs,',',rhs,');', file=self.file)
                self.dict[varname] = circ
            else:
                print('I will do this later:', node.op, file=self.file)
            return varname

        elif isinstance(node, Assign):
            varname = self.codeGen(node.lhs)
            rhs = node.rhs
            if circ == None:
                circ = self.circ
            lhsname = ''
            if isinstance(node.lhs, ArrayPub):
                lhsname = node.lhs.idname.name + node.lhs.ref
            else:
                lhsname = node.lhs.name

            if isinstance(rhs, Ident):
                print(varname,'= create_new_share(s_'+rhs.name+'->get_wire_ids(),',circ,');', file=self.file)

            elif isinstance(rhs, ArrayPub):
                rhsname = self.codeGen(rhs)
                print(varname,'= create_new_share('+rhsname+'->get_wire_ids(),',circ,');', file=self.file) 

            elif isinstance(rhs, Constant):
                print(lhsname,'=',rhs.value,';', file=self.file)
                print(varname,'=',circ+'->PutCONSGate(',lhsname,',bitlen);', file=self.file)

            elif isinstance(rhs, BinOp):
                if rhs.op == '+':
                    circ = 'acirc'
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutADDGate(',binlhs,',',binrhs,');', file=self.file)
                    self.dict[varname] = circ
                elif rhs.op == '*':
                    circ = 'acirc'
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutMULGate(',binlhs,',',binrhs,');', file=self.file)
                    self.dict[varname] = circ
                elif rhs.op == '-':
                    circ = 'acirc'
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutSUBGate(',binlhs,',',binrhs,');', file=self.file)
                    self.dict[varname] = circ
                elif rhs.op == '>':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutGTGate(',binlhs,',',binrhs,');', file=self.file)
                    self.dict[varname] = circ
                elif rhs.op == '<':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutGTGate(',binrhs,',',binlhs,');', file=self.file)
                    self.dict[varname] = circ
                elif rhs.op == '&&' or rhs.op == '&':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutANDGate(',binlhs,',',binrhs,');', file=self.file)
                    self.dict[varname] = circ
                elif rhs.op == '||' or rhs.op == '|':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutORGate(',binlhs,',',binrhs,');', file=self.file)
                    self.dict[varname] = circ
                elif rhs.op == '^':
                    circ = self.defckt
                    binlhs = self.codeGen(rhs.lhs, circ)
                    binrhs = self.codeGen(rhs.rhs, circ)
                    self.checkType(binlhs, circ)
                    self.checkType(binrhs, circ)
                    print(varname,'=',circ+'->PutXORGate(',binlhs,',',binrhs,');', file=self.file)
                    self.dict[varname] = circ
                else:
                    print('I will do this later:', node.op, file=self.file)

            elif isinstance(rhs, UnOp):
                expr = self.codeGen(rhs.expr, circ)
                circ = self.dict[expr]
                print(varname,'=',circ+'->PutINVGate(',expr,');', file=self.file)
                self.dict[varname] = circ

            elif isinstance(rhs, CondExpr):
                circ = self.defckt
                sel = self.codeGen(rhs.condition, circ)
                ina = self.codeGen(rhs.expr1, circ)
                inb = self.codeGen(rhs.expr2, circ)
                self.checkType(sel, circ)
                self.checkType(ina, circ)
                self.checkType(inb, circ)
                print(varname,'=',circ+'->PutMUXGate(',ina,',',inb,',',sel,');', file=self.file)

            elif isinstance(rhs, InpExpr):
                print(lhsname,'=',rhs.exprText,';', file=self.file)
                if rhs.partynum == 'input1':
                    print('if (role == SERVER) {', file=self.file)
                    print(varname,'=',circ+'->PutINGate(',lhsname,',bitlen,SERVER);', file=self.file)
                    print('} else {', file=self.file)
                    print(varname,'=',circ+'->PutDummyINGate(bitlen);\n}', file=self.file)
                else:
                    print('if (role == CLIENT) {', file=self.file)
                    print(varname,'=',circ+'->PutINGate(',lhsname,',bitlen,CLIENT);', file=self.file)
                    print('} else {', file=self.file)
                    print(varname,'=',circ+'->PutDummyINGate(bitlen);\n}', file=self.file)
                self.dict[varname] = circ

            else:
                print('I should not be here', file=self.file)
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
            print('share *', varname,'=',circ+'->PutMUXGate(',ina,',',inb,',',sel,');', file=self.file)
            self.dict[varname] = circ
            return varname

        elif isinstance(node, OutExpr):
            varname = 's_tmp_'+str(self.counter)
            self.counter += 1
            expr = self.codeGen(node.expr)
            circ = self.dict[expr]
            print('share *',varname,'=',circ+'->PutOUTGate(',expr,', ALL);', file=self.file)
            self.dict[varname] = circ
            print('party->ExecCircuit();', file=self.file)
            print('uint32_t _output =', varname + '->get_clear_value<uint32_t>();', file=self.file)

        else:
            pass