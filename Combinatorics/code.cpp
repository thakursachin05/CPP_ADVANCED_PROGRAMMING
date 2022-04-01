#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> binomialCoefficient(int n , int k)
{
     vector< vector<int>> table(n+1 , vector<int> (k+1,0));
     for(int i=0;i<=n;i++){
         for(int j=0 ; j<= min(i,k); j++){

             //base case
             if(j==0 || j==i){
                 table[i][j]=1;
             }
             else {
                  table[i][j] = table[i-1][j-1] + table[i-1][j];
             }
         }
     }
     return table;
}

int main(){
    int n;
    cin>>n;
    int queries = 5;
    vector<vector<int> > table = binomialCoefficient(n,n);

    while(queries--){
        int k;
        cin>>k;
    if(k<=n){
        cout << table[n][k] <<endl;
        }
    }
}