#include<stdio.h>//网上的代码竟然还有细节问题 
#include<cstring>
#include<algorithm>
using namespace std;
#define N 20
#define MAX 4000000
char s[3][N],op;
int n[3][N],len[3];
int num;
struct cha
{
  char c;
  int n;
}a[N];
bool number[10];
bool OK;
void init(char *tmp)
{
  bool used[N<<1];
  memset(n,0,sizeof(n));
  memset(s,0,sizeof(s));
  memset(a,0,sizeof(a));
  memset(used,0,sizeof(used));
  num=0;
  int i,j,k;
  for(i=0,j=0;i<3;i++)
  {
    len[i]=j;
    for(k=0;;j++,k++)
    {
      if(tmp[j]=='+'||tmp[j]=='-'||tmp[j]=='='||tmp[j]=='\0')
        break;
      s[i][k]=tmp[j];
      if(tmp[j]>='0'&&tmp[j]<='9')  n[i][k]=tmp[j]-'0';
      else
      {
        n[i][k]=tmp[j]-'A'+26;
        if(!used[tmp[j]-'A'])
        {
          used[tmp[j]-'A']=1;
          a[num++].c=tmp[j];
        }
      }
    }
    s[i][k]='\0';
    if(i==0) op=tmp[j];
    len[i]=j-len[i];
    j++;
  }
}    
int tran(int i)
{
  int ans=0;
  for(int k=0;k<len[i];k++)
  {
    ans=ans*10+n[i][k];
  }
  return ans;
}
void cal()
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<len[i];j++)
    {
      if(s[i][j]>='A'&&s[i][j]<='Z')
        for(int k=0;k<num;k++)
        {
          if(s[i][j]==a[k].c)
            n[i][j]=a[k].n;
        }
    }
  }
  int ss[3];
  for(int i=0;i<3;i++)
  {
    ss[i]=tran(i);
  }
  if(op=='+'&&ss[0]+ss[1]==ss[2])  OK=1;
  if(op=='-'&&ss[0]-ss[1]==ss[2])  OK=1;
}
void dfs(int c)
{
  if(c>=num)
  {
    cal();
    return ;
  }
  for(int i=0;i<10;i++)
  {
    if(!number[i])
    {
      number[i]=1;
      a[c].n=i;
      dfs(c+1);
      if(OK)  return ;
      number[i]=0;
    }
  }
}
int cmp(cha p,cha q)
{
  return p.c<q.c;
}
void solve()
{
  OK=0;
  sort(a,a+num,cmp);
  memset(number,0,sizeof(number));
  dfs(0);
  if(OK)
  for(int i=0;i<num;i++)
    printf("%c %d\n",a[i].c,a[i].n);
}
int main()
{
  char tmp[3*N];
  while(scanf("%s",tmp)!=EOF)
  {
    init(tmp);
    solve();
  }
}
  
     
  
  
         