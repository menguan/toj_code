#include<iostream>
#include<cstring>
using namespace std; 
int id[20000];
int sz[20000];
bool fri[20000];
int owe[20000];
int find(int p)
{
	while (p != id[p])
	{
		id[p] = id[id[p]];
		p = id[p];
	}
	return p;
}
void add(int p, int q)
{
	int i = find(p);
	int j = find(q);
	if (i == j) return;
	if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
	else { id[j] = i; sz[i] += sz[j]; }
	
}
int main()
{
  for(int i=0;i<20000;i++)
    id[i]=i;
  memset(sz,1,sizeof(sz));
  memset(fri,0,sizeof(fri));
  int n,m;
  bool flag=1;
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>owe[i];
  int a,b;  
  while(m--)  
  {
    cin>>a>>b;
    add(a,b);
  }
  int now;
  for(int i=0;i<n;i++)
  {
    if(fri[i])
      continue;
      
    
    fri[i]=1;
    now=owe[i];
    for(int j=0;j<n;j++)
    {
      if(fri[j])
        continue;
      if(find(j)==find(i))
      {
        fri[j]=1;
        now+=owe[j];
      }
    } 
    if(now!=0)
      flag=0;
  }
  if(flag)
    cout<<"POSSIBLE"<<endl;
  else
    cout<<"IMPOSSIBLE"<<endl;
  //while(1);
}    
         
        
            
    
  