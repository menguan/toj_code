#include<stdio.h>
#include<string.h>
char str[1000];
int start[1000],ans[1000],res[10000];
int oldbase,newbase;
void change()
{
    int i,len=strlen(str);
    start[0]=len;
    for(i=1;i<=len;i++)
    {
        if(str[i-1]>='0'&&str[i-1]<='9')
            start[i]=str[i-1]-'0';
        else if(str[i-1]>='a'&&str[i-1]<='z')
            start[i]=str[i-1]-'a'+36;
        else
            start[i]=str[i-1]-'A'+10;
    }
}
void solve()
{
    memset(res,0,sizeof(res));
    int y,i,j;
    
    while(start[0]>=1)
    {
        y=0;i=1;
        ans[0]=start[0];
        while(i<=start[0])
        {
            y=y*oldbase+start[i];
            ans[i++]=y/newbase;
            y%=newbase;
        }
        res[++res[0]]=y;
        i=1;
        while((i<=ans[0])&&(ans[i]==0)) i++;
        memset(start,0,sizeof(start));
        for(j=i;j<=ans[0];j++)
            start[++start[0]]=ans[j];
        memset(ans,0,sizeof(ans));
    }
}
void output()
{
    printf("%d %s\n%d ",oldbase,str,newbase);
    int i;
    for(i=res[0];i>=1;i--)
    {
        if(res[i]>=0&&res[i]<=9)
            printf("%d",res[i]);
        else if(res[i]>=10&&res[i]<=35)
            printf("%c",'A'+res[i]-10);
        else printf("%c",'a'+res[i]-36);
    }
    printf("\n\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%s",&oldbase,&newbase,str);
        change();
        solve();
        output();
    }
    return 0;
}