/*
*   Ricky Palaguachi
*   CS280
*   Program 4
*   val.h
*/

#ifndef VAL_H
#define VAL_H

#include <string>
using namespace std;

class Val {
    int i;
    string s;
    enum ValType { ISINT, ISSTR, ISERR } vt;
    
public:
    Val() : i(0), vt(ISERR) {}
    Val(int i) : i(i), vt(ISINT) {}
    Val(string s) : i(0), s(s), vt(ISSTR) {}
    Val(ValType vt, string errmsg) : i(0), s(errmsg), vt(ISERR) {}
    
    ValType getVt() const { return vt; }
    
    bool isErr() const { return vt == ISERR; }
    bool isInt() const { return vt == ISINT; }
    bool isStr() const { return vt == ISSTR; }
    
    int ValInt() const {
        if( isInt() ) return i;
        throw "This Val is not an Int";
    }

    string ValString() const {
        if( isStr() ) return s;
        throw "This Val is not a Str";
    }
    
    friend ostream& operator<<(ostream& out, const Val& v) {
        // IMPLEMENT
        if (v.isInt()){
            out << v.ValInt();
        }
        else if (v.isStr()){
            out << v.ValString();
        }
        else if (v.isErr()){
            out << v.GetErrMsg();
        }

        return out;
    }
    
    string GetErrMsg() const {
        if( isErr() ) return s;
        throw "This Val is not an Error";
    }
   
    Val operator+(const Val& op) const {
        if( isInt() && op.isInt() )
            return ValInt() + op.ValInt();
        if( isStr() && op.isStr() )
            return ValString() + op.ValString();
        return Val(ISERR, "Type mismatch on operands of +");
    }
    
    Val operator-(const Val& op) const {
        //IMPLEMENT
        if (isInt() && op.isInt())
            return ValInt() - op.ValInt();
        
        return Val(ISERR, "Type mismatch on operands of -");
    }
    
    Val multiplyString(string str, int n) const {
        string s = "";
        
        for (int i = 0; i < n; i++){
            s += str;
        }
        return Val(s);
    }

    Val operator*(const Val& op) const {
        //IMPLEMENT
        if( isInt() && op.isInt() ){
            return ValInt() * op.ValInt();
        }
        else if( isInt() && op.isStr()) {
            if (ValInt() < 0){
                return Val(ISERR, "Cannot multiply string by negative int");
            }
            return multiplyString(op.ValString(), ValInt());
        }
        else if (isStr() && op.isInt()){
            if (op.ValInt() < 0){
                return Val(ISERR, "Cannot multiply string by negative int");
            }
            return multiplyString(ValString(), op.ValInt());
        }
        
        return Val(ISERR, "Type mismatch on operands of *");
    }
    
    Val operator/(const Val& op) const {
        //IMPLEMENT
        if( isInt() && op.isInt() ){
            if (op.ValInt() != 0){
                return ValInt() / op.ValInt();
            }
            else {
                return Val(ISERR, "Divide by zero error");
            }
        }
            
        return Val(ISERR, "Type mismatch on operands of /");
    }
    
    Val operator!() const {
        //IMPLEMENT
        if (isInt()){
            int rev_num = 0; 
            int num = ValInt();
            bool negFlag = false;
            if (num < 0){
                negFlag = true;
                num = -num;
            }

            while (num > 0) { 
                rev_num = rev_num*10 + num%10; 
                num = num/10; 
            } 

            if (negFlag){
                rev_num = -rev_num;
            }
            return Val(rev_num);
        } 
        else if (isStr()){
            string rtnStr = "";
            string s = ValString();

            for (int i = s.size() - 1; i >= 0; i--){
                rtnStr += s[i];
            }
            
            return Val(rtnStr);
        }
        return Val(ISERR, "Invalid Bang Expr");
    }
};

#endif