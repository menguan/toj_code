#include <cstdio>//对此代码不予置评
#include <cstring>
#include <algorithm>
using namespace std;
char str0[105][100];
int str1[105];
bool types[205];
int l0;
int num0,num1;

bool cmp(char *a,char *b)
{
    int i;
    for(i=0; i<strlen(a); i++)
        if(a[i]>='A'&&a[i]<='Z') a[i]=a[i]+32;
    for(i=0; i<strlen(b); i++)
        if(b[i]>='A'&&b[i]<='Z') b[i]=b[i]+32;
    if(strcmp(a,b)>0) return 1;
    else return 0;
}
void strsort()
{
    int i,j;
    for(i=0;i<num0;i++)
        for(j=0;j<num0;j++)
        {
            char b1[1000],b2[1000];
            strcpy(b1,str0[i]);
            strcpy(b2,str0[j]);
            if(!cmp(b1,b2))
            {
                char t[1000];
                strcpy(t,str0[i]);
                strcpy(str0[i],str0[j]);
                strcpy(str0[j],t);
            }
        }
}
int main()
{
    while(1)
    {
        num0=0;
        num1=0;
        memset(types,0,sizeof(types));
        char temp[100];
        int i=0;
        while(1)
        {
            scanf("%s",temp);

            if((temp[0]>='0'&&temp[0]<='9')||temp[0]=='-')
            {
                types[i]=1;
                str1[num1++]=atoi(temp);
            }
            else
            {
                types[i]=0;
                strcpy(str0[num0++],temp);
            }
            i++;
            int l=strlen(temp);
            if((temp[l-1])=='.')break;
        }
        if(strcmp(temp,".")==0)break;
        strsort();
        sort(str1,str1+num1);
        int counter0=0;
        int counter1=0;
        for(int i=0;; i++)
        {
            if(types[i]==0)
            {
                if(counter0==num0)continue;
                str0[counter0][strlen(str0[counter0])-1]='\0';
                printf("%s",str0[counter0++]);
            }
            else
            {
                if(counter1==num1)continue;
                printf("%d",str1[counter1++]);
            }
            if(counter0==num0&&counter1==num1)
            {
                puts(".");
                break;
            }
            printf(", ");
        }
    }
    return 0;
}
