#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^') return 3;
    else if(c=='/'|| c=='*') return 2;
    else if(c=='+'|| c=='-') return 1;
    
    else{
        return -1;
    }
}

string infixToPostfix(string s){
  stack<int>st;
  string res;
  for(int i=0;i<s.length();i++){
    //if operand
     if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
        res+=s[i];
     }
     else if(s[i]=='('){
        st.push(s[i]);
     }
     else if(s[i]==')'){
        while(st.top()!='('){
            res+=st.top();
            st.pop();
        }
         st.pop();
     }
     else{ //operator is scanned
        while(!st.empty() && prec(st.top())>=prec(s[i])){
            res+=st.top();
            st.pop();
        }
          st.push(s[i]);
     }

  }
  //still stack has some element
  while(!st.empty()){
    res+=st.top();
    st.pop();
  }

  return res;
}
//abcd^e-fgh*+^*+i-
int main(){

    string star;
    cout<<"enter the string:"<<endl;
    cin>>star;
    cout<<"conversion is:";
    cout<<infixToPostfix(star)<<endl;
    return 0;
}