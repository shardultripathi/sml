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
    | ifElse
;

block
    : '{' blockComm* '}'
;

blockComm
    : assignment
    | forLoop
    | block
    | ifElse
// not allowing declaration and output inside block
;

declaration
    : varType arrDecl ';'
    | ('public'? varType Ident)? ';'
;

varType
    : 'uint32_t' 
    | 'uint16_t' // removed bool
;

assignment 
    : arrExpr '=' expr ';'
    | Ident '=' expr ';'
    | arrExpr '=' inputExpr ';'
    | Ident '=' inputExpr ';'
;

arrDecl
    : Ident intRef
;

intRef
    : ('[' IntegerConstant ']')+
;

arrExpr
    : Ident intIdRef
;

intIdRef
   : ('[' arithExpr ']')+
;

forLoop
    : 'for' 'uint32_t' Ident '=' rangeList block
;

rangeList
   : '[' IntegerConstant ':' IntegerConstant (':' IntegerConstant)? ']'
;

ifElse
    :   'if' '(' boolExpr ')' blockComm ('else' blockComm)?
;

expr
    : arithExpr
    | conditionalExpr
;

// TODO: / % >> <<
arithExpr
    : '(' arithExpr ')'
    | '-' arithExpr
    | '~' arithExpr
    | arithExpr ('*' | '/' | '%') arithExpr
    | arithExpr ('+' | '-') arithExpr
    | arithExpr ('<<' | '>>' | '@>') IntegerConstant
    | arithExpr '&' arithExpr // bitwise and
    | arithExpr '^' arithExpr // bitwise xor
    | arithExpr '|' arithExpr // bitwise or
    | IntegerConstant
    | arrExpr
    | Ident
;

conditionalExpr
    : '(' conditionalExpr ')' 
    | boolExpr '?' expr ':' expr
;

// TODO: <= >= == !=
boolExpr
    : '(' boolExpr ')'
    | '!' boolExpr
    | arithExpr ('<' | '<=' | '>' | '>=') arithExpr
    | arithExpr ('==' | '!=') arithExpr
    | boolExpr '^' boolExpr
    | boolExpr '&&' boolExpr
    | boolExpr '||' boolExpr
    | BoolConstant
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

LineComment
    : '//' ~[\r\n]* -> channel(HIDDEN)
;