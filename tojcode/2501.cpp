#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a;    
    int b[81];
    cin>>a;
    while(a--)
    {
        string s;
        long sum=0;
        cin>>s;
        
        for(int i=0;i<s.length();i++)
        {   
            if(i>0&&(s[i-1]=='O'&&s[i]=='O'))
            b[i]=b[i-1]+1;
            else if(s[i]=='O')
            b[i]=1;
            else if(s[i]=='X')
            b[i]=0;
        }
        
        for(int i=0;i<s.length();i++)
        {
         sum+=b[i];
        }
        cout<<sum<<endl;  
    }
    return 0;    
} 