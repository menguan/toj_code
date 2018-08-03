#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int a;
    while(cin>>s)
    {
      if(s==".")
        return 0;
      int l1=s.length();  
      string s_=s;
      cin>>a;
      while(--a)
      {
          s.insert(0,s_);
      }
      int l2=s.length();
      int i=0;
      for(int l=0;l<l1;l++)
      {
          for(int j=i,jj=0;jj<l2;jj++,j++)
          {
              int y=j%l2;
              cout<<s[y];
          }
          cout<<endl;
          i++;
      }        
    }
    return 0;
} 