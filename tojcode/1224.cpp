#include<iostream>
#include<cstring>
using  namespace std;
char word[100];
int main()
{
	int now=0;
	while(cin>>word)
	{
		int len=strlen(word);
		if(strcmp(word,"<br>")==0)
		{  cout<<endl;now=0;
	    }
		else if(strcmp(word,"<hr>")==0)
		{
			if(now)
			cout<<endl;
			for(int i=0;i<80;i++)
			  cout<<"-";
		    cout<<endl;
			now=0;
		}
		else{
			  
			    
		if(now+len+1<=80)
		{
		  if(now)  cout<<" ";
		  now=now+len+1;	
		  cout<<word;
		
		}
		
		  else
		  {
			cout<<endl;
			cout<<word;
			now=len;
		  }	
			 		
	    }
	}
	cout<<endl;
}  
		    
		  
		
