#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);

  int n1,n2,n3;cin>>n1>>n2>>n3;

  //creating two matrices
  int a[n1][n2];
  int b[n2][n3];
 
 //taking input of 1st matrice
  for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        cin>>a[i][j];
    }
  }


 //taking input of 2nd matrice
  for(int i=0;i<n2;i++){
    for(int j=0;j<n3;j++){
        cin>>b[i][j];
    }
  }
  
  //creating res matrice initialised with 0
  int res[n1][n3];
  for(int i=0;i<n1;i++){
    for(int j=0;j<n3;j++){
        res[i][j]=0;
    }
  }

  for(int i=0;i<n1;i++){
    for(int j=0;j<n3;j++){
        for(int k=0;k<n2;k++){
            res[i][j]+=a[i][k]*b[k][j];
        }
    }
  }

  for(int i=0;i<n1;i++){
    for(int j=0;j<n3;j++){
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }


return 0;
}