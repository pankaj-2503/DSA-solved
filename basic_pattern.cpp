#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;cin>>n;
   

   cout<<"SQUARE :"<<endl;

   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<"#"<<" ";
      }
      cout<<endl;
   }

  cout<<"INCREASING TRIANGLE : "<<endl;

   for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
         cout<<"#"<<" ";
      }
      cout<<endl;
   }
   
   cout<<"DECREASING TRIANGLE:"<<endl;


   for(int i=1;i<=n;i++){
      for(int j=1;j<=n-i+1;j++){
         cout<<"#"<<" ";
      }
      cout<<endl;
   }

   cout<<"Pattern 4:"<<endl;

   for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
         cout<<j<<" ";
      }
      cout<<endl;
   }

 /*  cout<<"RIGHT SIDED TRIANGLE:"<<endl;
   for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         cout<<"#"<<" ";
      }
      for(int k=2;k<=i;k++){
         cout<<" ";
      }
      cout<<endl;
   }
	*/	

  cout<<"Pattern 5:"<<endl;
  for(int i=1;i<=2*n;i++){
      int jcnt= (i>n) ? (2*n)-i:i;
   for(int j=1;j<=jcnt;j++){ 
      cout<<"*"<<" ";
   }
   cout<<endl;
  }

cout<<"Pattern :6"<<endl;
 for(int i=1;i<=2*n;i++){
      int jcnt= (i>n) ? (2*n)-i:i;
      int noSpaces=n-jcnt;
   for(int k=1;k<=noSpaces;k++){ 
      cout<<" ";
   }
   for(int j=1;j<=jcnt;j++){
      cout<<"*"<<" ";
   }
   cout<<endl;
  }

  cout<<"Pattern :7"<<endl;

  for(int i=1;i<=n;i++){

   for(int k=1;k<=n-i;k++){
      cout<<"  ";
   }
    for(int j=i;j>=1;j--){
      cout<<j<<" ";
    }
    for(int j=2;j<=i;j++){
      cout<<j<<" ";
    }
    cout<<endl;
  }
	return 0;
}