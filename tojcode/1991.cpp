#include<iostream>
#include<string>
using namespace std;

int f(string a,int base)
{
  int sum=0;
  int len=a.length();
  for(int i=len-1,j=1;i>=0;i--,j*=base)
  {
    sum+=(j*(a[i]-'0'));
  }
  return sum;
}
string a[10];
int main()
{
  int n;
  while(cin>>n,n)
  {
     for(int i=0;i<n;i++)
       cin>>a[i]; 
     int max=0;
     for(int i=0;i<n;i++)
     {
       for(int j=0;j<a[i].length();j++)
       {
         if((int)(a[i][j]-'0')>max)
           max=(int)(a[i][j]-'0');
       }
     }        
     if(n==2)
     {
       cout<<"Minimum base = ";
         cout<<max+1<<"."<<endl;
       continue;
     }
     int i,j;
     int flag=1;
     for(i=max+1;i<=10&&flag;i++)    
     {
       for(j=0;j<n-2;j++)
       {
           
           if(f(a[j+1],i)-f(a[j],i)!=f(a[j+2],i)-f(a[j+1],i))
           {
              break;
           }
       }
       if(j==n-2)
       {
         cout<<"Minimum base = ";
         cout<<i<<"."<<endl;
         break;
       }
     }
     if(i==11)
     {
       cout<<"No base <= 10 can be found."<<endl;
     }
   }
}  