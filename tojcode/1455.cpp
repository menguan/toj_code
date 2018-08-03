#include<iostream>
#include<cstring>
#include<algorithm>
#define N 999999 
using namespace std;

int c[N];
int t[N];//还必须离散 
 
struct f
{
  int v;
  int order;
}in[N];   
bool _f(f a, f b)
{
   return a.v<b.v;
}     
int Lowbit(int x) 
{ 
    return x&(-x); 
} 
void _plus(int i,int x) 
{ 
    while(i<=N) 
    { 
        c[i]+=x; 
        i+=Lowbit(i); 
    } 
} 
int Sum(int i) 
{ 
    int sum=0; 
    while(i>0) 
    { 
        sum+=c[i]; 
        i-=Lowbit(i); 
    } 
    return sum; 
} 
int main()
{
   int n,count=1;
   
   
   while(cin>>n,n)
   {
      long long sum=0;
      
      memset(c,0,sizeof(c));
      
      for(int i=1;i<=n;i++)
      {
         cin>>in[i].v;
         in[i].order=i;
      }
      sort(in+1,in+n+1,_f);
      for(int i=1;i<=n;i++)
        t[in[i].order]=i;
      for(int j=n;j>=1;j--)
      {
         int temp=t[j]+1;
         sum+=Sum(temp-1);
         _plus(temp,1);
      }
      cout<<sum<<endl;
    }
}  