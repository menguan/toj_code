#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int main()
{
  int n;
  string s;
  cin>>n;
  while(n--)
  {
    int t[123];
    for(int i=97;i<123;i++)
      t[i]=0;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
      t[(int)s[i]]++;
    }
    int max=0;
    for(int i=97;i<123;i++)
    {
       if(t[i]>max)
       max=t[i];
    }   
    for(int i=97;i<123;i++)
    {
       if(t[i]==max)
        cout<<(char)i;        
    }
    cout<<endl;
                
  }
}    