#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

char a[35][5]=
{".-","-...","-.-.","-..",".","..-.","--.",
"....","..",".---","-.-",".-..","--","-.",
"---",".--.","--.-",".-.","...","-","..-",
"...-",".--","-..-","-.--","--..",
"..--",".-.-","---.","----"};
int num[35]=
{2,4,4,3,1,4,3,4,2,4,
3,4,2,2,3,4,4,3,3,1,
3,4,3,4,4,4,4,4,4,4};

char xx[1000];
int c[100];
char temp[1000];
char mark[10];
char ans[1000];

int main()
{
int len,n;
int i,j,l;
int N;

scanf("%d",&n);
N=n;
getchar();
while(n--)
{

gets(xx);
temp[0]='\0';
len=strlen(xx);
for(i=0;i<len;i++)
{
if(xx[i]=='_' || xx[i]=='.' || xx[i]==',' || xx[i]=='?')
c[i]=4;
else
{
c[i]=num[xx[i]-'A'];
}
}

for(i=0;i<len;i++)
{
if(xx[i]=='_')
strcat(temp,a[26]);
else if(xx[i]==',')
strcat(temp,a[27]);
else if(xx[i]=='.')
strcat(temp,a[28]);
else if(xx[i]=='?')
strcat(temp,a[29]);
else
strcat(temp,a[xx[i]-'A']);

}

printf("%d: ",N-n);

int k=0;
for(i=len-1;i>=0;i--)
{
for(j=0;j<c[i];j++)
{
mark[j]=temp[k++];
}

mark[j]='\0';


for(l=0;l<30;l++)
{
if(strcmp(a[l],mark)==0)
{
if(l==26)
printf("_");
else if(l==27)
printf(",");
else if(l==28)
printf(".");
else if(l==29)
printf("?");
else
printf("%c",l+'A');
break;
}
}
}
printf("\n");
}

return 0;
}
