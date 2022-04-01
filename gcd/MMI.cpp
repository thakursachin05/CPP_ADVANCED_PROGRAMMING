#include<iostream>
#include<vector>
using namespace std;

// {x,y}
int gcd(int a , int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
vector<int> extendedGCD(int a, int b){
    if(b==0){
        //return the values of x and y
        return {1,0,a};
    }
    vector<int> result = extendedGCD(b,a%b);
     
     //bottom Up solution

     //after recursive call is over
     int smallX = result[0];
     int smallY = result[1];
     int gcd = result[2];

     int x =smallY;
     int y = smallX - (a/b)*smallY;
     
     return {x,y,gcd};
}

//Code for MMI

int modInverse(int a , int m){
    vector<int> result = extendedGCD(a,m);
    int x = result[0];
    int gcd = result[2];

    if(gcd!=1){
        cout<<"Multiplicative Modulo Inverse doesn't exist";
        return -1;
    }

    int ans = (x%m+m)%m; //x can be negative also, {1,2,3......m-1}
    return ans;
}
int main(){

    int a,m;
    cin>>a>>m;

    //a x + b y = gcd (a , b);
    cout<<modInverse(a,m)<<endl;
}