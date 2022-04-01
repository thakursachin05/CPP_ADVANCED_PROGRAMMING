#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 400;

int n, a[N], pref[N] , memo[N][N];

int sum(int l, int r){
    return pref[r] - (l==0 ? 0 : pref[l-1]);
}

int dp(int l,int r){
    if(l==r) return 0;
    int &ans = memo[l][r];
    if(ans!= 0) return ans; 
    ans = 1e18;
    for(int i=l;i<r;i++){
        ans = min(ans , dp(l,i) + dp(i+1,r));

    }
    ans += sum(l,r);
    return ans;
}

int32_t main(){
 
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
    pref[i] = a[i];
    if(i) pref[i] += pref[i-1];
}
cout<<dp(0,n-1);
return 0;
}