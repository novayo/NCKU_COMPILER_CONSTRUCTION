/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int codeLines = 0;
	int commentLines = 0;
%}

%x COMMENT

/* Define regular expression label */

letter 				[a-zA-Z]
digit				[0-9]
Int_Number 			{digit}+
Float_Number		{digit}+\.{digit}+
String_Constants	\".*\"
Identifier 			[_a-zA-Z][_a-zA-Z0-9]*
CComment			"//".*
CppComment			"/*"

/* Rules section */
%%


a*b     {printf("%s\n", yytext);}
ca      {printf("%s\n", yytext);}
a*ca*   {printf("%s\n", yytext);}
\n						{codeLines++;}
[ \t]					{;}

%%
/*	C Code section */
int yywrap(void)
{
    return 1;
}

int main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r"); // open specific file
	yylex(); // do lexing
	printf("\nParse over, the line number is %d\n\n", codeLines);
	printf("comment: %d lines\n\n", commentLines);

	return 0;
}
