#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        string s;
        cin>>s;
        int sum=0;
        int l=s.length();
        for(int i=0;i<l;i++)
        {
            sum+=s[i]-'0';
        }
        cout<<sum<<endl;
    }
    return 0;
} 