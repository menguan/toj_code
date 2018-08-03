#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char a[30],d[99];
int c[50],i,j,k,n;//C是存各位的数
int main()
{
	while(cin>>n,n)
    {
		memset(d,0,sizeof(d));
        memset(c,0,sizeof(c));
        getchar();
		gets(a);
		for(i=0;i<n;i++)
        {
			k=0;
			for(j='A';j<a[i];j++)if(d[j]<1)k++;
			d[a[i]]=1;
			for(j=0;j<49;j++)
                c[j]*=(26-i);
			c[0]+=k;
			for(j=0;j<48;j++){
				c[j+1]+=c[j]/10;
				c[j]=c[j]%10;
			}
		}
		i=49;
		while(c[i]<1&&i>0)i--;
		for(j=i;j>=0;j--)
            cout<<c[j];
		cout<<endl;
	}
	return 0;
}
