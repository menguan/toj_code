#include<iostream>//网上的递归解法 
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char in[200],a[200];
int pos;
void cal(int &NUM,int &XISHU)
{
	//cout<<NUM<<" "<<XISHU<<endl;//起步时只可能是零 计算都在后面 
    int nowNUM=0,nowXISHU=0,sign=1;
	for(;pos<strlen(in);pos++)
		if(in[pos]>='0'&&in[pos]<='9')
			nowNUM=nowNUM*10+in[pos]-48;
		else if(in[pos]=='x')
		{
			if(nowNUM)
			{
				nowXISHU=nowNUM;
				nowNUM=0;
			}
			else
				nowXISHU=1;
		}
		else if (in[pos]=='(')
		{
			pos++;
			cal(nowNUM,nowXISHU);
			//cout<<NUM<<" "<<XISHU<<endl;
		}
		else if(in[pos]==')')
		{
			nowNUM*=sign;
			NUM+=nowNUM;
			XISHU+=nowXISHU;
			return ;
		}
		else if(in[pos]=='+')
		{	
			NUM+=nowNUM*sign;
			XISHU+=nowXISHU*sign;
			nowXISHU=0;		nowNUM=0;
			sign=1;		
		}
		else if(in[pos]=='-')
		{	
			NUM+=nowNUM*sign;
			XISHU+=nowXISHU*sign;
			nowXISHU=0;		nowNUM=0;
			sign=-1;	
		}
		else if(in[pos]=='*')
		{
			nowNUM*=sign;
			nowXISHU*=sign;
			sign=1;
			pos++;
			for(int nnum=0,nxishu=0;pos<strlen(in)+1;pos++)
				if(in[pos]=='(')
				{
					pos++;
					cal(nnum,nxishu);
				}
				else if(in[pos]>='0'&&in[pos]<='9')
					nnum=nnum*10+in[pos]-48;
				else if(in[pos]=='x')
				{
					nxishu=1;
				}
				else 
				{
					if(nxishu)
						nowXISHU=nowNUM*nxishu;
					else
						nowXISHU=nowXISHU*nnum;
					nowNUM*=nnum;
					pos--;
					break;
				}
		}
		NUM+=nowNUM*sign;
		XISHU+=nowXISHU*sign;
		return ;
}


int main()
{
	int t=0;
	while(cin>>a&&++t)
	{
		int i;
		for(i=0;a[i]!='=';i++)
			in[i]=a[i];
		in[i]='\0';
		int NUM=0,XISHU=0,NUM1=0,XISHU1=0;
		pos=0;
		cal(NUM,XISHU);
		strcpy(in,&a[i+1]);
		pos=0;
		cal(NUM1,XISHU1);
		
		XISHU-=XISHU1;
		NUM1-=NUM;

		if(XISHU==0&&NUM1!=0)
			cout<<"Equation #"<<t<<endl<<"No solution."<<endl<<endl;
		else if(XISHU==0&&NUM1==0)
			cout<<"Equation #"<<t<<endl<<"Infinitely many solutions."<<endl<<endl;
		else 
		{
			printf("Equation #%d\nx = %.6lf\n\n",t,double(NUM1)/double(XISHU));

		}
	}

}
