#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

vector<int> gr[N];
vector<int> order;
int dfs[N];
void dfs(int curr,int par)
{
    vis[cur]=1;
    for(auto x : gr[curr]){
        if(!vis[x]){
            dfs(x,curr);
        }
    }

    order.push_back(curr);
    return;
}

int main(){

    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,0);
    }

    reverse(order.begin(),order.end());

    for(auto x : order) cout<< x <<" ";

    return 0;
}