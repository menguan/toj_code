#include<iostream>//照打 
#include<cstring>
#include<stdio.h>
using namespace std;
int s[10],x[10],lev;
int numnode[10]={1,2,4,8,16,32,64,128};
char lea[300];
int main()
{
    int T=0,n,m,i,j,p,q,num;char ch,temp[10],ans[300];
    while(scanf("%d",&n)!=EOF&&n)
    {
      getchar();
      T++;
      printf("S-Tree #%d:\n",T);
      for(i=0;i<n;i++)  scanf("%c%d%c",&ch,&s[i],&ch);
      for(q=0,i=0;i<=n;i++) q+=numnode[i]; p=q-numnode[n]+1;
      for(i=p;i<=q;i++)  scanf("%c",&lea[i]);lea[i]='\0'; getchar();
      scanf("%d",&m);  getchar();
      for(j=0;j<m;j++)
      {
        scanf("%s",temp+1);for(i=1;i<=n;i++) x[i]=temp[i]-'0';
        num=1;lev=0;
        while(lev<n)
        {
           i=s[lev];
           if(x[i]) num=num*2+1;
           else     num=num*2;
           lev++;
        }
        ans[j]=lea[num];
      }
      ans[j]='\0';
      printf("%s\n\n",ans);
    }
}                                                        
