import sys
from antlr4 import *
from smlLexer import smlLexer
from smlParser import smlParser
from smlListener import smlListener
from smlAST import *
from smlCodeGen import smlCodeGen
import os

def main():
    inputFile = FileStream(sys.argv[1])
    lexer = smlLexer(inputFile)
    stream = CommonTokenStream(lexer)
    parser = smlParser(stream)
    tree = parser.commandSeq()
    ast = getAST(tree)
    filename, file_extension = os.path.splitext(sys.argv[1])
    scg = smlCodeGen(filename + '.cpp')
    scg.codeGen(ast, False)

if __name__ == '__main__':
    main()