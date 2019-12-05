/*
*   Ricky Palaguachi
*   CS280
*   Program 4
*   main.h
*/

#include "lex.h"
#include "parse.h"
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

map<string, Val> myMap;

void runtime_err(int linenum, string errmsg){
    string message = "RUNTIME ERROR at " + to_string(linenum) + ": " + errmsg;
    throw message;
}

int main(int argc, char *argv[]) {
	ifstream file;
	istream *in;
	int linenum = 0;

	if( argc == 1 ) {
		in = &cin;
	}

	else if( argc == 2 ) {
		file.open(argv[1]);
		if( file.is_open() == false ) {
			cout << "COULD NOT OPEN " << argv[1] << endl;
			return 1;
		}
		in = &file;
	}
	else {
		cout << "TOO MANY FILENAMES" << endl;
		return 1;
	}

	ParseTree *prog = Prog(*in, linenum);

	if( prog == 0 )
		return 0;


	//check for undeclared identifiers
	map<string,bool> declaredId;
	if (prog->CheckLetBeforeUse(declaredId) > 0){
		return 0;
	}

	//execute interpeter
    try {
        prog->Eval();
    }
    catch(string& e) {
        cout << e << endl;
    }
	return 0;
}
