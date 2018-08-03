#include<iostream>
#include<algorithm>
using namespace std;
int a[100000];
int main()
{
   int n,lon;
   cin>>n>>lon;
   for(int i=0;i<n;i++)
     cin>>a[i];
   sort(a,a+n);
   int re=0;
   for(int i=0,j=n-1;j>=i;j--)
   {
     re++;
     if(a[i]+a[j]<=lon)
     {
       i++;
     }
   }
   cout<<re<<endl;
   
}         