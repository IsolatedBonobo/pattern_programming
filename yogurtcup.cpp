#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int sum[t];
    for(int i=0;i<t;i++){
        sum[i]=0;
        int n;
        cin>>n;
        int k;
        cin>>k;
        int cup[n];
        for(int j=0;j<n;j++){
            cin>>cup[j];

        }
        for(int j=0;j<n;j++){
            if(sum[i]>=k)
            break;
            else{
                if(cup[j]!=0)
                sum[i]++;

            }
        
        }
        
        
    }
    for(int i=0;i<t;i++){
        cout<<sum[i]<<endl;

    }
}