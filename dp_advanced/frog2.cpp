#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif

    int n,k;
    cin>>n>>k;
    int h[n];

    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int dp[n];


    dp[0] = 0;
    dp[1] = dp[0] + abs(h[1]-h[0]);

    for(int i=2;i<n;i++){
        dp[i] = INT_MAX;
        for(int kk=1;kk<=k;kk++)
            dp[i] = min(dp[i], dp[i-kk] + abs(h[i-kk]-h[i]));
    }

    cout<< dp[n-1] <<endl;

    return 0;
}
 