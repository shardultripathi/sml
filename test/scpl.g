program:
	declaration_list procedure_definition_list
;

declaration_list:
	procedure_declaration_list
|
	variable_declaration_list procedure_declaration_list
|
	procedure_declaration variable_declaration_list
;

procedure_declaration_list:
	procedure_declaration
|
	procedure_declaration_list procedure_declaration
;

procedure_declaration:
	var_data_type NAME '(' optional_procedure_argument_list ')' ';'
|
	VOID NAME '(' optional_procedure_argument_list ')' ';'
;

optional_procedure_argument_list:
	/* empty */
|
	procedure_argument_list
;

procedure_argument_list:
	procedure_argument
|
	procedure_argument_list ',' procedure_argument
;

procedure_argument:
	var_data_type NAME
;

procedure_definition_list:
	procedure_definition
|
	procedure_definition_list procedure_definition
;

procedure_definition:
	NAME '(' optional_procedure_argument_list ')'
	'{' optional_variable_declaration_list statement_list return_statement '}'
;

var_data_type:
	INTEGER
|
	FLOAT
;

optional_variable_declaration_list:
	/* empty */
|
	variable_declaration_list
;

variable_declaration_list:
	variable_declaration
|
	variable_declaration_list variable_declaration
;

variable_declaration:
	declaration ';'
;

declaration:
	var_data_type NAME id_list 
;

id_list:
	/* empty */
|
	',' NAME id_list

statement_list:
	/* empty */
|
	statement_list statement
;

statement:
	if_else_statement
|
	while_statement
|
	do_while_statement
|
	for_statement
|
	assignment_statement
|
	'{' statement_list '}'
|
	procedure_call ';'
|
	return_statement
|
	print_statemnt
;

assignment_statement:
	variable ASSIGN arith_expression ';'
;

do_while_statement:
	DO statement WHILE '(' boolean_expression ')' ';'
;

while_statement:
	WHILE '(' boolean_expression ')' statement
;

if_else_statement:
	IF '(' boolean_expression ')' statement 	%prec THEN

|	
	IF '(' boolean_expression ')' statement ELSE statement
;

for_statement:
	FOR '(' for_decl ';' boolean_expression ';' for_decl ')' statement
;

for_decl:
	/* empty */
|
	variable ASSIGN arith_expression
;

arith_expression:
	operand '+' operand
|
	operand '-' operand
|
	operand '*' operand
|
	operand '/' operand
|
	'-' operand %prec UMINUS
|
	boolean_expression '?' arith_expression ':' arith_expression
|
	'(' operand ')'
|
	expression_term
;

boolean_expression:
	'!' boolean_expression
|
	boolean_expresion '&&' boolean_expresion
|
	boolean_expresion '||' boolean_expresion
|
	'(' boolean_expression ')'
|
	relational_expression

relational_expression:
	operand '<' operand
|
	operand '<=' operand
|
	operand '>' operand
|
	operand '>=' operand
|
	operand '==' operand
|
	operand '!=' operand
;

operand:
	arith_expression
;

expression_term:
	variable
|
	constant
|
	procedure_call
;

variable:
	NAME
;

constant:
	INTEGER_NUMBER
|
	DOUBLE_NUMBER
;

procedure_call:
	NAME '(' optional_argument_list')'
;

optional_argument_list:
	/* empty */
|
	argument_list
;

argument_list:
	arith_expression
|
	argument_list ',' arith_expression
;

return_statement:
	RETURN ';'
|
	RETURN arith_expression ';'
;

print_statement:
	PRINT '(' print_argument ')';

print_argument:
	arith_expression
|
	string