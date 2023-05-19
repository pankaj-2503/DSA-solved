#include<iostream>
#include<queue>
using namespace std;

class heap{
     public:
     int a[100];
     int size;

     heap(){
          a[0]=-1;
          size=0;
     }
     
     void insert(int val){
          size=size+1;
          int index=size;
          a[index]=val;
          while(index>1){
            int parent= index/2;
            if(a[parent]<a[index]){
                swap(a[parent],a[index]);
                index=parent;
            }
            else return;
          }
     } 


     void deletefromHeap(){
      if(size==0){
        cout<<"Nothing can't be deleted fromm Heap"<<endl;
        return;
      }
     a[1]=a[size];  // Step:1
     size--;        //Step:2

      int i=1;  //Step:3
      while(i<size){
          int leftIndex=2*i;
          int rightIndex=(2*i)+1;

          if(leftIndex<size && a[i]<a[leftIndex]){
             swap(a[i],a[leftIndex]);
             i=leftIndex;   //update index
          }
          else if(rightIndex<size && a[i]<a[rightIndex]){
             swap(a[i],a[rightIndex]);
             i=rightIndex;  //update index
          }
          else  return ;
      }
     }

     void heapify(int a[],int n,int i){
        int largest =i;
        int left=2*i;
        int right= (2*i) +1;
        
        if(left<=n && a[largest]<a[left]){
            largest=left;
        }
        if(right<=n && a[largest]<a[right]){
            largest=right;
        }

        if(largest!=i){
          swap(a[largest],a[i]);
          heapify(a,n,largest);
        }
     }

     void heapSort(int a[],int n){
         int size=n;
         while(size>1){
          swap(a[size],a[1]);
          size--;
          heapify(a,size,1);
         }
     }



      void print(){
            for(int i=1;i<=size;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
          }

};

int main(){ 
   /*
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();
 
    int a[6]={-1,54,53,55,52,50};
    int n=5;
   for(int i=n/2;i>0;i--){
    h.heapify(a,n,1);
   }
   cout<<"PRINTING HEAP"<<endl;
   for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
   }
   cout<<endl;


    h.heapSort(a,n);
    cout<<"Printing heapSort"<<endl;
    for(int i=1;i<=n;i++){
      cout<<a[i]<<" ";
    }
    cout<<endl;
    */

   //Max.  heap
   priority_queue<int>pq;
   pq.push(53);
   pq.push(45);
   pq.push(55);
   pq.push(50);
   cout<<pq.top()<<endl;
   pq.pop();
   cout<<pq.size()<<endl;
   if(pq.empty()){
    cout<<"pq is empty"<<endl;
   }
   else cout<<"pq is not empty"<<endl;

   // Min. heap
   priority_queue<int,vector<int>,greater<int>>minheap;
   minheap.push(54);
   minheap.push(53);
   minheap.push(50);
   minheap.push(58);
   cout<<minheap.top()<<endl;
   cout<<minheap.size()<<endl;

  
    return 0;
}