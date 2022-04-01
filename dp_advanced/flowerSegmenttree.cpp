#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

struct segmenttree {
    int n;
    vector<int> st;
    void init(int _n){
        this->n = _n;
        st.clear();
        st.resize(4*n,0);
    }

    void build(int start, int ending, int node){
        // leaf node base case 
        if(start==ending){
            return;
        }

        int mid = (start + ending) / 2;
        // left subtree is (start,mid)
        build(start,mid,2*node+1);
        //right subtree is (mid+1,ending)
        build(mid+1,ending,2*node+2);

        st[node] = st[node * 2 + 1] + st[node * 2 +2];
    }
    int query(int start, int ending,int l,int r, int node){
        //non overlapping case
        if(start > r || ending < l || l>r){
            return 0;
        }
        //complete overlap
        if(start >=l && ending <=r){
            return st[node];
        }

        // partial case
        int mid = (start+ending)/2;

        int q1 = query(start,mid,l,r,2*node+1);
        int q2 = query(mid+1,ending,l,r,2*node+2);

        return max(q1,q2);
    }

    void update(int start,int ending,int node,int index,int val)
    {   //base case
        if(start==ending){
            st[node] = val;
            return;
        }

        int mid = (start+ending)/2;
        //left subtree
        if(mid>=index){
            update(start,mid,2*node+1,index,val);
        }
        else{

            update(mid+1,ending,2*node+2,index,val);
        }
        st[node]= max(st[node*2+1],st[node*2+2]);
        return;
    }
    void build(vector<int> &v){
        build(0,v.size()-1,0);
    }
    int query(int l , int r){
        return query(0,n-1,l,r,0);
    }
    void update(int x,int y){
        update(0,n-1,0,x,y);
    }

} tree;

int32_t main(){
 int n;
 cin>>n;
 int h[n], a[n], dp[n];

 int idx[n];

 for(int i=0;i<n;i++){
     cin>>h[i];
     h[i]--;
     idx[h[i]]=i;
 }
 for(int i=0;i<n;i++){
     cin>>a[i];
 }

 tree.init(n);
 for(int hh=0;hh<n;hh++){
     int index = idx[hh];
     cout<<index<<" ";
     dp[index] = tree.query(0,index-1)+a[index];
     tree.update(index, dp[index]);
     cout<<dp[index]<<'\n';
 }

cout<<tree.query(0,n-1);

return 0;
}