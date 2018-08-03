#include<stdio.h>
#include<iostream>
#include<cstring>
const int MAXN=1000;
int map[MAXN][MAXN];
int n;
int linker[MAXN];
bool used[MAXN];
bool dfs(int a)
{
    for(int i=0;i<n;i++)
      if(map[a][i]&&!used[i])
      {
          used[i]=true;
          if(linker[i]==-1||dfs(linker[i]))
          {
              linker[i]=a;
              return true;
          }    
      }
      return false;    
}
int hungary()
{
    int result=0;
    memset(linker,-1,sizeof(linker));
    for(int i=0;i<n;i++)
    {
        memset(used,0,sizeof(used));
        if(dfs(i))  result++;
    } 
    return result;   
}
int f1(char *z)
{
	int len=strlen(z);
	int res=0;
	for(int i=0;i<len-1;i++)
	{
		res=res*10+z[i]-'0';
	}
	return res;
}
int f2(char *z)
{
	int len=strlen(z);
	int res=0;
	for(int i=1;i<len-1;i++)
	{
		res=res*10+z[i]-'0';
	}
	return res;
}
int main()
{
    int i,j,num,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(i=1;i<=n;i++)
        {
                scanf("%d: (%d)",&a,&num);
                for(j=0;j<num;j++)
                {
                    scanf("%d",&b);
                    map[a][b]=1;
                }    
        } 
        int cnt=hungary();
        printf("%d\n",n-cnt/2);
        
    }  
    return 0; 
}
