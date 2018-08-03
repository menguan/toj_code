#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[60];
char ans[60];
char temp[60];
bool cmp()
{
  for(int i=0;i<strlen(temp);i++)
  {
    if(temp[i]<ans[i])
      return 1;
    else if(temp[i]==ans[i])  
      continue;
    else if(temp[i]>ans[i])
      return 0;
  }
  return 1;
}  
      
  
int main()
{
  cin>>a;
  int len =strlen(a);
  reverse(a+0,a+1);
  reverse(a+1,a+2);
  reverse(a+2,a+len);
  strcpy(temp,a);
  strcpy(ans,temp);
  reverse(a+0,a+1);
  reverse(a+1,a+2);
  reverse(a+2,a+len);
  for(int i=0;i<len-2;i++)
  {
    for(int j=1;i+j+1<len;j++)
    {
        reverse(a,a+i+1);
        reverse(a+i+1,a+i+1+j);
        reverse(a+i+1+j,a+len);
        
        strcpy(temp,a);
        //cout<<i<<" "<<j<<" ";
        //cout<<temp<<endl;
        if(cmp())
        {
          strcpy(ans,temp);
        }
        reverse(a,a+i+1);
        reverse(a+i+1,a+i+1+j);
        reverse(a+i+1+j,a+len);
    }
  }
  cout<<ans<<endl;
  //while(1);
}           
          
        