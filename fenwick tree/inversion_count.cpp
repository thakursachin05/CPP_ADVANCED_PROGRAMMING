#include<bits/stdc++.h>
using namespace std;

struct fenwick{
    vector<int> fn;
    int n;
    void init(int n){
        this->n = n+1;
        fn.resize(this->n);
    }

    void add(int x, int y){
        x++;
        while(x<n){
            fn[x]+= y;
            x += (x & (-x)); //last set bit of x
        }
    }

    // void add(int x, int y){
    //     for(x++;x<n;x+= (x & (-x))) fn[x]+=y;
    // }

    int sum(int x){
        x++;
        int ans = 0;
        while(x){
           ans += fn[x];
           x -= (x & (-x));

        }
        return ans;
    }
    int sum(int l , int r){
        return sum(r)-sum(l-1); 
    }
};

int main(){
    int n;
    cin>>n;
    pair<int,int> a[n];

    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    
    sort(a , a+n);
    fenwick tree;
    tree.init(n);

    int inversion_count = 0;

    for(int i=0;i<n;i++){
        int element = a[i].first;
        int index = a[i].second;

        inversion_count += tree.sum(index + 1,n-1);
        tree.add(index,1);
    }
    cout<<inversion_count;


    return 0;
}