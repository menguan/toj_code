#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
int main()
{
    int n,m;
    long long sum;
    cin>>n;
    while(n--)
    {
      sum=0;
      cin>>m;
      for(int i=0;i<m;i++)
        cin>>a[i];
      sort(a,a+m);
      int t=m;
      int i=0;
      while(t-1)
      {
         
         sum+=(a[i]+a[i+1]);
         a[i+1]=a[i]+a[i+1];
         i++;
         t--;
         if(a[i]>a[i+1])
         {
           for(int j=i;j<m-1;j++)
           {
              if(a[j]<=a[j+1])
                break;
              else
              {
                  int temp=a[j];
                  a[j]=a[j+1];
                  a[j+1]=temp;
                  } 
                  }                       
         }
         }             
      
              
     if(m==1)
     cout<<"0"<<endl;
     else   
        cout<<sum<<endl;
}} 