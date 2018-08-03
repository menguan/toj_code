#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  int n,t;
  cin>>t;
  while(t--)
  {
            cin>>n;
            int bas=0;
            int ans=0;
            for(int i=1;i<=1000000000;i++)
            {
               if(n>i) {n-=i;ans++;}
               else
                break;
               }     
            cout<<ans+1<<endl;
  }       
}
