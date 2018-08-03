#include<stdio.h>
#include<cstring>
int a[120][120];
int b[120][120];
int c[120][120];
int d[120][120];   
int main()
{
    int t;int am,an,bm,bn;
    int g;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&g);
      g--;
      scanf("%d%d",&am,&an);
      bn=an;
      for(int i=1;i<=am;i++)
      for(int j=1;j<=an;j++)
        scanf("%d",&a[i][j]);
      while(g--)  
      {scanf("%d%d",&bm,&bn);
       for(int i=1;i<=bm;i++)
       for(int j=1;j<=bn;j++)
         scanf("%d",&b[i][j]);
       memset(c,0,sizeof(c));
       for(int i=1;i<=am;i++)
       for(int j=1;j<=an;j++)
       for(int k=1;k<=bn;k++)
         c[i][k]+=a[i][j]*b[j][k];
       //for(int i=1;i<=am;i++)for(int j=1;j<=bn;j++)printf("%d",c[i][j]);  
       memcpy(a,c,sizeof(a));
       an=bn;
      }  
      for(int i=1;i<=am;i++)
      {
          for(int j=1;j<=bn;j++)
          {
             if(j>1)  printf(" ");
             printf("%d",a[i][j]);
          }
          puts("");
      }
      puts("");
    }
}           
                           
    
    
