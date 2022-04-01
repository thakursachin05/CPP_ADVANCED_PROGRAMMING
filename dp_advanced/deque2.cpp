#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;
const int N = 3001;
int n,a[N],memo[N][N];

int dp(int i,int j){
    if(i==j) return a[i];
    int &ans = memo[i][j];
    if(ans!=-1e18) return ans;
    ans = max(a[i] - dp(i+1,j), a[j] - dp(i,j-1));
    return ans;
}

int32_t main(){
 
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        memo[i][j] = -1e18;
    }
}
cout<<dp(0,n-1);
return 0;
}