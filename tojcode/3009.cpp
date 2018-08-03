#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main(){
	int n,dep,r,i,l,s;
	char a[200];
	cin>>n;
	getchar();
	for(i=1;i<=n;i++){
		gets(a);
		l=strlen(a);
		dep=0;
		r=0;
		for(int j=0;j<l;j++){
			if(a[j]=='[')
				dep++;
			else if(a[j]==']')
				dep--;
			if(r<dep)
				r=dep;
		}
		s=1;
		for(int j=0;j<r;j++){
			s=s*2;
		}
		cout<<i<<" "<<s<<endl;
	}
	return 0;
}
