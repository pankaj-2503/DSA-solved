#include<iostream>
using namespace std;

int main(){

int n;
cout<<"enter the size of array:";
cin>>n;

int a[n];
cout<<"enter the element of array:";
for(int i=0;i<n;i++){
    cin>>a[i];
}

for(int i=1;i<n;i++){
    int j=i-1;
    int curr=a[i];
    while(a[j]>curr && j>=0){
        a[j+1]=a[j];
        j--;
    }
   a[j+1]=curr;
}

for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}

return 0;
}