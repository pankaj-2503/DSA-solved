#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){
            swap(a[i],a[j]);
        }
    }
}

for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
return 0;
}