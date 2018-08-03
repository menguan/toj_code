#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int f(string s)
{
    int i=0,j=1,k=0;
    int len=s.length();
    s+=s;
    while(i<len&&j<len)
    {
       //cout<<i<<" "<<j<<endl;
       k=0;
       while(k<len&&s[i+k]==s[j+k])
       {//cout<<s[i+k]<<" "<<s[j+k]<<endl;
         k++;}
       //cout<<k<<endl;  
       if(k>=len)
         break;
       if(s[i+k]>s[j+k])
         i=max(i+k+1,j+1);
       else
         j=max(i+1,j+k+1);
    }
    return min(i,j);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int pos=f(s);
        //cout<<pos<<endl;
        int len=s.length();
        for(int i=pos;i<len;i++)
          cout<<s[i];
        for(int i=0;i<pos;i++)
          cout<<s[i];
        cout<<endl;
    }
}                 
                             

    
