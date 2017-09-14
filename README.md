# assign-and-print
A compiler for a language that just has assignment and printing

To use this language, you need g++, flex, and bison.
Type "make" in your directory to compile the files.

Then type 
  ./B++ 'executable name' 'filename.BOY' 
 to compile your .BOY files
 
 
 This language currently only supports assignment and print statements, and the only type is integer. A file might look like the following:
 
 a = 7;
 b = 8;
 c = a;
 print a;
 print b;
 print c;
 
