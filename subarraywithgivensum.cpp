#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int S;
    cin>>S;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
           sum+=arr[j];
           if(sum>S)
               break;
           else if(sum==S){
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
        


    }
}