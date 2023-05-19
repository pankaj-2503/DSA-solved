#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>
#define ll long long
#define endl "\n"
using namespace std;



int main(){
   srand(time(0));
   string pass;

   string data= "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "0123456789"
                "~`!@#$%^&*()_+=-{}[]\?/:;,<>" ;

    for(int i=0;i<12;i++){
        pass=pass+ data[rand()%93];
    }
    cout<<"YOUR PASSWORD IS : "<<pass<<endl;
  
return 0;
}