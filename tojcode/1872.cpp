#include<cstdio>//先加后乘 和 先乘后加 
#include<cstring>
#include<iostream>
using namespace std;
char s[1010];
int main()
{
	int t;long long minn,maxn;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		minn=0;maxn=1;
		int len=strlen(s);
		long long now=1;long long temp=0;
	    for(int i=0;i<=len;i++)
	    {
            //cout<<now<<" "<<temp<<" "<<minn<<endl;
            if(s[i]=='*'&&i<len)
            {
               now*=temp;
               temp=0;
            }
            else if(s[i]=='+'||i==len)
            {
                now*=temp;
                minn+=now;
                now=1;temp=0;
            }
            else
              temp=temp*10+s[i]-'0';
        } 
        now=0;temp=0;
        for(int i=0;i<=len;i++)
	    {
            if(s[i]=='+'&&i<len)
            {
               now+=temp;
               temp=0;
            }
            else if(s[i]=='*'||i==len)
            {
                now+=temp;
                maxn*=now;
                now=0;temp=0;
            }
            else
              temp=temp*10+s[i]-'0';
        }  
        //cout<<minn<<" "<<maxn<<endl; 
        cout<<"The maximum and minimum are "<<maxn<<" and "<<minn<<".\n";              
		//printf("The maximum and minimum are %lld and %lld.\n",maxn,minn);
	}
}
