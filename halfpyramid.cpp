#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int row=0;row<2*n-1;row++){
        if(row<n){
        for(int col=0;col<row+1;col++){
            cout<<"*";

        }
        for(int col=0;col<n-row-1;col++){
            cout<<" ";
        }
        }
        else if(row>=n){
            for(int col=0;col<2*n-row-1;col++){
                cout<<"*";
            }
            for(int col=0;col<row-4;col++){
                cout<<" ";                
            }
        }
        
        cout<<endl;
        
    }
    
       
        
        

   
}