#ifndef SYMTAB
#define SYMTAB

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class SymbolNode {
	/*
	This class represents a node in the symbol table
	Each node contains the name of a variable, along with its type
	Also, each node contains a pointer to the next node, if needed
	*/
	
	private:
	string varName;
	string varType;
	SymbolNode *next;
	
	protected:
	
	public:
	// list of constructors
	SymbolNode() {varName = ""; varType = ""; next = NULL;} ;
	// list of deconstructors
	~SymbolNode() {varName = ""; varType = ""; next = NULL;} ;
	
	// list of methods
	void setVarName(string n) {varName = n;} ;
	void setVarType(string t) {varType = t;} ;
	void setNext(SymbolNode *n) {next = n;} ;
	
	void insert(SymbolNode*);
	
	string getVarName() {return varName;} ;
	string getVarType() {return varType;} ;
	SymbolNode *getNext() {return next;} ;
	
};


class SymbolTable {
	/*
	This class represents the symbol table
	The symbol table contains each of the variables used in the programming,
		as well as their types
	
	*/
	private:
	int size;
	SymbolNode *nodeList; 
	
	protected:
	
	public:
	// list of constructors
	SymbolTable();
	
	// list of deconstructors
	~SymbolTable();
	
	// list of methods
	SymbolNode *getNodeList() {return nodeList;};
	int getSize() {return size;};
	
	void insert(SymbolNode *);
	SymbolNode *find(string); // returns NULL if string not found
	
	
};

#endif