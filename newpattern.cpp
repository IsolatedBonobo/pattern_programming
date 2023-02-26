#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        int col;
        
        for(col=0;col<row+1;col++){
            int i=col + 1;
            char c='A' + i-1;
            cout<<c;
        }
        for(int col=row ; col>=1;col--){
            int i=col;
            char c='A' + i-1;
            cout<<c;
        }
        cout<<endl;
    }

}