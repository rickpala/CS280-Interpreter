# CS280-Project-4
Interpreter

Final Project for my course in Programming Language Concepts. We've built upon previous projects (Lexical Analyzer and Parser)
and added the final step in producing a usable programming language: the Interpreter. Written in C++.

In this language, there are two data types: Integer and String.
There are variables that follow the same naming conventions as C/C++ and Java.
Comments follow the same style as C/C++ and Java.
Conditional Expressions are integer values where Zero is False and Nonzero is True.
Integer arithmetic is supported.
String concatenation and string multiplication (repeatedly concatening the same string to itself) is supported.
String reversal and integer reversal (digit-by-digit) is a feature using the ! operator.
Error handling is implemented with appropriate syntax error and runtime error messages.

There are "Let" Statements for variable declaration:
  let age 19;
  let name "Ricky";
  
There are "Print" Statements for console output:
  print "Hello, World!\n";
  print "I am " + name;

There are "Loop" Statements for iterative execution:
  loop 1 BEGIN
    //code goes here
  END
  
There are "If" Statementes for conditional execution:
  if 0 BEGIN
    //code goes here
  END
  
  
To use this language, write code into a file and pass the file's name as a command-line-argument.
