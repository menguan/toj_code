#include<iostream>
#include<cstring>
using namespace std;
char a[30];int aa[10];
char u[1000];int uu[10];long long ans;
long long f(int n,int m)
{
     
       long long ret=1;
     for(int i=1;i<=n;i++)
     {
              ret=ret*(m-i+1);
              }
              return ret;
} 
bool is()
{
      for(int i=0;i<10;i++)
      {
        if(uu[i]<aa[i])                               
          return 0;
          }
          return 1;
          }    
int main()
{
    while(cin>>a>>u)
    {ans=0;
                      memset(aa,0,sizeof(aa));
                      memset(uu,0,sizeof(uu));
      for(int i=0;i<strlen(a);i++)
      {
              aa[a[i]-'0']++;
              }
      for(int i=0;i<strlen(u);i++)
      {
              uu[u[i]-'0']++;
              }
              bool flag=1;aa[2]+=aa[5];
         aa[5]=0;
         aa[6]+=aa[9];
         aa[9]=0;
         uu[2]+=uu[5];
         uu[5]=0;
         uu[6]+=uu[9];
         uu[9]=0;
     for(int i=0;i<=9;i++)
     {
             if(aa[i]>uu[i])
               flag=0;
               }
               if(flag==0)
                 cout<<0<<endl;
     else
     {
         
         
         while(is()){ans++;
         for(int i=0;i<10;i++)
         {
           
           if(aa[i]==0)
             continue;
           else  if(i==5||i==9)
           {
             continue;
             }
           else  
           {
             
             uu[i]-=aa[i];;
             
                  
             
             }
             }
             } 
             cout<<ans<<endl;   
                              
                 
                     
         }
}         }
           
         
             
                               
