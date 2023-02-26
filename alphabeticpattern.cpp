#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char c='A';
    for(int row=0;row<n;row++){
        for(int col=0;col<row;col++){
            cout<<" ";
        }
        for(int col=0;col<n-row;col++){
            cout<<char(c+row+col)<<" ";
            
        }
        cout<<endl;
    }

}