import sys
from antlr4 import *
from smlLexer import smlLexer
from smlParser import smlParser
from smlListener import smlListener
from smlAST import *
from smlCodeGen import smlCodeGen

def main():
    input = FileStream(sys.argv[1])
    lexer = smlLexer(input)
    stream = CommonTokenStream(lexer)
    parser = smlParser(stream)
    tree = parser.commandSeq()
    ast = getAST(tree)
    # ast.visit(0)
    # print()
    scg = smlCodeGen()
    scg.codeGen(ast)

if __name__ == '__main__':
    main()