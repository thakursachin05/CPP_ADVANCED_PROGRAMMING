#include<iostream>
using namespace std;

bool divideAmong(int *arr,int n,int k,int min_coins){

    int partions = 0;
    int current_friend = 0;

    for(int i=0;i<n; i++){
        if(current_friend + arr[i]>= min_coins){
            partions++;
            current_friend = 0;
        }
        else {
            current_friend += arr[i];
        }
    }
    return partions >=k;
}


int k_partitions(int *arr,int n,int k){
    int s = 0;
    int e = 0;
    int ans=0;
    for(int i=0;i<n;i++){
        e+=arr[i];
    }
    while(s<=e){
        int mid = (s+e)/2;
        int canDivide = divideAmong(arr,n,k,mid);
        if(canDivide){
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }

    }
    return ans;
}

int main(){

    int k = 3;
    int arr[]={10,22,40,50};
    cout<<k_partitions(arr,4,k)<<endl;

}