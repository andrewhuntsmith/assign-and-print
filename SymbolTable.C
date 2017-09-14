#include "SymbolTable.h"
#include <iostream>
#include <string>

SymbolTable::SymbolTable() {
	size = 13;
	nodeList = new SymbolNode[size];
	
}

SymbolTable::~SymbolTable() {
	delete [] nodeList;
	
}

void
SymbolTable::insert(SymbolNode *node) {
	int index = 0;
	int key = 0;
	
	// key is equal to the sum of the ascii characters in the variable's name, mod size
	while (node->getVarName()[index]) {
		key += node->getVarName()[index];
		index += 1;
	}
	
	key = key % size;
	
	// if there is something in that index in the array, insert node later into that list
	//    otherwise, node is the first item in that index
	if (nodeList[key].getVarName() != "") {
		nodeList[key].insert(node);
	}
	else {
		nodeList[key] = *node;
	}
	return;
	
}


void
SymbolNode::insert(SymbolNode *node) {
	if (varName==node->getVarName()) {
		return;
	}
	
	if (next!=NULL) {
		next->insert(node);
	}
	else {
		next = node;
	}
	return;
}


SymbolNode *
SymbolTable::find(string name) {
	int index = 0;
	int key = 0;
	
	// key is equal to the sum of the ascii characters in the variable's name, mod size
	while (name[index]) {
		key += name[index];
		index += 1;
	}
	
	key = key % size;
	
	SymbolNode *temp = &nodeList[key];
	
	while ( temp != NULL ) {
		if (temp->getVarName() == name) {
			return temp;
		}
		else if (temp->getVarName() != name) {
			temp = temp->getNext();
		}
	}	
	
	return NULL;
	
}