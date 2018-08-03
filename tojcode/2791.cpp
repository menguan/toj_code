#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        string s;
        for(int i=1;i<=a;i++)
        {
            cin>>s;
            if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')   
            {
                cout<<s<<"cow"<<endl;
            }
            else
            {
                int k=s.length();
                char f=s[0];
                for(int j=0;j<k-1;j++)
                {
                    s[j]=s[j+1];
                }
                s[k-1]=f;    
                cout<<s<<"ow"<<endl;
            }
        }
    }    
    return 0;
}