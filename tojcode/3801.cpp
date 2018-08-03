#include<iostream>
#include<string>
using namespace std;
string s[101];
int len[101];
int main()
{
    int n;
    kk:while(cin>>n,n)
    {
      if(n==0)
        return 0;
      int t=n;  
      while(t)
      {
        cin>>s[t];
        len[t]=s[t].length();
        t--;
      }
      
      int count=0;
      while(1)
      {
        
        for(int i=1;i<n;i++)
        {
          for(int j=i+1;j<=n;j++)
          {
            
            if(s[i].compare(s[j])==0)
            {
              cout<<count-1<<endl;
              goto kk;
            }
          }
        }
        
        count++;
        for(int i=1;i<=n;i++)
        {
          s[i].erase(0,1);
          len[i]--;
          if(len[i]==0)
          {
            cout<<count-1<<endl;
            goto kk;
          }
        }
      }      
    }
} 