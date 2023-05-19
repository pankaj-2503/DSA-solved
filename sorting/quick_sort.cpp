#include<iostream>
using namespace std;

void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

int partition(int a[],int l,int r){
    int pivot=a[r];  //taking last element as pivot
    int i=l-1;       //taking first index from 0
    for(int j=l;j<r;j++){
         if(a[j]<pivot){
            i++;
            swap(a,i,j);
         }
    }
    swap(a,i+1,r);  //taking pivot to its correct position
    return i+1;
}

void quicksort(int a[],int l,int r){
    if(l<r){
        int pi=partition(a,l,r);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,r);
    }
}
int main(){
 
  int n;
  cout<<"enter the size of array:";cin>>n;
  int a[n];
  cout<<"enter the element of array:";
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  quicksort(a,0,n-1);
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
 
return 0;
}