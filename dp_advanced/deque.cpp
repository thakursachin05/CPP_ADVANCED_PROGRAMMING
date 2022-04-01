#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 3001;

int n,a[N],sum=0;
int memo[N][N][2];

int dp(int i,int j,int turn){
    if(i>j) return 0;
    // if(i==j) {
    //     if(turn==0) return a[i];
    //     else return 0;
    // }
    int &ans = memo[i][j][turn];
    if(ans!=1e18) return ans;
    if(turn==0){
        ans = max(a[i]+dp(i+1,j,1-turn), a[j]+dp(i,j-1,1-turn));
    }
    else {
        ans = min(dp(i+1,j,1-turn) , dp(i,j-1,1-turn));

    }
    
    return ans;
}

int32_t main(){
 
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
    sum += a[i];
}
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        memo[i][j][0] = memo[i][j][1] = 1e18;
    }
}

    int max_x = dp(0,n-1,0);
    int min_y = sum - max_x;

    cout<<max_x - min_y;

return 0;
}