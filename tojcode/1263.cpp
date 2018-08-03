#include<cstdio>
#include<stdlib.h>
#include<string.h>

struct da
{
  char ch[105];        
}dd[105];

int fun(const void *a,const void *b)
{ 
  return strcmp( (*(da *)a).ch , (*(da *)b).ch ); 
}
int judge(char *a,char *b) 
{
    int i,j,k,flag;
    int len1=strlen(a),len2=strlen(b);
    for(i=0;i+len1-1<=len2;i++)
    {flag=1;
      for(j=i,k=0;k<=len1-1;j++,k++)
      if(a[k]!=b[j]){flag=0;break;}
      if(flag) return 1;                         
    }
    return 0;
}
int main()
{
  int i,cas,n,len,l,k1,k2,j,flag1,flag2,r,f,f1,f2;
  char temp1[101],temp2[101];
  scanf("%d",&cas);
  while(cas--)
  {
  scanf("%d",&n);
  
  for(i=0;i<n;i++) 
  scanf("%s",dd[i].ch);
  qsort(dd,n,sizeof(dd[0]),fun);
  
  len=strlen(dd[0].ch);
  f=0;
  for(l=len;l>0;l--)
  {
    for(i=0;i+l-1<len;i++) 
    {
       for(j=i,k1=0,k2=l-1;j<i+l;j++,k1++,k2--)
       {temp1[k1]=dd[0].ch[j];temp2[k2]=dd[0].ch[j];}
       temp1[k1]='\0';temp2[k1]='\0';
       
       flag1=0;f1=1;
       for(r=1;r<n;r++)
       if(judge(temp1,dd[r].ch)==0&&judge(temp2,dd[r].ch)==0)
       {f1=0;break;}
       
       if(f1) flag1=1;
       if(flag1) {f=1;goto loop;}
    }                  
  } 
loop: if(f)printf("%d\n",l);
      else printf("0\n");
  }    
}  