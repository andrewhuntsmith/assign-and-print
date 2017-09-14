%{
#include <iostream>
#include "ASTNode.h"
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "bisonBOY.tab.h"  // to get the token types that we return
int line_num = 1;
void yyerror(const char *s) {
	cerr << "Error on line: " << line_num << ", before token: " << yytext << " -->>  Message: " << s << endl;
}
%}

%%

[ \t]           ;
[0-9]+          { yylval.sval = strdup(yytext); return INT_LIT; }
print	{ yylval.sval = strdup(yytext); return PRINT; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval.sval = strdup(yytext); return IDENT; }
\n		{ ++line_num; }
\;		{ yylval.sval = strdup(yytext); return SEMICOLON; }
=		{ yylval.sval = strdup(yytext); return GETS; }
.                ;

%%

