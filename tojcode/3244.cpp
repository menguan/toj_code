#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t;bool flag;
	int hh,mm;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d/%d",&hh,&mm);
		int temp=2*hh/mm;//t2只可能为1 2  所以直接乘2 处理 
		flag = 0;
		for(int hour=0;hour<12;hour++)
		{	
            for(int minute=0;minute<60;minute++)
			{
				int deg=abs(60*hour-11*minute);
				if(deg>360)deg=720-deg;//锐角 
				if(temp==deg)
				{
					if(flag)printf(" ");
					printf("%02d:%02d",hour,minute);
					flag=1;
				}
			}
        }	
		puts("");
	}
} 
