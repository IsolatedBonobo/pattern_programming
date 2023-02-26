#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char str[1024];
    gets(str);
    int a=strlen(str);
    char c[1024];
    for(int i=0;i<a;i++){
        c[i]=str[i];
        if(c[i]>='A' && c[i]<='Z' || c[i]>='a' && c[i]<='z')
        cout<<c[i];
        else if(c[i]>=33 && c[i]<=64 || c[i]>=91 && c[i]<=96)
        cout<<"";
        else 
        cout<<endl;

    }



    return 0;
}