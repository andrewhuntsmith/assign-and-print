#include <stdio.h>
#include <string>
#include <iostream>
#include "ASTNode.h"
#include "SymbolTable.h"

using namespace std;

extern SymbolTable *table;

int makeSymbolTable(ASTNode *node) {
	/*
	This function's sole purpose is to add elements to the symbol table, as well as their types
	In a more complex language, this function might also:
		check for type errors
		do type inference
		check for variables used before being defined
	If the function is successful, it returns 1
	Otherwise, it returns -1
	*/
	
	if (node->getName() == "IDENT") {		
		// if we search the variable name in the table, and it is not found, insert the variable
		if (table->find(node->getValue())==NULL) {
			SymbolNode *newNode = new SymbolNode();
			newNode->setVarName(node->getValue());
			newNode->setVarType("INT");
			table->insert(newNode);
		}
	}
	
	if (node->getLeft()!=NULL) {
		makeSymbolTable(node->getLeft());
	}
	if (node->getRight()!=NULL) {
		makeSymbolTable(node->getRight());
	}

	return 1;
	
}