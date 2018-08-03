#include<iostream>
#include<string> 
using namespace std;
void f(string s)
{
    int l=s.length();
    if(l%3==1)
      s.insert(0,"00");
    if(l%3==2)
      s.insert(0,"0");
      
    l=s.length();
    for(int i=0;i<l-2;i+=3)
    {
        if(s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='1')
            cout<<1;
        if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0')
            cout<<2;
        if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='1')
            cout<<3;
        if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='0')
            cout<<4;
        if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='1')
            cout<<5;
        if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0')
            cout<<6;
        if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='1')
            cout<<7;
        if(s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='0')    
            cout<<0;
    }
    cout<<endl;
}                                    
            
    
          
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
      string s;
      cin>>s;
        f(s);
    }
    return 0;
}