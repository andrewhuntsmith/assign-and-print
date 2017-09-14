#include <stdio.h>
#include <iostream>
#include <string>
#include "ASTNode.h"
#include "SymbolTable.h"

using namespace std;

extern FILE *tempBOY;
extern SymbolTable *table;

int generateHeader() {
	/*
	This function generates the start of the temporary C file
	If the function is successful, it returns 1
	Otherwise, it returns -1
	*/
	
	fprintf(tempBOY, "#include <stdio.h>\n\n");
	return 1;
	
}

int generateCode(ASTNode *node) {
	/*
	This function generates the C file based on the AST passed in as an argument
	If the function is successful, it returns 1
	Otherwise, it returns -1
	*/
	
	if (node->getName() == "PROGRAM") {
		fprintf(tempBOY,"int main() {\n\n");
		
		SymbolNode *curNode;
		
		for (int i = 0; i < table->getSize(); i++) {
			if (table->getNodeList()[i].getVarName()!="") {
				curNode = &table->getNodeList()[i];
				while(curNode!=NULL) {
					fprintf(tempBOY,"int %s;\n",curNode->getVarName().c_str());
					curNode = curNode->getNext();
				}
			
			}
		}
		
		if (node->getRight() != NULL) {
			generateCode(node->getRight());
		}
		fprintf(tempBOY, "}\n");
	}
	else if (node->getName() == "STATEMENT") {
		generateCode(node->getLeft());
		fprintf(tempBOY,";\n");
		
		if (node->getRight() != NULL) {
			generateCode(node->getRight());
		}
	}
	else if (node->getName() == "GETS") {
		fprintf(tempBOY, "%s", node->getLeft()->getValue().c_str());
		fprintf(tempBOY, " = ");
		generateCode(node->getRight());
	}
	else if (node->getName() == "PRINT") {
		fprintf(tempBOY, "printf(\"%%d\\n\", ");
		generateCode(node->getLeft());
		fprintf(tempBOY, ")");
	}
	else if (node->getName() == "IDENT") {
		fprintf(tempBOY, "%s", node->getValue().c_str());
	}
	else if (node->getName() == "INT_LIT") {
		fprintf(tempBOY, "%s", node->getValue().c_str());
	}
	else {
		cout << "Unfamiliar node type!!!" << endl;
		return -1;
	}
	
	return 1;
	
}