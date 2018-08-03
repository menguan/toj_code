#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void pl(string s)
{
    int l=s.length();
    if(s[l-1]=='y'&&s[l-2]!='a'&&s[l-2]!='e'&&s[l-2]!='i'&&s[l-2]!='o'&&s[l-2]!='u')
    {
        s.erase(l-1,1);
        cout<<s<<"ies"<<endl;
    }
    else if(s[l-1]=='o'||s[l-1]=='s'||s[l-1]=='x'||(s[l-2]=='c'&&s[l-1]=='h')||(s[l-2]=='s'&&s[l-1]=='h'))    
    {
        cout<<s<<"es"<<endl;
    }
    else
        cout<<s<<"s"<<endl;
}                 
int main()
{
    int a,b;
    cin>>a>>b;
    char aa[a][50];
    char bb[a][50];
    for(int i=0;i<a;i++)
    {
        cin>>aa[i]>>bb[i];
    }
    for(int i=0;i<b;i++)
    {
        string s;
        bool p=0;
        cin>>s;
        for(int i=0;i<a;i++)
        {
            if(aa[i]==s)
            {    
                 cout<<bb[i]<<endl;
                 p=1;
                 break;
            }            
        }
        if(p==1)
         
           continue;
          
        else
          pl(s);
    }
    return 0;
}  