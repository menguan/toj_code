#include<iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
    char a[100];
    char b[100];
    char s[1000];
    int i,j,l1,l2;
    gets(a);
    gets(b);
    puts(b);
    puts(a);

    l2=strlen(a);

    while(gets(s))
    {
        l1=strlen(s);
        for(i=0; i<l1; i++)
        {
            for(j=0;j<l2;j++)
            {
                if(s[i]==a[j])
                {
                    cout<<b[j];
                    break;
                }
            }
            if(j==l2)
            {
                cout<<s[i];
            }
        }
        cout<<endl;
    }
    return 0;
}