#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
char be[20];
char now[20];
int jud()
{
	int len1=strlen(be);
	int len2=strlen(now);
	int i;
	for(i=0;i<len1&&i<len2;)
	{
		if(be[i]!=now[i])
		  break;
		i++;  
	}
	return i;
}
		
int main()
{
	memset(be,0,sizeof(be));int sp=0;
	while(gets(now))
	{
		  
		  int ap=jud();
		  if(ap&&sp+1<=ap)
		    sp++;
		  else
		    sp=ap;  
		  for(int i=0;i<sp;i++)
		    printf(" ");
		  puts(now);
		  strcpy(be,now);
	}
}
		  
		
	
