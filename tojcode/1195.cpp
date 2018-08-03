#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int inn[30];int res;bool map[30][30];int in[30];
vector<int> ans;
int n,m;
bool f(int *ini)
{
	memcpy(in,ini,sizeof(in));
	bool flag=0;  
	queue<int> q;
	int temp;
	for(int i=0;i<n;i++)
	{
		if(in[i]==0)
		{
		  q.push(i);
		 
		}
	}
	while(!q.empty())
	{
		 if(q.size()>1)  flag=1;
		 temp=q.front();
		q.pop();
		ans.push_back(temp);
		for(int i=0;i<n;i++)
		{
			if(map[temp][i])
			{
				in[i]--;
				if(in[i]==0)
				{
				  q.push(i);
			      
				}
				  
			}
		}
	}
	if(ans.size()<n)
	  return res=1;
	if(flag==1)
	  return res=0;  
	
	return res=2;
}
int main()
{
	string str;
	while(cin>>n>>m&&(n+m))
	{
		
		memset(map,0,sizeof(map));
		memset(inn,0,sizeof(inn));
		int i;bool flag=0;
		for(i=0;i<m&&!flag;i++)
		{
			ans.clear();
			cin>>str;
			int u=str[0]-'A';
			int v=str[2]-'A';
			map[u][v]=1;
			inn[v]++;
			if(f(inn))
			{
				flag=1;
			}
		}
		for(int j=i;j<m;j++)  cin>>str;
		switch(res)
		{
			case 0: cout<<"Sorted sequence cannot be determined."<<endl;break;
			case 1: cout<<"Inconsistency found after "<<i<<" relations."<<endl;break;
			case 2:{
				  cout<<"Sorted sequence determined after "<<i<<" relations: ";
				  for(int k=0;k<n;k++)
				    cout<<(char)(ans[k]+'A');
				  cout<<"."<<endl;
				  break;
				}
		}
	}
}  


 
			
			
	
