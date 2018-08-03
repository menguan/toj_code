#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int f(char a)
{
    if(a=='A')
    return 1;
    if(a=='B')
    return 2;
    if(a=='C')
    return 3;
    if(a=='D')
    return 4;
    if(a=='E')
    return 5;
    if(a=='F')
    return 6;
    if(a=='G')
    return 7;
    if(a=='H')
    return 8;
    if(a=='I')
    return 9;
    if(a=='J')
    return 10;
    if(a=='K')
    return 11;
    if(a=='L')
    return 12;
    if(a=='M')
    return 13;
    if(a=='N')
    return 14;
    if(a=='O')
    return 15;
    if(a=='P')
    return 16;
    if(a=='Q')
    return 17;
    if(a=='R')
    return 18;
    if(a=='S')
    return 19;
    if(a=='T')
    return 20;
    if(a=='U')
    return 21;
    if(a=='V')
    return 22;
    if(a=='W')
    return 23;
    if(a=='X')
    return 24;
    if(a=='Y')
    return 25;
    if(a=='Z')
    return 26;
}    
int main()
{
    char a[300];
    
    while(gets(a))
    {
        
         
        if(a[0]=='#')
          return 0;
        int sum=0;  
        int l=strlen(a);
        for(int i=0,j=1;i<l;j++,i++)
        {
            if(a[i]==' ')
              sum+=0;
            else
            {
              
              sum+=f(a[i])*j;
            }  
        }
        cout<<sum<<endl;
    }
    return 0;
}   