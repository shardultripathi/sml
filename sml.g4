grammar sml;

commandSeq
    : command*
;

command
    : declaration
    | assignment
//  | ifElse
//  | forLoop
    | '{' commandSeq '}'
    | output
;

declaration
    : (varType Ident)? ';' //{print($varType.text + " " + $Ident.text + ";")}
;

varType
    : 'uint64_t'
    | 'bool'
;

assignment 
    : Ident '=' expr ';' //{print($Ident.text + " = " + $expr.text + ";")}
;

expr
    : arithExpr
    | boolExpr
    | conditionalExpr
    | '(' expr ')'
    | InputA '(' expr ')'
    | InputB '(' expr ')'
;

arithExpr
    : Constant
    | Ident
    | arithExpr BinaryOp arithExpr
    | UnaryOp arithExpr
    | '(' arithExpr ')'
;

boolExpr
    : Ident
    | Constant
    | arithExpr RelationalOp arithExpr
    | '!' boolExpr
    | boolExpr '&' boolExpr
    | boolExpr '|' boolExpr
    | '(' boolExpr ')'
;

conditionalExpr
    : boolExpr '?' expr ':' expr
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

BinaryOp
    : '+'
    | '*'
    | '-'
    | '/'
    | '&'
    | '|'
    | '^'
    | '||'
    | '&&'
    | '%'
    | '<<'
    | '>>'
;

UnaryOp
    : '!'
    | '~'
;

RelationalOp
    : '<'
    | '<='
    | '>'
    | '>='
    | '=='
    | '!='
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