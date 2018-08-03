#include<iostream>
#include<algorithm> 
using namespace std;
int num[10000];
int main()
{

    int n;
    while(cin>>n)
    {
         
         if(n==0)
           return 0;
         if(n==1||n==2)
         {
           cout<<"-1"<<endl;
           continue;
         }  
         int count=0;
         for(int i=0;i<n;i++)
         {
           cin>>num[i];
         }
         bool flag=0;
         sort(num,num+n);
         for(int i=n-1;i>=2&&!flag;i--)
         {
           for(int j=i-1;j>=1&&!flag;j--)
           {
             for(int k=j-1;k>=0&&!flag;k--)
             {
               if(num[i]>num[j]+num[k])
                 break;
               if(num[i]==num[j]+num[k]&&j!=k)
               {
                 cout<<num[i]<<endl;
                 flag=1;
                 break;
               }
             }
           }
         } 
         if(!flag)
           cout<<"-1"<<endl;
      }
}     