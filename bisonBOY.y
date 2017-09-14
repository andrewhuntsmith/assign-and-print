%{
#include <cstdio>
#include <iostream>
#include "ASTNode.h"
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_num;
extern ASTNode *treeRoot;
 
void yyerror(const char *s);
%}

%union {
int ival;
char *sval;
ASTNode *node;
}

%token SEMICOLON GETS PRINT

%token <sval> INT_LIT
%token <sval> IDENT

%type <node> statements statement expression term

%%


file:	statements 
        { treeRoot->setName("PROGRAM");
			treeRoot->setLineNum(0);
			treeRoot->setRight($1); } ;
		

statements: statements statement
			{ ASTNode *cur = new ASTNode(); 
				cur->setName("STATEMENT");
				cur->setLineNum(line_num);
				cur->setLeft($2);
				if ($1!=NULL) {
					$1->setMostRight(cur);
					$$ = $1;
				} else { $$ = cur; }
			}
            | { $$ = NULL; }
			;

statement: expression SEMICOLON 
			{ $$ = $1; };
	

expression: 
	term GETS term 
		{ ASTNode *cur = new ASTNode();
			cur->setName("GETS");
			cur->setLineNum(line_num); 
			cur->setLeft($1);
			cur->setRight($3); 
			$$ = cur; }
	| PRINT term
		{ ASTNode *cur = new ASTNode();
			cur->setName("PRINT");
			cur->setLineNum(line_num);
			cur->setLeft($2);
			$$ = cur; }
	| term
        ;

		
term:
	IDENT { ASTNode *cur = new ASTNode();
			cur->setName("IDENT");
			cur->setValue($1);
			cur->setLineNum(line_num);
			$$ = cur;
			}
	| INT_LIT { ASTNode *cur = new ASTNode();
			cur->setName("INT_LIT");
			cur->setValue($1);
			cur->setLineNum(line_num);
			$$ = cur;
			} 
			;
		
%%


