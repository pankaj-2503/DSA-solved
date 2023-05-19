#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
           return true;
    }
    return false;
}

string preToInfix(string s){
    stack<string>st;
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        if(isOperator(s[i])){
            string op1=st.top(); st.pop();
            string op2=st.top();st.pop();
            //concatenate
            string temp= "("+op1+s[i]+op2+")";
            st.push(temp);
        }
        else{
            st.push(string(1,s[i])); //converting one char to string
        }
    }
    return st.top();
}

int main(){
    string star= "*-A/BC-/AKL";
    cout<<"Your conversion is:";
    cout<<preToInfix(star)<<endl;
    return 0;
}