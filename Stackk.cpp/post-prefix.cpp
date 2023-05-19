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
    // 3 step process
    //1 traverse from front , if operand then push it else if operator then pop two element from stack and concatenate them and push to stack
    int n=s.length();
    for(int i=0;i<n;i++){
        if(isOperator(s[i])){
            string op1=st.top(); st.pop();
            string op2=st.top();st.pop();
            //concatenate
            string temp= s[i]+op2+op1;
            st.push(temp);
        }
        else{
            st.push(string(1,s[i])); //converting one char to string
        }
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
   
}

int main(){
    string star="ABC/-AK/L-*" ;
    cout<<"Your conversion is:";
    cout<<preToInfix(star)<<endl;
    return 0;
}