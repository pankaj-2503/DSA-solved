#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){


int n;
cout<<"enter the size of array:";
cin>>n;
int a[n];
cout<<"enter the array element:";
for(int i=0;i<n;i++){
    cin>>a[i];
}

for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    }
}
cout<<"sorted array is:";
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}


return 0;
}