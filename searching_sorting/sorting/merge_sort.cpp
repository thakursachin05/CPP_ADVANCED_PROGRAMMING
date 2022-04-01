#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &array,int s,int e){
     int i=s;
     int m = (s+e)/2;
     int j = m+1;

     vector<int> temp;

     while(i<=m and j<=e){
         if(array[i]<array[j]){
             temp.push_back(array[i]);
             i++;
         }
         else {
             temp.push_back(array[j]);
             j++;
         }
     }
     //copy rem element from first array
        while(i<=m){
            temp.push_back(array[i++]);
        }

     //or copy rem elements from second array
     while(j<=e){
         temp.push_back(array[j++]);
     }

     //copy back the element from temp to orignal array
     int k=0;
     for(int i=s;i<=e;i++){
         array[i]=temp[k++];
     }
     return;
}

//sorting method
void mergesort(vector<int> &array , int s,int e){
    //base case
    if(s>=e){
        return;
    }
    //rec case
    int mid = (s+e)/2;
    mergesort(array,s,mid);
    mergesort(array,mid+1,e);
    return merge(array,s,e);

}

int main(){
    vector<int> arr{3,2,15,56,2,1,0};
    mergesort(arr,0,arr.size()-1);
    for(auto it: arr){
        cout<<it<<" ";
    }
}