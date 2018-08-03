#include<cstdio>
#include<cstring>
int main()
{
    char str[600];
    char p[3][200];
    while(gets(str))
    {
        if(strcmp(str,"e/o/i")==0)
            break;
        sscanf(str,"%[^/]/%[^/]/%[^/]",p[0],p[1],p[2]);
        int len[3];
        for(int i=0;i<3;i++)
            len[i]=strlen(p[i]);
        int n[3];
        for(int i=0;i<3;i++)
        {
            n[i]=0;
            for(int j=0;j<len[i];j++)
            {
                if(p[i][j]=='a'||p[i][j]=='e'||p[i][j]=='i'||p[i][j]=='o'||p[i][j]=='u'||p[i][j]=='y')
                {
                    if(j-1>=0)
                       if(p[i][j-1]=='a'||p[i][j-1]=='e'||p[i][j-1]=='i'||p[i][j-1]=='o'||p[i][j-1]=='u'||p[i][j-1]=='y')
                            continue;
                    n[i]++;
                }

            }
        }
        if(n[0]==5&&n[1]==7&&n[2]==5)
            printf("Y\n");
        else
        {
            if(n[0]!=5)
            {
                printf("1");
            }
            else if(n[1]!=7)
            {
                printf("2");
            }
            else if(n[2]!=5)
            {
                printf("3");
            }
            printf("\n");
        }
    }
    return 0 ;
}

