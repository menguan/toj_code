#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int a[2300][13][32];//0 re 
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool f(int y)
{
	if((y%4==0&&y%100!=0)||(y%400==0))
	  return 1;
	else
	  return 0;
}  
char kk[4][30];
int main()
{
	strcpy(kk[0],"Resting");
	strcpy(kk[1],"7:00-11:00, 18:30-23:00");
	strcpy(kk[2],"16:00-23:00");
	strcpy(kk[3],"11:30-23:00");
	int we=6;int now=0; 
	a[2010][2][27]=now;
	for(int y=2010;y<2202;y++)
	{
		for(int m=1;m<=12;m++)
		{
			if(y==2010&&m==1)
			  continue;
			for(int d=1;d<=((f(y)&&m==2)?(day[m]+1):day[m]);d++)
			{
				if(y==2010&&m==2&&d<=27)
				  continue;
				we=(we+1)%7;
				now=(now+1)%3;
				if(we==2&&now==2)  
				  a[y][m][d]=3;
				else
				  a[y][m][d]=now;
		    }
		}
	}int y,m,d;
	while(scanf("%d/%d/%d",	&y,&m,&d)!=-1)
	{
		    cout<<kk[a[y][m][d]]<<endl;
	}
}  
				
	
	
