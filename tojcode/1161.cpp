#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map[]="22233344455566677778889999";
char str[80],telNumber[100000][9];
int compare(const void *p1,const void *p2)
{
    return(strcmp((char*)p1,(char*)p2));
}
void standardizeTel(int n)
{
    int j,k;
    k=-1;j=-1;
    while(k<8)
    {
    j++;
    if(str[j]=='-') continue;
    k++;
    if(k==3){telNumber[n][k]='-';k++;}
        if(str[j]>='A'&&str[j]<='Z'){telNumber[n][k]=map[str[j]-'A'];continue;}
    telNumber[n][k]=str[j];
    }
         telNumber[n][8]='\0';
     return;

}
int main()
{
    int n,i,j;
    bool noduplicate;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        standardizeTel(i); 
    }
    qsort(telNumber,n,9,compare);
    noduplicate=true;
    i=0;
    while(i<n)
    {
        j=i;
        i++;
        while((i<n)&&strcmp(telNumber[i],telNumber[j])==0)i++;
        if(i-j>1)
       {
            printf("%s %d\n",telNumber[j],i-j);
            noduplicate=false;
        }
    }
        if(noduplicate==true)
            printf("No duplicates.\n");              
}
