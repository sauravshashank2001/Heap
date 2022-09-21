#include<bits/stdc++.h>
using namespace std;



class Heap{
    public:
    int arr[100];
    int size=0;
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void deletFromHeap(){
        if(size==0){
            return;
        }
        //step 1 put last index value in 1st
        arr[1]=arr[size];
        // step-2 remove last node
        size--;
        //step3 propagate new root to its xact position
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            
            if(leftIndex<size && arr[leftIndex]>arr[i]){
                swap(arr[leftIndex],arr[i]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[rightIndex]>arr[i]){
                swap(arr[rightIndex],arr[i]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
        
        
    }
    
    
};


void heapify(int arr[], int size,int i){
    int largest=i;
    int left=2*i+1;
    int right= 2*i+2;
    if(left<size && arr[left]>arr[largest]){//left <=n due to 1 based indexing
        largest=left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest=right;
        
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}

void heapSort(int arr[],int n){
    
    int size = n-1;
    for(int i=n-1;i>=0;i--){
        //step 1 swap
        swap(arr[size],arr[0]);  //1 due to 1 based indexing
        //step 2
        size--;
        
        //step 3
        heapify(arr,size,0);
    }
    
    
}



int main(){
    // Heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // // h.deletFromHeap();
    // // h.print();
    
    //given array
    int arr[5]={54,53,55,52,50};
    int n=5;
    
    //heap creation
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    
    //calling heap sort wala function
    
   heapSort(arr,n);
    
    
    //printing after sorting
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

