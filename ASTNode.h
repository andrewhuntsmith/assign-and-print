#ifndef ASTNODE
#define ASTNODE

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class ASTNode {
	/*
	This class represents one node of an Abstract Syntax Tree
	A node is an atomic part of a program; it cannot be divded further
		This might be an integer, a string, a variable name, an operation, etc.
	
	Each node contains the type of thing represented 	(int, str, PLUS, GETS, etc.)
		the value of the thing represented 				(6, "foo", "+", "=", etc.)
		a pointer to the left-child of the node
		and a pointer to the right-child of the node
		
	Note: if a node does not need two children, 
		then the next node will be pointed to by the right-child
	Each of the items stored in the node are private members,
		accessed by get and set methods
	
	*/
	private:
	string name;
	string value;
	int line_num;
	ASTNode *left;
	ASTNode *right;
	
	protected:
	
	public:
	// list of constructors
	ASTNode();
	
	// list of deconstructors
	~ASTNode();
	
	void setName(string);
	void setValue(string);
	void setLineNum(int);
	void setLeft(ASTNode *);
	void setRight(ASTNode *);
	void setMostRight(ASTNode *);
	
	string getName() { return name; };
	string getValue() { return value; };
	int getLineNum() { return line_num; };
	ASTNode *getLeft() { return left; };
	ASTNode *getRight() { return right; };
	
	void printTree(); // prints every node of the tree with the current node as the root
	
	
	
};

#endif