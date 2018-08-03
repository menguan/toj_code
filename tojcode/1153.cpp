#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char s[111111];
int main()
{
    int a;
    cin>>a;
    getchar();
    while(a--)
    {                
        gets(s);        
        int ss=strlen(s);
        int low=0;
        for(int i=0;i<ss;i++)
        {
            if(s[i]==' ')
            {
                
                for(int j=i-1;j>=low;j--)
                {
                    cout<<s[j];
                    
                }
                low=i+1;
                cout<<" ";
                
            }
               
        }            
        for(int j=ss-1;j>=low;j--)
        {
            cout<<s[j];
        }
        cout<<endl;
         
    
    
    
    }
    return 0;
}  