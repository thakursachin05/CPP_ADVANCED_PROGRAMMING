#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &array,int s,int e){
     int i=s;
     int mid = (s+e)/2;
     int j = mid+1;

     vector<int> temp;
     int count =0;

     while(i<=mid and j<=e){
         if(array[i]<array[j]){
             temp.push_back(array[i]);
             i++;
         }
         else {
             count+= mid-i+1;
             temp.push_back(array[j]);
             j++;
         }
     }
     //copy rem element from first array
        while(i<=mid){
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
     return count;
}

int inversion_count(vector<int> &arr,int s, int e){
    //base case;
    if(s>=e){
        return 0;
    }
    //rec case
    int mid = (s+e)/2;
    int C1= inversion_count(arr,s,mid);
    int C2= inversion_count(arr,mid+1,e);
    int CI= merge(arr,s,e);
    return C1+C2+CI;

}

int main(){
    vector<int> arr{0,5,2,3,1};
   cout<<inversion_count(arr,0,arr.size()-1)<<endl;
  
}