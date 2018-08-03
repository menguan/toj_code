#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
using namespace std;
string s;
int solve(int top,int end){
	if(top==end){
		cout<<s[top];
		return 0;
	}
	else{
		int t,count=0;
		for(t=end-1;t>=top;t--){
			if(s[t]>='a'&&s[t]<='z')
				count++;
			else
				count--;
			if(count==1)
				break;
		}
		//cout<<t<<endl;
		solve(top,t-1);
		cout<<s[end];
		solve(t,end-1);
	}
}
int main(){
	int n;
	//string s;
	cin>>n;
	while(n--){
		cin>>s;
		solve(0,s.length()-1);
		cout<<endl;
	}
	return 0;
}
