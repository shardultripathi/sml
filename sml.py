import sys
from antlr4 import *
from smlLexer import smlLexer
from smlParser import smlParser
from smlListener import smlListener
from smlAST import *

class CommandPrinter(smlListener):     
    def enterCommand(self, ctx):         
        print(ctx.start, ctx.stop) 

def main():
    input = FileStream(sys.argv[1])
    lexer = smlLexer(input)
    stream = CommonTokenStream(lexer)
    parser = smlParser(stream)
    tree = parser.commandSeq()
    walker = ParseTreeWalker()
    ast = getAST(tree)
    # cp = CommandPrinter()
    # walker.walk(cp,tree)
    # for child in tree.getChildren():
    # 	print(1);

if __name__ == '__main__':
    main()