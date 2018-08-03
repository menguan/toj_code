#include<iostream>
#include<string>
using namespace std;
int v(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
    return 1;
    else 
    return 0;
}    
int main()
{
    string s;
    while(cin>>s&&s!="end")
    {
        bool k1=0;
        bool k2=1;
        bool k3=1;
        for(int i=0;i<s.length();i++)
        {
            if(v(s[i])==1)
            k1=1;
        }
        if(s.length()>=3)
        {
          for(int i=1;i<s.length()-1;i++)
          {
              if(v(s[i-1])==v(s[i])&&v(s[i+1])==v(s[i]))
              k2=0;
          }
        }
        if(s.length()>=2)
        {
          for(int i=1;i<s.length();i++)
          {
              if(s[i-1]==s[i])
              { 
                k3=0;                
                if(s[i-1]=='e'||s[i-1]=='o')
                k3=1;
              }  
          }
        }
        if(k1==1&&k2==1&&k3==1)
        cout<<"<"<<s<<"> is acceptable."<<endl;
        else
        cout<<"<"<<s<<"> is not acceptable."<<endl;
     }
     
     return 0;
} 