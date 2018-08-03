#include<iostream>
using namespace std; 

int main()
{
      
      int n;
      
      cin>>n;
      for(int j=1;j<=n;j++)
      {
          long long a;
          cin>>a;
          int zero=0;
          int i;
          for(i=5;i<=a;i*=5)
          {
              zero+=a/i;
          }
          cout<<zero<<endl;
      }
      
      return 0;
}  