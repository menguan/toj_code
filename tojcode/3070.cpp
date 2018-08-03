#include<iostream>
#include<cstring>
using namespace std;
void f(char a,int i)
{
    char k[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int j=0;j<26;j++)
    {
        if(a==k[j])
        {
            cout<<k[(j+i)%26];
        }
    }
}            
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
      char t[111];
      int i=0;
      cin>>t>>i;
      for(int j=0;j<strlen(t);j++)
      {
          f(t[j],i);
      }
      cout<<endl;
    }
    return 0;
} 