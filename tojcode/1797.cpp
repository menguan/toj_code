#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[300];
int main()
{   
	char flag;
	while (cin>>s)
	{
		int x=310,y=420;
		int len = strlen(s);
		printf("300 420 moveto\n310 420 lineto\n"); 
		flag='r';
		for(int i=0;i<len;i++)
		{
			switch(flag)
			{
			  case 'r': if(s[i]=='A') {y-=10; flag = 'd';}  else {y+=10; flag='u';}  break;
			  case 'd': if(s[i]=='A') {x-=10; flag = 'l';}  else {x+=10; flag='r';}  break;
			  case 'l': if(s[i]=='A') {y+=10; flag = 'u';}  else {y-=10; flag='d';}  break;
			  case 'u': if(s[i]=='A') {x+=10; flag = 'r';}  else {x-=10; flag='l';}  break;
			}
			printf("%d %d lineto\n",x,y);
		}
		printf("stroke\nshowpage\n");
	}
	
	return 0;
}