#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    while(n--)
    {
      cin>>m;
      long long max,min;
      long long t;
      cin>>t;
      max=min=t;
      m--;
      while(m--)
      {
        cin>>t;
        if(t<min)
        min=t;
        else if(t>max)
        max=t;
        }        
                
      
      cout<<max-min<<endl;
      }
      }  //想麻烦了                 
    
