import sys
from antlr4 import *
from smlLexer import smlLexer
from smlParser import smlParser

def main():
    input = FileStream(sys.argv[1])
    lexer = smlLexer(input)
    stream = CommonTokenStream(lexer)
    parser = smlParser(stream)
    tree = parser.commandSeq()
    # print(tree.toStringTree(recog=parser))

if __name__ == '__main__':
    main()