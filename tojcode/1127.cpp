#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int n,m;
   cin>>n>>m;
   int i , j , k;
   int times;
   char t[105][55];
   int num[105]={0};
   int d[105]={0};
   for(times=0;times<m;times++)
   {
       for(i=0;i<n;i++)
           cin>>t[times][i];
       for(j=0;j<n;j++)
           for(k=j+1;k<n;k++)
               if(t[times][j]>t[times][k])
               num[times]++;
       d[times]=num[times];
   }
   sort(num,num+m);
   for(i=0;i<m;i++)
   {
       for(times=0;times<m;times++)
       {
           if(d[times]==num[i])            
               for(k=0;;k++)
               {
                   cout<<t[times][k];
                   if(k==n-1)
                   {
                       cout<<endl;
                       d[times]=-1;
                       break;
                   }    
               }
       }
   }
   return 0;
}