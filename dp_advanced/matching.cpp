#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 22;
int a[N][N] , n, mod = 1e9+7;
int memo[N][(1<<N)];

// int dp(int m, set<int> W){
//     if(m==m) return 1;
//     int ans = 0;
//     for(int x=0;x<n;x++)
//     {
//         if(W.find(i) != W.end() && a[m][i] == 1){
//             W.erase(x);
//             ams += dp(m+1,W);
//             W.insert(x);
//         }
//     }
//     return ans;
// } less optimize

int dp(int m,int bitmask){
    if(m==n) return 1;
    int &ans= memo[m][bitmask];
    if(ans!=-1) return ans;
    ans = 0;

    for(int x = 0; x<n; x++){
        int set = (bitmask >> x) & 1;
        int compatible = a[m][x];
        if(set && compatible){
            ans += dp(m+1 , bitmask ^ (1 << x));
            ans %=mod;
        }

    }
    return ans;
}



int32_t main(){
 cin>>n;
 for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
         cin>>a[i][j];
     }
 }
//  set<int> W;
//  for(int i=0;i<n;i++){
//      W.insert(i);
//  }
//     cout<dp(0,W);
memset(memo,-1,sizeof(memo));
    cout<<dp(0,(1<<n)-1);

return 0;
}