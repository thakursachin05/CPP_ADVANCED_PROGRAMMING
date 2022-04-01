#include<iostream>
using namespace std;

int main(){

    int people = 1;
    float num = 365;
    float denom = 365;

    float prob_diff_bday = 1;

    while(1){
        prob_diff_bday = prob_diff_bday * (num/denom);
        if(prob_diff_bday < 0.5) break;
        cout<<"People "<<people<<" Prob : "<<prob_diff_bday<<endl;
        num--;
        people++;
    }

    cout<<"Final Ans "<<people<<endl;

    return 0;
}