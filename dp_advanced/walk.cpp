#include<bits/stdc++.h>

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

using namespace std;

const int mod = 1e9+7;
const int sz = 51;

//matrix exponentition
struct Mat
{
    int m[sz][sz];
    Mat(){
        memset(m,0,sizeof(m));
    }

    void eye() {
        for(iny i=0;i<sz;i++){
            m[i][i]=1;
        }
    }
    
    Mat operator* (const Mat &a) const {
        Mat r;
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                for(int k=0;k<sz;k++){
                    r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j])%mod;
                }
            }
        }
        return r;
    }
};

int32_t main(){
 
 Mat a, res;
 int n,k;
 cin>>n>>k;

 for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
         cin>>a.m[i][j];
     }
 }

 res.eye();

 while(k){
     if(k & 1ll) res = res * a;
     a = a*a;
     k/=2;
 }

 int ans = 0;

 for(int i=0; i<n;i++){
     for(int j=0;j<n;j++){
         ans += res.m[i][j];
         ans%= mod;
     }
 }

 cout<<ans;

return 0;
}