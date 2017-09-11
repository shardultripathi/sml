import sys
from antlr4 import *
from smlLexer import smlLexer
from smlParser import smlParser
from smlListener import smlListener
from smlAST import *
from smlCodeGen import smlCodeGen
from sml2c import sml2c
import os

def main():
    inputFile = FileStream(sys.argv[1])
    muxCirc = sys.argv[2]
    filename, file_extension = os.path.splitext(sys.argv[1])
    lexer = smlLexer(inputFile)
    stream = CommonTokenStream(lexer)
    parser = smlParser(stream)
    tree = parser.commandSeq()
    flagArr = 0
    if len(sys.argv) > 3:
        flagArr = int(sys.argv[3])
    cpp_debug = sml2c(tree, filename + '_debug' + '.cpp', flagArr)
    ast = getAST(tree)
    scg = smlCodeGen(filename + '.cpp', muxCirc)
    scg.codeGen(ast, False)

if __name__ == '__main__':
    main()