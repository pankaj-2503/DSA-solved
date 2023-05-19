#include<iostream>
using namespace std;


void merge(int a[],int l,int mid,int r){
    //declaring size of temp. array
    int n1=mid-l+1;
    int n2=r-mid;

    //temporary array
    int b[n1];
    int c[n2];

    //copying values of array a into temp. array according to their divided sizes
    for(int i=0;i<n1;i++){
        b[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        c[i]=a[mid+i+1];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(b[i]<=c[j]){  // array element may be equal
            a[k]=b[i];
            k++;
            i++;
        }
        else {
            a[k]=c[j];
            k++;j++;
        }
    }

    //if one array is empty then array other array element to main array
    while(i<n1){
        a[k]=b[i];
        k++;i++;
    }
    while(j<n2){
        a[k]=c[j];
        k++;j++;
    }

}


void mergesort(int a[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);


        merge(a,l,mid,r);

    }
}


int main(){
int n;cout<<"enter the size of array:";cin>>n;
int a[n];cout<<"enter the element of array:";
for(int i=0;i<n;i++) cin>>a[i];
mergesort(a,0,n-1);  //0 based indexing

cout<<"sorted array is: ";
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}

return 0;
}