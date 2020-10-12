# CS280-Project-4
Interpreter

Final Project for my course in Programming Language Concepts. We've built upon previous projects (Lexical Analyzer and Parser)
and added the final step in producing a usable programming language: the Interpreter. 

*Written in C++*

## Variables
Assign variables using a `let` statement. 
- `let` expects an identifier and an Integer or String expression.
- Valid identifiers are alphanumeric but can contain underscores, and must begin with a letter.

```C++
  let age 20;
  let name "Ricky";
```

## Integers
Integer expressions follow PEMDAS order of operations and can include other Integer variables within them.

```C++
  let year 2020;
  
  let radius 10;
  let areaOfCircle 3.14 * radius ^ 2;
```

## Strings
- String literals and String expressions are supported. 
- String concatenation uses the `+` operator
- String multiplication (repeated concatenation) uses the `*` operator.
```C++
  let firstName "Ricky";
  let lastName "Palaguachi";
  let fullName firstName + " " + lastName; // "Ricky Palaguachi"
  
  let eightZeros "0" * 8;     // "00000000"
  let alphabet "abcdef" * 2;  // "abcdefabcdef"
```

## Print statements
To print to `stdout`, use a `print` statement. 
- `print` expects a String variable or String expression.

```C++
  print "Hello, World!\n";  // "Hello, World!"
  print "I am " + name;     // "I am Ricky"
  print "0" * 16;           // "0000000000000000"
```

## Conditional Expressions
Conditional experssions can be used within the header of an `if` statement or a `loop` statement.
- A `false` boolean value is encoded by the Integer value of `0`
- A `true` boolean value is any nonzero Integer.

## If Statements
There are `if` statementes for conditional execution:
```C++
  if 0 BEGIN
    //code goes here
  END
```

## Loop Statements
There are "Loop" Statements for iterative execution:
```C++
  loop 1 BEGIN
    //code goes here
  END
```
- The body of the loop is enclosed by the `BEGIN` and `END` reserved words
- A `true` boolean expression is encoded by the Integer value `1`
  
## Error handling
Error checking is done in phases when analyzing the source file, and can occur when parsing or executing.

1. Syntax Error
  When the regular grammer of the language is violated.
2. Runtime error
  Occurs during runtime. A common example: using an undeclared variable.

Error messages display the line number where the error occured.

  
To use this language, write code into a file and pass the file's name as a command-line-argument.
