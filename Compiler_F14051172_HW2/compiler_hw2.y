/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char *);
void create_symbol();
void insert_symbol(char *, char *, char *, char *);
void dump_symbol();
void yyerror(char *);

void getFuncItem(char *, char *);
void getVarItem(char *, char *);
int table_index[30] = {0};
int table_scope = 0;
struct symbol_table{
	int index;
	char name[30];
	char entry_type[30];
	char data_type[30];
	int scope;
	char formal_parameters[100];
} symbol_table[30][30];
struct symbol_table original_symbol_table;
%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
} 

/* Token without return */

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STR_CONST

/* Nonterminal with return, which need to sepcify type */
%type <string> IDENTIFIER function_definition type_specifier declarator init_declarator init_declarator_list id

/* Yacc will start at this nonterminal */
%token IDENTIFIER
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
%token INT FLOAT VOID BOOL STRING
%token IF ELSE WHILE FOR RETURN
%token PRINT TRUE FALSE

/* Priority */
%nonassoc IFX
%nonassoc ELSE

%start translation_unit
%%

constant
	: I_CONST
	| F_CONST
;

primary_expression
	: IDENTIFIER { /*不用理他，不是宣告部分*/ }
	| constant
	| STR_CONST
	| '(' expression ')'
	| TRUE
	| FALSE
;

postfix_expression
	: primary_expression
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '!'
;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
;

relational_expression
	: additive_expression
	| relational_expression '<' additive_expression
	| relational_expression '>' additive_expression
	| relational_expression LE_OP additive_expression
	| relational_expression GE_OP additive_expression
;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
;

expression
	: assignment_expression
	| expression ',' assignment_expression
;

declaration
	: type_specifier ';' 
	| type_specifier init_declarator_list ';' { getVarItem($1, $2); }
;

init_declarator_list
	: init_declarator { $$ = $1; }
	| init_declarator_list ',' init_declarator
;

init_declarator
	: declarator { $$ = $1; }
	| declarator '=' initializer 
;

type_specifier
	: VOID   {$$ = "void";}
	| INT    {$$ = "int";}
	| FLOAT  {$$ = "float";}
	| BOOL   {$$ = "bool";}
	| STRING {$$ = "string";}
;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
;

declarator
	: IDENTIFIER 				{ $$ = $1; }
	| '(' declarator ')' {}
;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration 
;

parameter_declaration
	: type_specifier declarator
	| type_specifier abstract_declarator
	| type_specifier
;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
;

abstract_declarator
	: '(' abstract_declarator ')'
	| '(' ')'
	| '(' parameter_list ')'
	| abstract_declarator '(' ')'
	| abstract_declarator '(' parameter_list ')'
;

initializer
	: assignment_expression
	| string
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
;

string
	: '"' STR_CONST '"'
;

initializer_list
	: initializer
	| designation initializer
	| initializer_list ',' initializer
	| initializer_list ',' designation initializer
;

designation
	: designator_list '='
;

designator_list
	: designator
	| designator_list designator
;

designator
	: '.' IDENTIFIER
;

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
;

compound_statement
	: '{' '}'
	| '{' block_item_list '}' 
;

block_item_list
	: block_item
	| block_item_list block_item
;

block_item
	: declaration 
	| statement
	| print_func
;

expression_statement
	: ';'
	| expression ';'
;

selection_statement
	: IF '(' expression ')' statement %prec IFX
	| IF '(' expression ')' statement ELSE statement
;

iteration_statement
	: WHILE '(' expression ')' statement
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	| FOR '(' declaration expression_statement ')' statement
	| FOR '(' declaration expression_statement expression ')' statement
;

jump_statement
	: RETURN ';'
	| RETURN expression ';'
;

translation_unit
	: external_declaration 
	| translation_unit external_declaration  
;

external_declaration
	: function_definition
	| declaration 
	| print_func
;

print_func
	: PRINT '(' IDENTIFIER ')' ';'
	| PRINT '(' string ')' ';'
;

function_definition
	: type_specifier id parameter_list ')' declaration_list compound_statement   {printf("%d: }\n", yylineno+1); getFuncItem($1, $2); dump_symbol();}
	| type_specifier id parameter_list ')' compound_statement 					 {printf("%d: }\n", yylineno+1); getFuncItem($1, $2); dump_symbol();}
	| type_specifier id identifier_list ')' declaration_list compound_statement  {printf("%d: }\n", yylineno+1); getFuncItem($1, $2); dump_symbol();}
	| type_specifier id identifier_list ')' compound_statement 					 {printf("%d: }\n", yylineno+1); getFuncItem($1, $2); dump_symbol();}
	| type_specifier id ')' declaration_list compound_statement 				 {printf("%d: }\n", yylineno+1); table_scope--;getFuncItem($1, $2); table_scope++;dump_symbol();}
	| type_specifier id ')' compound_statement 									 {printf("%d: }\n", yylineno+1); table_scope--;getFuncItem($1, $2); table_scope++;dump_symbol();}
