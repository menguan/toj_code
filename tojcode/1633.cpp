#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int n;
    char a[210],b[210],c[410];
    bool dp[210][210];
    cin>>n;
    for(int cas=1;cas<=n;cas++)
    {
       memset(dp,0,sizeof(dp));
       a[0]=b[0]=c[0]=';';
       scanf("%s",a+1);
       scanf("%s",b+1);
       scanf("%s",c+1);
       int lena=strlen(a);
       int lenb=strlen(b);
       int lenc=strlen(c);
       dp[0][0]=1;
       for(int i=0;i<=lena-1;i++){
       for(int j=0;j<=lenb-1;j++)
       {
             if(!i&&!j)
               continue;
             if(i&&c[i+j]==a[i]&&dp[i-1][j]==1)
               dp[i][j]=1;
             if(j&&c[i+j]==b[j]&&dp[i][j-1]==1)
               dp[i][j]=1;
       }
       }
       cout<< "Data set "<<cas<<": ";
       if(dp[lena-1][lenb-1])
         cout<<"yes"<<endl;
       else
         cout<<"no"<<endl;
    }
}                        
