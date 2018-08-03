#include<iostream>
using namespace std;
int map[200][200];int r,c;
bool jud(int i,int j)
{
	bool flag=1;
	for(int k=0;k<r;k++)
	{
		if(map[i][j]<map[k][j])
		  flag=0;
	}
	for(int k=0;k<c;k++)
	{
		if(map[i][j]<map[i][k])
		  flag=0;
	}
	if(flag)
	  return 1;
	else
	  return 0;
}    
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>r>>c;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>map[i][j];
		    }
		}
		int ans=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(jud(i,j))
				    ans++;
		    }
		}
		cout<<ans<<endl;
	}
}	
		
	
