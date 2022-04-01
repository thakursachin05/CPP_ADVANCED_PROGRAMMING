#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;
int n, mod = 1e9+7;
string str;
int memo[3005][3005];
int dp(int i,int s){
    if(i==n) return 1;
    int &ans = memo[i][s];
    if(ans!=-1) return ans;
    ans = 0;
    if(str[i-1] == '<'){
        int g = (n-i-s);
        for(int j = 1; j<=g; j++){
            ans += dp(i+1,s+j-1);
        }
    }
    else {
        for(int j = 1; j<=s; j++){
            ans += dp(i+1,j-1);
            ans %= mod;
        }
    }
    return ans;
}

int32_t main(){
 
cin>>n>>str;
// int ans = 0;
// memset(memo,-1,sizeof(memo));
// for(int i=1;i<=n;i++){
//     ans += dp(1,i-1);
// }
int dp[n+1][n+1], ans=0;
memset(dp,0,sizeof(dp));
dp[n][0]=1;

for(int i= n-1; i>0; i--){
    for(int j=1;j<=n;j++){
        dp[i+1][j] += dp[i+1][j-1];
    }

    for(int s=0;s<=n;s++){
        int g = (n-i-s);
        if(g<0) continue; 
        if(str[i-1] == '<'){
            dp[i][s] = dp[i+1][s+g-1] - (s==0 ? 0 : dp[i+1][s-1]);
        }
        else{
            dp[i][s] = dp[i+1][s-1];
        }
            dp[i][s] %= mod;
    }
}
for(int i=1;i<=n;i++){
    ans += dp[1][i-1];
    ans %= mod;
}
ans +=  mod;
ans%=mod;
cout<<ans;
return 0;
}