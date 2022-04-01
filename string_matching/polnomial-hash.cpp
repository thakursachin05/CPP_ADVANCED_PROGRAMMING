#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int poly_hash(string s){
    int hash=0,p=31,mod=1e9+7;
    int p_power = 1;

    for(int i=0;i<s.size();i++){
        hash += (s[i] - 'a' + 1) * p_power;
        p_power *= p;
        
        hash %= mod;
        p_power %=mod;
        }


    return hash;
}

int32_t main() {
    string s = "abababa";

    cout<<poly_hash(s);

    return 0;
}

