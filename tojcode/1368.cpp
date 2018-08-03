#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    char a[70]={' ','2','3','4','5','6','7','8','9','0','-','=','W','E','R','T','Y','U','I','O','P','[',']','\\','S','D','F','G','H','J','K','L',';','\'','X','C','V','B','N','M',',','.','/'};
    char b[70]={' ','1','2','3','4','5','6','7','8','9','0','-','Q','W','E','R','T','Y','U','I','O','P','[',']','A','S','D','F','G','H','J','K','L',';','Z','X','C','V','B','N','M',',','.'};
    char s[100];
    while(gets(s))
    {
        for(int i=0;i<strlen(s);i++)
        {
            for(int j=0;j<43;j++)
            {
                if(a[j]==s[i])
                cout<<b[j];
            }
        }
        cout<<endl;
    }
    
    return 0;
}      