#include <iostream>
#include <string>
#include "ASTNode.h"
#include "SymbolTable.h"

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_num;

FILE *tempBOY;
ASTNode *treeRoot;
SymbolTable *table;


int generateHeader();
int generateCode(ASTNode *);
int makeSymbolTable(ASTNode *);

int main(int argc, char** argv) {

	treeRoot = new ASTNode();
	
	FILE *myfile = fopen( argv[1] , "r");
	if (!myfile) {
		cerr << "I can't open file!" << endl;
		return -1;
	}
	yyin = myfile;

	do {
		yyparse();
	} while (!feof(yyin));
	
	//treeRoot->printTree();
	
	table = new SymbolTable();
	makeSymbolTable(treeRoot);
	
	tempBOY = fopen( "temp.BOY.c", "w+" );
	generateHeader();
	generateCode(treeRoot);
	fclose(tempBOY);
	
	return 1;
	
}