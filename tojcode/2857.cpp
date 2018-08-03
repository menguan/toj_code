#include<iostream>
#include<algorithm>
using namespace std;
int f(int a)
{
    int wei=0;
    
    for(int i=1,j=0;i<=1000000;i*=10,j++)
    {
        if(a/i==0)
        {
          wei = j;
          break;
        }  
    }
    
    int t[wei];
    int sum=0;
    for(int j=0;j<wei;j++)
    {
        t[j]=a%10;
        a/=10;
    }
    sort(t,t+wei);
    for(int i=1,j=wei-1;j>=0;i*=10,j--)
    {
        
        sum+=(i*t[j]);
    }
    return sum;           
    
}
int main()
{
    int n;
    while(cin>>n,n)
    {
        int a[n];
        
        int t;
        for(int i=0;i<n;i++)
        {
           
           cin>>t;
           a[i]=f(t);
           
    
        }
        sort(a,a+n);
        cout<<a[n-1]<<endl;
    }    
    
    
    return 0;
}  