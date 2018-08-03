#include<iostream>
#include<cstring>
#define N 2000010 
using namespace std;

int c[N+100]; 
int a[1010]; 
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
   cin>>n;
   
   while(n--)
   {
      int sum=0;
      int m;
      cin>>m;
      memset(c,0,sizeof(c));
      for(int i=1;i<=m;i++)
      {
         cin>>a[i];
      }
      for(int j=m;j>=1;j--)
      {
         int temp=a[j]+1000001;
         sum+=Sum(temp-1);
         _plus(temp,1);
      }
      cout<<"Scenario #"<<count++<<":"<<endl<<sum<<endl<<endl;
    }
}    
          
   