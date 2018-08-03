#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
char map[120][120];
char now[120][120];
int n,m,r,c;
int main()
{
    while(scanf("%d%d%d%d",&n,&m,&r,&c)&&(n+m+r+c))
    {
       for(int i=0;i<n;i++)
         scanf("%s",map[i]);
       for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
         now[i][j]='0';  
       //for(int i=0;i<n;i++)
       //{
        //  for(int j=0;j<m;j++)
         //   cout<<map[i][j];
        //  cout<<endl;
       //} 
       //for(int i=0;i<n;i++)
       //{
     //     for(int j=0;j<m;j++)
      //      cout<<now[i][j];
       //   cout<<endl;
       //}   
       int ans=0;  
       for(int i=0;i<n-r+1;i++)
       {
         for(int j=0;j<m-c+1;j++)
         {
            if(now[i][j]==map[i][j])
              continue;
            else
            {
      
               ans++;
               for(int k=i;k<i+r;k++)
               {
                  for(int l=j;l<j+c;l++)
                  {
                       if(now[k][l]=='0')
                         now[k][l]='1';
                       else if(now[k][l]=='1')
                         now[k][l]='0';
                  }
               }
            }
         }
       }
       //for(int i=0;i<n;i++)
       //{
        //  for(int j=0;j<m;j++)
        //    cout<<now[i][j];
         // cout<<endl;
       //}         
         bool flag=1;
         for(int i=0;i<n;i++)
         {  for(int j=0;j<m;j++)
            {
              if(now[i][j]!=map[i][j])
              {
                 flag=0;
                 break;
              }
            }
         }
         if(flag)
           cout<<ans<<endl;
         else
           cout<<-1<<endl;
       
    }
}  
                                                  
                                                                                 
    
 
