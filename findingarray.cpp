#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int a[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)
            b[i]=a[j];
            
        }
        cout<<a[i]<<" ";
    }
    
    return 0;
}