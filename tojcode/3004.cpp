#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
char s[1111];
int main()
{
    int a,count=1;
    cin>>a;
    while(a--)
    {
        int b;
        
        cin>>b;
        getchar();
        gets(s);        
        cout<<count<<" ";
        for(int i=0;i<strlen(s);i++)
        {
            
            if(i>=b-1)
            s[i]=s[i+1];
            
        }
        for(int i=0;i<strlen(s);i++)
        {
            
            cout<<s[i];
            
        }
        cout<<endl;
        count++;
    }
    return 0;
}