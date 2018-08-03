#include<iostream>
#include<string>
#include<cstring>
int len[100];
using namespace std;
int main()
{
  string s;
  while(cin>>s)
  {
    memset(len,0,sizeof(len));
    int l=s.length();
    len[1]=l;
    for(int i=0;i<l;i++)//奇数 
    {
      int j=i-1;
      int k=i+1;
      while(j>=0&&k<l&&s[j]==s[k])
      {
        len[k-j+1]++;
        j--;
        k++;
      }  
    }
    for(int i=0;i<l;i++)//偶数 
    {
      int j=i;
      int k=i+1;
      while(j>=0&&k<l&&s[j]==s[k])
      {
        len[k-j+1]++;
        j--;
        k++;
      }  
    }
    for(int i=l;i>0;i--)
    {
      if(len[i])
      {
        cout<<i<<" "<<len[i]<<endl;
        break;
      }  
    }    
  }
}        
            