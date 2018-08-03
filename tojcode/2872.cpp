#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int main()
{
	while(cin>>s1)
	{
		if(s1[0]=='#')
			break;
		cin>>s2;int count =0;
		int n = s1.length();
		for(int i=0;i<n;i++)
		{
			if(s1[i] < s2[i] && s1[i]!='?')
			{
				break;
			}
			if(s1[i]=='?')
			{
				int buff = '9' - s2[i];
				for(int j=i+1;j!=n;j++)
					if(s1[j]=='?')
						buff*=10;
				count+=buff;
				//cout<<buff<<endl;
			//	break;
			}
			if(s1[i]==s2[i])
				continue;
			if(s1[i]>s2[i]&&s1[i]!='?')
			{
				int buff = 1;
				for(int j=i+1;j!=n;j++)
				{
					if(s1[j]=='?')
						buff*=10;
				}
				count+=buff;
				//cout<<buff<<" kk"<<endl;
				break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}