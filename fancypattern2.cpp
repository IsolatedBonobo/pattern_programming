#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a=1;
	for(int row=0;row<n;row++){
		for(int col=0;col<row;col++){
			cout<<a;
			a++;
			if(col!=row-1)
			cout<<"*";
			else
			cout<<" ";
		}
		cout<<endl;
	}
	
	for(int row=0;row<n-1;row++){
		for(int col=0;col<n-row-1;col++){
			cout<<a;
			a--;
			if(col!=n-row-2)
			cout<<"*";
			else
			cout<<" ";
		}
		cout<<endl;
	}
	
}