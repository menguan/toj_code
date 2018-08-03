#include<iostream>

using namespace std;
int sum[10000000];
int main()
{
    int n,s;
    kk:while(cin>>n>>s)
    {
         if(n==0&&s==0)
           return 0;
         
         
         sum[1]=0;
         int count=2;
         int num[n];
         for(int i=0;i<n;i++)
         {
           cin>>num[i];
           
         }
           
         for(int i=0;i<n;i++)
         {
             int c=count;
             for(int j=1;j<c;j++)
             {
                 sum[count]=sum[j]+num[i];
                 count++;
             }
         }
                
         for(int i=2;i<count;i++)
         {
             
             if(s==sum[i])
             {cout<<"Yes"<<endl;
             goto kk;}
         }
         cout<<"No"<<endl;
     }
    return 0;
                     
 } 