#include<iostream>
#include<algorithm>
using namespace std;
int a[1010];
int b[1010];
int main()
{
  int n;
  while(cin>>n,n)
  {
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
      cin>>b[i];
    } 
    sort(a,a+n);
    sort(b,b+n);
    int sum=0;
    int aa=0,aaa=n-1,bb=0,bbb=n-1;
    for(int i=0;i<n;i++)    
    {
        if(a[aa]>b[bb])
        {
          sum+=200;
          aa++;
          bb++;
        }      
        else if(a[aaa]>b[bbb])
        {
          sum+=200;
          aaa--;
          bbb--;
        }
        else
        {
          if(a[aa]!=b[bbb])
          {
            sum-=200;
          }
          else
           ;
          
          aa++;
          bbb--;
        }            
    }
    cout<<sum<<endl;
  }
}  