;

id
	: IDENTIFIER '(' {$$ = $1; table_scope++;}
;

declaration_list
	: declaration
	| declaration_list declaration
;


%%

/* C code section */
int main(int argc, char** argv)
{
	create_symbol();
    yylineno = 0;
    yyparse();
	while (table_scope >= 0) {
		dump_symbol();
		table_scope--;
	}
	printf("\nTotal lines: %d \n", yylineno);

    return 0;
}

void getFuncItem(char * str_type, char * str){
	char p[30][30] = {'\0'};
	int p_count = 0;
	char strbuf[1000] = {'\0'};
	for (int i=0; i<strlen(str); i++) strbuf[i] = str[i];

    char * func = strtok(strbuf, "(");

	char strbuf1[1000] = {'\0'};
	for (int i=0; i<strlen(str); i++) strbuf1[i] = str[i];
	char * pars = strtok(strbuf1, ")");


	char * subpar = NULL;
	subpar = strtok(pars, "(");
	subpar = strtok(NULL, "(");
	if (subpar == NULL){
		insert_symbol(func, "function", str_type, "");
		return;
	}
	
	char strbuf2[1000] = {'\0'};
	for (int i=0; i<strlen(subpar); i++) strbuf2[i] = subpar[i];
	char * subpar2 = strtok(strbuf2, " ");
	char func_pars[100] = {'\0'};

	do {
		if (subpar2[strlen(subpar2)-1] == ',') subpar2[strlen(subpar2)-1] = '\0';
		for (int i=0; i<strlen(subpar2); i++) p[p_count][i] = subpar2[i];
		if (++p_count % 2 == 0){
			insert_symbol(p[p_count-1], "parameter", p[p_count-2], "");
			int tmp = strlen(func_pars);
			for (int i=tmp; i<strlen(p[p_count-2]) + tmp; i++) func_pars[i] = p[p_count-2][i - tmp];
			tmp = strlen(func_pars);
			func_pars[tmp] = ',';
			func_pars[tmp+1] = ' ';
		}
        subpar2 = strtok(NULL, " ");
    } while (subpar2);
	int tmp = strlen(func_pars);
	func_pars[tmp-1] = '\0';
	func_pars[tmp-2] = '\0';

	table_scope--;
	insert_symbol(func, "function", str_type, func_pars);
	table_scope++;
}

void getVarItem(char * stype, char * sname){
	int tmp = strlen(sname);
	if (sname[tmp-1] == '=') {
		sname[tmp-1] = '\0';
		sname[tmp-2] = '\0';
	}

	char strbuf[1000] = {'\0'};
	for (int i=0; i<strlen(sname); i++) strbuf[i] = sname[i];

    char * var = strtok(strbuf, " =");
	if (var[strlen(var)-1] == ';') var[strlen(var)-1] = '\0';
 
	insert_symbol(var, "variable", stype, "");
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	exit(0);
}

void create_symbol() {
	for (int i=0; i<30; i++) 
		for (int j=0; j<30; j++) 
			symbol_table[i][j] = original_symbol_table;
}

void insert_symbol(char * sname, char * sentry_type, char * sdata_type, char * sformal_parameter) {
	symbol_table[table_scope][table_index[table_scope]].index = table_index[table_scope];
	for (int i=0; i<strlen(sname); i++) symbol_table[table_scope][table_index[table_scope]].name[i] = sname[i];
	for (int i=0; i<strlen(sentry_type); i++) symbol_table[table_scope][table_index[table_scope]].entry_type[i] = sentry_type[i];
	for (int i=0; i<strlen(sdata_type); i++) symbol_table[table_scope][table_index[table_scope]].data_type[i] = sdata_type[i];
	symbol_table[table_scope][table_index[table_scope]].scope = table_scope;
	for (int i=0; i<strlen(sformal_parameter); i++) symbol_table[table_scope][table_index[table_scope]].formal_parameters[i] = sformal_parameter[i];
	table_index[table_scope]++;
}
int lookup_symbol(char *sname) {
	int isExist = 0;
	for (int i=0; i<table_index[table_scope]; i++) {
		if (strcmp(symbol_table[table_scope][i].name, sname) == 0){
			isExist = 1;
			break;
		}
	}
	if (isExist == 0) return 0;
	else return 1;
}

void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	for (int i=0; i<table_index[table_scope]; i++){
		printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
		   symbol_table[table_scope][i].index, symbol_table[table_scope][i].name, symbol_table[table_scope][i].entry_type,
		   symbol_table[table_scope][i].data_type, symbol_table[table_scope][i].scope, symbol_table[table_scope][i].formal_parameters);
		symbol_table[table_scope][i] = original_symbol_table;
	}
	
	table_index[table_scope] = 0;
	table_scope--;
	printf("\n\n");
}

