#include<iostream>  //??????????????????map
#include<string>
#include<map>
#include<stdio.h>
using namespace std;

int main(void)
{
	char english[11],foreign[11];

	map<string,bool>appear;  
	map<string,string>translate;
	while(1)
	{
		char t;  
		if((t=getchar())=='\n')  
			break;
		else     
		{
			english[0]=t;
			int i=1;
			while(1)
			{
				t=getchar();
				if(t==' ')
				{
					english[i]='\0';
					break;
				}
				else
					english[i++]=t;
			}
		}
		cin>>foreign;
		getchar();  
		appear[foreign]=true;
		translate[foreign]=english;
	}
	char word[11];
	while(cin>>word)
	{
		if(appear[word])
			cout<<translate[word]<<endl;
		else
			cout<<"eh"<<endl;
	}
	
	return 0;
}