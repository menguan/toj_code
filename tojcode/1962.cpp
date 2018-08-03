#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
	while(cin>>s&&s!="0")
	{
		int i=2;
		long double sum=0;
		if(s.length()>=32)
		{
			cout<<2147483647<<endl;
			continue;
		} 
		for(int j=s.length()-1;j>=0;j--)
		{
			sum+=(s[j]-'0')*(i-1);
			i*=2;
		}
		if(sum>2147483647)
			cout<<2147483647<<endl;
		else
			cout<<(int)sum<<endl;
	}
	return 0;
}