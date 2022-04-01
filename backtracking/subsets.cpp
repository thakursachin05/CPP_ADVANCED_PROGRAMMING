#include<iostream>
#include<vector>
using namespace std;

void findSubset(char *input, char *output, int i,int j){
    //base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }

    //rec case
    //Include the ith letter
    output[j] = input[i];
    findSubset(input,output,i+1,j+1);

    //Exclude the ith Letter
    //Overwritting 
    // output[j]='\0';
    findSubset(input,output,i+1,j);


}

int main(){
    char input[100];
    char output[100];

    cin>>input;
    findSubset(input,output,0,0);

    return 0;
}