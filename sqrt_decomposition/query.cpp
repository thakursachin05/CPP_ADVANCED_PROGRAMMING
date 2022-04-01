#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int a[N] , cnt[N*10] , distinct;

struct query {
    int l,r,id,block,ans;
    bool operator<(query P) const {
        return make_pair(this->block, r) < make_pair(P.block , P.r);
    }
} q[N];

bool comp(query a, query b){
    return a.id < b.id;
}

void add(int val){
    cnt[val]++;
    if(cnt[val]==1) distinct++;
}

void remove(int val){
    cnt[val]--;
    if(cnt[val]==0) distinct--;
}

int main() {

    int n,m,queries;
    cin>>n;
    m = sqrt(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>queries;
    for(int i=0;i<queries;i++){
        cin>>q[i].l>>q[i].r;
        q[i].l--; q[i].r--;
        q[i].id = i, q[i].block = q[i].l/m;

    }    
    sort(q,q+queries);

    int x=0,y=0;
    for(int i=0;i<queries;i++){
        //adding y
        while(y<=q[i].r) {
            add(a[y]);
            y++;
        }
        //remove y
        while(y > q[i].r+1){
            y--;
            remove(a[y]);
        } 

        //removing x
        while(x <= q[i].l){
            remove(a[x]);
            x++;
        } 
        //adding x
        while(x > q[i].l){
            x--;
            add(a[x]);
        }
        q[i].ans = distinct;
    }
    sort(q,q+queries,comp);

    for(int i=0;i<queries;i++){
        cout<< q[i].ans << '\n';
    }

    return 0;

}