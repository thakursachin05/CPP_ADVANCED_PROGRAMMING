#include<iostream>
using namespace std;

#define int long long int
const int P = 1e9+7 , N = 1e5;
int fact[N];


int addm(int x, int y){
    return (x + y) % P;
}

int subm(int x, int y){
    return ((x-y) %P + P) % P;
}

int mulm (int x , int y){
    return (x * y) % P;
}

//log(Y)
int powrm(int x, int y){
    int res =1;
    while(y) {
        if(y & 1) res = mulm(res , x);
        y /=2;
        x = mulm(x,x);
    }
    return res;
}

int inv(int x){
    return powrm(x , P-2);
}

int divm(int x, int y){
    return mulm(x , inv(y));
}

void calulate_factorials() {
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = mulm(fact[i-1],i);
    }
}

int ncr (int n, int r){
    return mulm(mulm(fact[n],inv(fact[r])),inv(fact[n-r]));

}

int32_t main(){

    // cout<<mulm(324,324);
    // cout<<divm(56,2);
    calulate_factorials();
    cout<<fact[5]<<"\n";

    cout<<ncr(5,2)<<endl;
    cout<<ncr(5778,123)<<endl;
    

    return 0;
}