#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
char s1[5],s2[5];
int hash[100];

int main()
{
    int i,j,cas = 1;
    while(scanf("%d",&n),n)
    {
        memset(hash,0,sizeof(hash));
        hash[0] = 1;
        for(i = 0;i<n;i++)
        {
            scanf("%s = %s",s1,s2);
            if(hash[s2[0]-'a'])
            hash[s1[0]-'a'] = 1;
            else
            hash[s1[0]-'a'] = 0;
        }
        printf("Program #%d\n",cas++);
        int flag = 1;
        for(i = 0;i<26;i++)
        {
            if(hash[i])
            {
            printf("%c ",i+'a');
            flag = 0;
            }
        }
        if(flag)
        printf("none");
        printf("\n\n");
    }

    return 0;
}
