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
    vector<int> v = {1,2,3,4,5,6};
    fenwick tree;
    tree.init(v.size());

    for(int i=0;i<v.size();i++){
        tree.add(i,v[i]);
    }
    cout<<tree.sum(3,5)<<endl;
    tree.add(4,-3);
    cout<<tree.sum(3,5)<<endl;
    return 0;
}