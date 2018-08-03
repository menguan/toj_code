#include<iostream>
#include<cstring>
using namespace std;
bool map[400][200];int linker[500];
bool used[500];
bool jud(int pos,int p)
{
	for(int i=1;i<=p;i++)
	{
		if(map[pos][i]&&used[i]==0)
		{
			used[i]=1;
			if(linker[i]==-1||jud(linker[i],p))
			{
				linker[i]=pos;
				return 1;
			}
		}
	}
	return 0;
}
				
int f(int n,int p)
{
	int res=0;
	memset(linker,-1,sizeof(linker));
	for(int i=1;i<=n;i++)
	{
		memset(used,0,sizeof(used));
		if(jud(i,p))  res++;
	}
	return res;
}
int main()
{
	int t;int con;int temp;int n,p;
	cin>>t;
	while(t--)
	{
		memset(map,0,sizeof(map));
		cin>>p>>n;
		for(int i=1;i<=p;i++)
		{
			cin>>con;
			for(int j=1;j<=con;j++)
			{
				cin>>temp;
				map[temp][i]=1;
			}
		}
		if(f(n,p)==p)
		  cout<<"YES"<<endl;
		else
		  cout<<"NO"<<endl;
	}
}    
		  
				
			
		
		
