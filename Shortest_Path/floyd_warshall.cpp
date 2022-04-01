#include<iostream>
#include<vector>

using namespace std;
#define INT_MAX 10000
vector<vector<int>> floyd_warshall(vector<vector<int> > graph){

    vector<vector<int> > dist(graph);
    int V = graph.size();
    //Phases, in kth phase we include vertices (1,2,...k) as intermediate vertices 
    for(int k=0;k<V;k++){
        //Iterate over entire 2D matrix
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){

                //if vertex k is included , and can we minimise the dist ?
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;

}

int main(){


    vector<vector<int> > graph = {
                                    {0,INT_MAX,-2,INT_MAX},
                                    {4, 0,3,INT_MAX},
                                    {INT_MAX,INT_MAX,0,2},
                                    {INT_MAX,-1,INT_MAX,0}
                                };

    auto result = floyd_warshall(graph);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result.size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}