#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
char name[13131];int a[1000002];
int main()
{
    int t;
    cin>>t;int n;
    while(t--)
    {
              cin>>n;
              for(int i=0;i<n;i++)
              {
                      cin>>name>>a[i];
                      }
                      sort(a,a+n);long long ans=0;
       for(int i=0;i<n;i++ )              
       {
           ans+=abs(i+1-a[i]);
       }
       cout<<ans<<endl;
       }
       }                
