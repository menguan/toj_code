#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   int t;char s[100];
   int temp;
   int n;
   int ans;
   cin>>t;
   while(t--)
   {
          cin>>n;
          cin>>s;
          if(s[0]=='l')
            ans=1;
          else
            ans=0;  
          for(int i=1;i<n;i++) 
          {
            cin>>s;
            if(s[0]=='l')
            temp=1;
            else
            temp=0; 
            ans^=temp;
          }
          if(ans)
            cout<<"lxh"<<endl;
          else
            cout<<"hhb"<<endl;
   }
}  
                    
            
