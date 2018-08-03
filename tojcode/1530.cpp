#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string key;
string cipher;
char ans[200];
int main()
{
  while(cin>>key)
  { 
    if(key=="THEEND")
      return 0;
    cin>>cipher; 
    int klen=key.length();
    int clen=cipher.length();
    int row=clen/klen;
    int count=0;
    for(int i=65;i<=90;)
    {
      for(int j=0;j<klen;j++)
      {
        if(key[j]==(char)i)
        {
          for(int k=j,l=0;l<row;k+=klen,l++)
            ans[k]=cipher[count++];        
        }
      }
      i++;
    }
    ans[clen]='\0';
    cout<<ans<<endl;        
            
       
      
  }
}     