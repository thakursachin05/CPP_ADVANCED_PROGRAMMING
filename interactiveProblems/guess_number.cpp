#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

// 0 -> '<'
// 1 -> '>='
int query(int middle){
    //query
    cout<<middle<<endl;

    string in;
    cin>>in;

    return (in == ">=");
}

int32_t main(){

    int left=1,right = 1e6,ans;
    while(left<=right){
        int middle = (left+right)/2;
        if(query(middle)){
            ans = middle;
            left = middle + 1;
        }
        else {
            right = middle - 1;

        }

    }
    cout<<"!" <<ans<<endl;

    return 0;
}