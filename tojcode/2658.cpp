#include<iostream>
#include<cstring>
using namespace std;
int a[200];
long long b[33000];
void f()
{
   int i,j,k,t;
   for(i=1;i<=200;i++)
    a[i]=i*i;
   a[0]=0;
   for(i=0;i<=200;i++)
   {
     if(a[i]>32768)
     break;
     for(j=i;j<=200;j++)
     {
       if(a[i]+a[j]>32768)
       break;
       for(k=j;k<=200;k++)
       {
         if(a[i]+a[j]+a[k]>32768)
         break;
    	 for(t=k;t<=200;t++)
    	 {
     	   if(a[i]+a[j]+a[t]+a[k]>32768)
      	   break;
           else
           b[a[i]+a[j]+a[k]+a[t]]++;
         }
       }
     }
   }
}
int main()
{
 int n;
 memset(b,0,sizeof(b));
 f();
 while(cin>>n,n)
 {
  cout<<b[n]<<endl;
 }
} 
