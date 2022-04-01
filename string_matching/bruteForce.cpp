#include<bits/stdc++.h>

using namespace std;

int main() {
    
    string text = "ababaababbbbabaaa";
    string pat = "aa";
    int m = pat.size();
    int n = text.size();

    for(int i=0;i + m <= n;i++){
        if(text.substr(i,m) == pat){
            cout<<i<<'\n';
        }
    }
    return 0;
}