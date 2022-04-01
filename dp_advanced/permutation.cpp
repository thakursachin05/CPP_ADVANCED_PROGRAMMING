#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;
int n, mod = 1e9+7;
string str;
int memo[25][25];
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
int ans = 0;
memset(memo,-1,sizeof(memo));
for(int i=1;i<=n;i++){
    ans += dp(1,i-1);
}
cout<<ans%mod;
return 0;
}