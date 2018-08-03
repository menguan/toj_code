#include<iostream>
#include<cstdio>
using namespace std;
int ans[]={1,2,3,4,5,6,8,10,12,15,16,20,24,30,40,48,60,80,120,240};
int main()
{

   int t,n,i;
   cin>>t;
   while(t--)
   {
       scanf("%d",&n);
       for(i=0;i<20;i++)
           if(ans[i]==n)
           {
               puts("YES");
               break;
           }
           if(i==20)
               puts("NO");
   }
}
