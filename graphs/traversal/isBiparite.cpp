// https://leetcode.com/problems/is-graph-bipartite/
// Is graph Bipartite

class Solution {
public:
    bool bipartiteDfs(int src,vector<vector<int>> &adj,int color[]){
       if(color[src] == -1)
            color[src] = 1;

        for(auto it : adj[src]){
            if(color[it] == -1){
                color[it] = 1-color[src];
               if(!bipartiteDfs(it,adj,color)) return false;
            }
            else if(color[it] == color[src]) return false;
            }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
          int color[n];
            memset(color,-1,sizeof color);

     for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!bipartiteDfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};
