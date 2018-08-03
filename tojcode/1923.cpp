#include<iostream>
#include<cstring>
using namespace std;
char s[100];
int t[26];
int main()
{
  int n;
  while(cin>>n,n)
  {
    for(int i=0;i<26;i++)
      t[i]=0;
    cin>>s;
    int re=0;
    for(int i=0;i<strlen(s);i++)
    {
      if(t[s[i]-'A']==0)
      {
        if(n)
        {
          t[s[i]-'A']=1;
          n--;
        }  
        else
        {
          t[s[i]-'A']=2;
          re++;
        }  
      }
      else if(t[s[i]-'A']==1)      
      {
        n++;
      }
    }
    if(re)
      cout<<re<<" customer(s) walked away."<<endl;
    else
      cout<<"All customers tanned successfully."<<endl;
  }
}      