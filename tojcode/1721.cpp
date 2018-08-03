/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <stdio.h>
using namespace std;
map<string,int>M;
bool mark[8];
int a,b,c;
int main()
{
    M["Anne"]=1;
    M["Bob"]=2;
    M["Karin"]=3;
    M["Charly"]=4;
    M["Dave"]=5;
    M["Edward"]=6;
    M["Frank"]=7;
    int t,len,i,zz=1;
    cin>>t;
    getchar();
    string str,temp;
    while(t--)
    {
        getline(cin,str,'\n');
        len=str.length();
        str+=' ';
        int starti=0;
        for(i=1;i<=7;i++)
            mark[i]=false;
        for(i=0;i<=len;i++)
        {
            if(str[i]==' ')
            {
                temp=str.substr(starti,i-starti);
                starti=i+1;
                mark[M[temp]]=true;
            }
        }
        a=0;
        b=0;
        c=0;
        if(mark[1])
        {
            a++;
        }
        if(mark[2])
        {
            if(mark[3]&&!mark[5]&&!mark[6]&&mark[1])
                b++;
            else if(!mark[3]&&(mark[5]||mark[6]||!mark[1]))
                c++;
        }
        if(mark[3])
        {
            if(mark[4])
                b++;
            else if(!mark[4]&&mark[1])
                a++;
            else if(!mark[1]&&!mark[4])
                c++;
        }
        if(mark[4])
        {
            if(mark[1])
                a++;
        }
        if(mark[6])
        {
            if(mark[1]&&!mark[4])
                c++;
            else
                a++;
        }
        if(mark[7])
        {
            if(!mark[1]&&!mark[2])
                a++;
            else if(mark[1])
                b++;
        }
        printf("Scenario #%d:\n",zz++);
         if(a>b&&a>c)
        {
            printf("cinema\n");
        }
        else if(b>c&&b>a)
        {
            printf("disco\n");     
        }
        else if(c>a&&c>b)
        {
            printf("cocktail bar\n");
        }
        else
            printf("stay at the Hacienda\n");
        printf("\n");
    }
    return 0;
}
