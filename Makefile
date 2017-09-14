SRC=main.C ASTNode.C codeGeneration.C SymbolTable.C typeCheck.C
OBJ=$(SRC:.C=.o)

BOY: lex.yy.c bisonBOY.tab.c bisonBOY.tab.h $(OBJ)
	g++ $(OBJ) bisonBOY.tab.c lex.yy.c -lfl -o BOY

bisonBOY.tab.c bisonBOY.tab.h: bisonBOY.y
	bison -d -v bisonBOY.y

lex.yy.c: flexBOY.l bisonBOY.tab.h
	flex flexBOY.l

.C.o: $<
	g++ -g -I. -c $<

clean:
	rm *.tab.*
	rm *.output
	rm lex.yy.c
	rm *.o
	rm BOY
