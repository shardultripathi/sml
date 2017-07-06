grammar sml;

commandSeq
    : command*
;

command
    : declaration
    | assignment
//    | forLoop
    | block
    | output
;

block
    : '{' blockComm* '}'
;

blockComm
    : assignment
//    | forLoop
    | block
// not allowing output inside block
;

declaration
    : (varType Ident)? ';'
;

varType
    : 'uint64_t' // removed bool
;

assignment 
    : Ident '=' expr ';'
    | Ident '=' inputExpr ';'
;

expr
    : arithExpr
    | conditionalExpr
;

arithExpr
    : '(' arithExpr ')'
    | '-' arithExpr
    | arithExpr ('*' | '/' | '%') arithExpr
    | arithExpr ('+' | '-') arithExpr
    | arithExpr ('<<' | '>>') arithExpr
    | arithExpr '&' arithExpr
    | arithExpr '^' arithExpr
    | arithExpr '|' arithExpr
    | arithExpr '&&' arithExpr
    | arithExpr '||' arithExpr
    | Ident
    | Constant
;

conditionalExpr
    : boolExpr '?' expr ':' expr
;

boolExpr
    : '(' boolExpr ')'
    | '!' boolExpr
    | arithExpr ('<' | '<=' | '>' | '>=') arithExpr
    | arithExpr ('==' | '!=') arithExpr
    | boolExpr '&' boolExpr
    | boolExpr '^' boolExpr
    | boolExpr '|' boolExpr
    | boolExpr '&&' boolExpr
    | boolExpr '||' boolExpr
    | Constant
    | Ident
;

inputExpr
    : InputA '(' arithExpr ')'
    | InputB '(' arithExpr ')'
;

output
    : Output '(' expr ')' ';'
;

InputA
    : 'input1'
;

InputB
    : 'input2'
;

Output
    : 'output'
;

RelationalOp
    : '<'
    | '<='
    | '>'
    | '>='
    | '=='
    | '!='
;

// code below copied from c grammar
Ident
    :   IdentNondigit
        (   IdentNondigit
        |   Digit
        )*
;

fragment
IdentNondigit
    :   Nondigit
//  |   // other implementation-defined characters...
;

fragment
Nondigit
    :   [a-zA-Z_]
;

fragment
Digit
    :   [0-9]
;

Constant
    :   IntegerConstant
    |   BoolConstant
;

fragment
IntegerConstant
    :   DecimalConstant
;

fragment
DecimalConstant
    :   Digit+
;

fragment
NonzeroDigit
    :   [1-9]
;

fragment
BoolConstant
    :   'true'
    |   'false'
;

WS : [ \t\r\n]+ -> skip ; // skip spaces, tabs, newlines