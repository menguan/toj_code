#include<iostream>
using namespace std;
int main()
{
	int n; 
	while(cin>>n,n)
	{
		char* Stra=new char[1001]; //这种开字符串的方法还要学习 
		char* Strb=new char[1001];  
		int p=0,m=0;  
		cin>>Stra>>Strb;
		for(int j=0;Strb[j];j++)  
		{
			m*=n;
			m+=Strb[j]-'0';
		}
		for(int i=0;Stra[i];i++)  
		{
			p*=n;
			p+=Stra[i]-'0';

			if(p>=m) 
				p%=m;
		}
		if(!p)
			cout<<0<<endl;
		else
		{
			int pa=0; 
            while(p)  
			{
				Stra[pa++]=p%n+'0';
				p/=n;
			}
			for(pa--;pa>=0;pa--)
				cout<<Stra[pa];
			cout<<endl;
		}

		delete Stra;
		delete Strb;
	}
	return 0;
}
//检查我为啥编译错误的还是顾好自己吧  哈哈