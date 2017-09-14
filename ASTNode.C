#include "ASTNode.h"
#include <iostream>
#include <string>

ASTNode::ASTNode() {
	name = "";
	value = "";
	left = NULL;
	right = NULL;
	line_num = -1;
}

ASTNode::~ASTNode() {
	name = "";
	value = "";
	left = NULL;
	right = NULL;
	line_num = -1;
}

void
ASTNode::setName(string s){
	name = s;
	return;
}

void
ASTNode::setValue(string s) {
	value = s;
	return;
}

void
ASTNode::setLineNum(int i) {
	line_num = i;
	return;
}

void
ASTNode::setLeft(ASTNode *n) {
	left = n;
	return;
}

void
ASTNode::setRight(ASTNode *n) {
	right = n;
	return;
}

void
ASTNode::printTree() {
	cout << "Name: " << name << endl;
	if (value != "") {
		cout << "Value: " << value << endl;
	}
	
	if (left!=NULL) {
		cout << "Left Child Name: " << left->getName() << endl;
	} else {
		cout << "Left Child is NULL" << endl;
	}
	
	if (right!=NULL) {
		cout << "Right Child Name: " << right->getName() << endl;
	} else {
		cout << "Right Child is NULL" << endl;
	}
	
	cout << "Line number: " << line_num << endl << endl;
	
	if (left!=NULL) {
		left->printTree();
	}
	if (right!=NULL) {
		right->printTree();
	}
	
	return;
	
}

void
ASTNode::setMostRight(ASTNode *n) {
	if (right!=NULL) {
		right->setMostRight(n);
	}
	else { right = n; }
	return;
	
}