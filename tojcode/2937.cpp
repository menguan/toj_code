#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
 int n,m;
 int a[20000];
 cin>>n;
 for(int i=1;i<=n;i++)
  {
    cin>>m;
    for(int j=0;j<m;j++)
    {
         cin>>a[j];
    }
    sort(a,a+m);
    int sum=0;
    if(m%3==0)
    { 
        for(int k=m-1;k>=0;k--)
            {
                    if(k%3==0)
                    sum+=a[k];
            }
     }
     else if(m%3==1)
     {
         for(int k=m-1;k>=0;k--)
          {         if(k%3==1)
                    sum+=a[k];        
           }
     } 
     else if(m%3==2)
     {
         for(int k=m-1;k>=0;k--)
          {         if(k%3==2)
                    sum+=a[k];        
           }
     }           
    cout<<sum<<endl;
  }
 
 return 0;
} 