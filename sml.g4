grammar sml;

commandSeq
    : command*
;

command
    : declaration
    | assignment
    | forLoop
    | block
    | output
;

block
    : '{' blockComm* '}'
;

blockComm
    : assignment
    | forLoop
    | block
// not allowing output inside block
;

declaration
    : (varType Ident)? ';'
;

varType
    : 'uint32_t' // removed bool
;

assignment 
    : Ident '=' expr ';'
    | Ident '=' inputExpr ';'
;

forLoop
    : 'for' 'uint32_t' Ident '=' rangeList block
;

rangeList
   : '[' IntegerConstant ':' IntegerConstant (':' IntegerConstant)? ']'
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
    | arithExpr '&' arithExpr // bitwise and
    | arithExpr '^' arithExpr
    | arithExpr '|' arithExpr // bitwise or
//    | arithExpr '&&' arithExpr // logical and
//    | arithExpr '||' arithExpr // logical or
    | IntegerConstant
    | Ident
;

conditionalExpr
    : boolExpr '?' expr ':' expr
;

boolExpr
    : '(' boolExpr ')'
    | '!' boolExpr
    | arithExpr ('<' | '<=' | '>' | '>=') arithExpr
    | arithExpr ('==' | '!=') arithExpr
//    | boolExpr '&' boolExpr
    | boolExpr '^' boolExpr
//    | boolExpr '|' boolExpr
    | boolExpr '&&' boolExpr
    | boolExpr '||' boolExpr
    | BoolConstant
    | Ident
;

inputExpr
    : InputA '(' expr ')'
    | InputB '(' expr ')'
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

// code below taken from c grammar

BoolConstant
    :   'true'
    |   'false'
;

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
    :   [a-zA-Z]
;

fragment
Digit
    :   [0-9]
;

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

WS : [ \t\r\n]+ -> skip ; // skip spaces, tabs, newlines