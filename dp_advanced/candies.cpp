#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;


int32_t main(){
 int n,k,mod = 1e9+7;
 cin>>n>>k;

 int a[n+1];

 for(int i=1;i<=n;i++){
     cin>>a[i];
 }

 int dp[n+1][k+1];
 memset(dp,0,sizeof(dp));
 dp[0][0]=1;  

//  for(int i=1; i<=n; i++){
//      for(int j=0; j<=k; j++){
//          //dp[i][j]
//          for(int kk=0; kk<=min(a[i],j);kk++){
//              dp[i][j] += dp[i-1][j-kk];
//          }
//      }
//  }
//  for(int i=1; i<=n; i++){
//      for(int j=0; j<=k; j++){
//          //dp[i][j]
        
//           cout<<dp[i][j]<<" ";
         
//      } cout<<'\n';
//  }

for(int i = 1; i<=n; i++){
    for(int j=1; j<=k; j++){
        dp[i-1][j] += dp[i-1][j-1];
    }
    for(int j=0; j<=k;j++){
        dp[i][j] = dp[i-1][j];
        if(j-a[i]>0) dp[i][j] -= dp[i-1][j-a[i]-1];
    dp[i][j] = ((dp[i][j]%mod)+mod )%mod;
    }
}
    cout<< dp[n][k];
return 0;
}