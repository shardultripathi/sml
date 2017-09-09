from antlr4 import *
from io import StringIO
from typing.io import TextIO
from smlParser import smlParser as sp
from smlLexer import smlLexer as sl
import sys

class sml2c:
    def __init__(self, tree, filename, flagArr=0):
        self.file = open(filename, 'w')
        self.flagArr = flagArr
        print('#include <iostream>', file=self.file)
        print('#include <vector>', file=self.file)
        print('using namespace std;', file=self.file)
        print("namespace details {", file=self.file)
        print("template<class T>struct tag{using type=T;};", file=self.file)
        print("template<class Tag>using type=typename Tag::type;", file=self.file)         
        print("template<class T, size_t n>", file=self.file)
        print("struct n_dim_vec:tag< std::vector< type< n_dim_vec<T, n-1> > > > {"+"};", file=self.file)
        print("template<class T>", file=self.file)
        print("struct n_dim_vec<T, 0>:tag<T>{"+"};", file=self.file)
        print("template<class T, size_t n>", file=self.file)
        print("using n_dim_vec_t = type<n_dim_vec<T,n>>;", file=self.file)
        print("template <class T, class R=std::vector<T>>", file=self.file)
        print("R make_vector(size_t size) {", file=self.file)
        print("return R(size);", file=self.file)
        print("}", file=self.file)
        print("template<class T, class...Args, class R=n_dim_vec_t<T, sizeof...(Args)+1>>", file=self.file)
        print("R make_vector(size_t top, Args...args){", file=self.file)
        print("return R(top, make_vector<T>(std::forward<Args>(args)...));", file=self.file)
        print("}", file=self.file)
        print("}", file=self.file)
        print("template <class T, class... Args, class R=details::n_dim_vec_t<T, sizeof...(Args)>>", file=self.file)
        print("R make_vector(Args... args)", file=self.file)
        print("{ return details::make_vector<T>(std::forward<Args>(args)...); }", file=self.file)
        print('int main() {', file=self.file)
        self.codeGen(tree)
        print('}', file=self.file)

    def makeVec(self, vecname, vectype, refctx):
        print('auto', vecname, '= make_vector<'+vectype+'>(', end='', file=self.file)
        for x in range(1,refctx.getChildCount(),3):
            num = refctx.getChild(x)
            if x == 1:
                print(num, end='', file=self.file)
            else:
                print(',',num, end='', file=self.file)
        print(');', file=self.file)


    def codeGen(self, node):
        if isinstance(node, sp.CommandSeqContext):
            for i in range(0, node.getChildCount()):
                self.codeGen(node.getChild(i).getChild(0))

        if isinstance(node, sp.DeclarationContext):
            if node.getChildCount() > 1:
                if isinstance(node.getChild(1), sp.ArrDeclContext):
                    arrdecl = node.getChild(1)
                    if self.flagArr == 0:
                        self.makeVec(arrdecl.getChild(0).getText(), node.getChild(0).getText(), arrdecl.getChild(1))
                    else:
                        print(node.getChild(0).getText(), node.getChild(1).getText(), ';', file=self.file)
                else:
                    print(node.getChild(0).getText(), node.getChild(1).getText(), ';', file=self.file)

        elif isinstance(node, sp.AssignmentContext):
            lhs = node.getChild(0).getText() + ' ='
            if isinstance(node.getChild(2), sp.InputExprContext):
                rhs = node.getChild(2).getChild(2).getText() + ';'
            else:
                rhs = node.getChild(2).getText() + ';'
            print(lhs, rhs, file=self.file)

        elif isinstance(node, sp.ForLoopContext):
            name = node.getChild(2).getText()
            rangelist = node.getChild(4)
            start = rangelist.getChild(1).getText()
            end = rangelist.getChild(3).getText()
            if rangelist.getChildCount() > 5:
                step = name + ' += ' + rangelist.getChild(5).getText()
            else:
                step = name + '++'
            print('for (uint32_t',name,'=',start+';',name,'<',end+';',step+')', file=self.file)
            self.codeGen(node.getChild(5))

        elif isinstance(node, sp.BlockContext):
            print('{', file=self.file)
            for i in range(1, node.getChildCount()):
                self.codeGen(node.getChild(i).getChild(0))
            print('}', file=self.file)

        elif isinstance(node, sp.OutputContext):
            print('cout <<', node.getChild(2).getText(), '<< endl;', file=self.file)






