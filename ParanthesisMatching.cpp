//((a+b)+c(d+e))---->true;
//((a+b)* c))------>false;

#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string &str){
    stack<char> s;
    for(char c: str){
        if(c=='('){
            s.push(c);

        }
        else if(c==')'){
            if(s.empty()){
                return false;
            }
            s.pop();            
        }
    }
    return s.empty();
}


int main(){

    string str="((a+b)* ()c)";
    if(isBalanced(str)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NOT"<<endl;
    }

    return 0;
}