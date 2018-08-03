#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
bool flag[16000005];
int main()
{
    int i,j;
	int a,c,m,R;
	memset(flag,0,sizeof(flag));
    cin>>a>>c>>m>>R;
	flag[R]=1;
	int ans=0;
	while(1)
	{
		R=(a*R+c)%m;
		if(flag[R])
			break;
		flag[R]=1;
	}
	for(i=0;i<m;i++)
		if(flag[i])
			break;
	for(j=i+1;j<m;j++)
	{
		if(flag[j])
		{
			if(j-i>ans)
				ans=j-i;
			i=j;
		}
	}
    cout<<ans<<endl;
    //while(1);
}
