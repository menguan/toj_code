#include<iostream>
#include<string>
using namespace std;
void f(char a)
{
	char t1[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char t2[26]={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
    for(int i=0;i<26;i++)
    {
	    if(a==t2[i])
	        cout<<t1[i];
    }
}        
int main()
{
    int a;
	cin>>a;
	string s;
	int count=1;
	while(a--)
	{
	    cin>>s;
	    int len=s.length();
	    cout<<"String #"<<count<<endl;
	    count++;
	    for(int i=0;i<len;i++)
	    {
			f(s[i]);
	    }
		cout<<endl<<endl;
    }
    return 0;
}    
