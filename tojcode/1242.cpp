#include<iostream>
#include<cstring>
using namespace std;
int a[50];bool flag[50];
int ans[50];
int main()
{
	int t;int n;
	int p;
	cin>>t;
	while(t--)
	{
	    memset(flag,0,sizeof(flag));
	    memset(ans,0,sizeof(ans));
		cin>>n;int now=0;int j;
	    for(int i=1;i<=n;i++)
	    {
	        cin>>p;
	        for(j=now+1;j<p+i;j++)
	        {
				a[j]=0;
			}
			a[j]=1;
			now=j;
		}
		/*for(int i=1;i<=2*n;i++)
		{
			cout<<a[i]<<endl;
		}*/
    int con=0;
	for(int i=1;i<=2*n;i++)
	{
	    if(a[i]==1)
	    {
			flag[i]=1;
			for(int k=i-1;k>=1;k--)
			{
				if(a[k]==0&&!flag[k])
				{
					flag[k]=1;
					for(int l=k;l<=i;l++)
					{
						if(a[l]==1)
						  ans[con]++;
					}
					break;
				}
			}
			con++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
}
}
	

