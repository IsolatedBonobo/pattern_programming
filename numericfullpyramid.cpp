#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        for(int col=0;col<n-row;col++){
            cout<<" ";

        }
        //another way for same below for loop
        int start=row+1;
        for(int col=0;col<row+1;col++){
            cout<<start;
            start++;
        }
        // OR
        // for(int col=0;col<row+1;col++){
        //     cout<<col+row+1;        
        // }
       
        for(int col=row;col>=1;col--){
            cout<<col+row;
        }
        for(int col=0;col<n-row;col++){
            cout<<" ";
        }
        cout<<endl;

    }

}