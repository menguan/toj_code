/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaa                 aaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaa  aaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaa   aaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaa   aaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaa   aaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaa    aaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaa   aaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaa   aaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaa                aaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;
map<char,int>M;
string str[1000];
int num;
int main()
{
    int kk,len,i,j,maxtemp;
    char maxchar;
    kk=0;
    M.clear();
    maxtemp=-1;
    while(getline(cin,str[kk],'\n'))
    {
        len=str[kk].length();
        for(i=0;i<len;i++)
        {
            if((str[kk][i]>='a'&&str[kk][i]<='z')||(str[kk][i]>='A'&&str[kk][i]<='Z'))
            {
                if(M[str[kk][i]]==0)
                {
                    M[str[kk][i]]=1;
                    if(maxtemp<1)
                    {
                        maxtemp=1;
                        maxchar=str[kk][i];
                    }
                }
                else
                {
                    M[str[kk][i]]++;
                    if(maxtemp<M[str[kk][i]])
                    {
                        maxtemp=M[str[kk][i]];
                        maxchar=str[kk][i];
                    }
                }
            }
        }
        kk++;
    }
    int n='i'-maxchar;
    if(n>0&&n>=26)
        n%=26;
    char temp;
    for(i=0;i<kk;i++)
    {
        len=str[i].length();
        for(j=0;j<len;j++)
        {
            if((str[i][j]>='a'&&str[i][j]<='z'))
            {
                if(n>0)
                {
                    for(int kkk=0;kkk<n;kkk++)
                    {
                        str[i][j]++;
                        if(str[i][j]>'z')
                            str[i][j]='a';
                    }
                }
                else
                {
                    temp=str[i][j]+n;
                    if(temp<'a')
                    temp=temp-'a'+'z'+1;
                    str[i][j]=temp;
                }
                
            }
            else if(str[i][j]>='A'&&str[i][j]<='Z')
            {
                    temp=str[i][j]+n;
                    if(temp>'Z')
                    {
                        temp=temp-'Z'+'A'-1;
                    }
                    else if(temp<'A')
                        temp=temp-'A'+'Z'+1;
                    str[i][j]=temp;
            }
        }
    }
    for(i=0;i<kk;i++)
    {
        cout<<str[i]<<endl;
    }
    //while(1);
}
