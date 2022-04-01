#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 1e5+1 , mod = 1e9 + 7;
vector<int> gr[N];
int memo[N][2];

int dp(int cur, int paint,int par){
    int &ans = memo[cur][paint];
    if(ans!=-1) return ans;
    ans = 1;

    for(auto child : gr[cur]){
        if(child != par){
            if(paint){
                
             ans*= (dp(child,0,cur) + dp(child,1,cur));
            }
            else {
                ans *= dp(child , 1,cur);
            }
             ans %= mod;
        }
    }
    return ans;
}

int32_t main(){
 
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);

    }
    memset(memo,-1,sizeof(memo));

    cout<<(dp(1,1,0)+ dp(1,0,0))%mod;

return 0;
} 