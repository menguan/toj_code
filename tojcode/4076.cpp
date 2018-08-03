#include<iostream>
#include<string>
using namespace std;
long long ans=0;string s;
bool is(char c)
{
     
     if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
  return 1;
  else
    return 0;
}    
void f()
{
  int len=s.length();
  int i=0;bool flag;
  if(is(s[0]))
    flag=1;
  else 
  flag=0;  
  
  for(i=1;i<len;i++)
  {
      //cout<<i<<" ";
      //cout<<is(s[i])<<endl;
      if(is(s[i])==1&&flag)
        continue;
      else if(flag&&is(s[i])==0)
      {
           flag=0;
           //cout<<"kk"<<" "<<i<<endl;
        ans++;
        }
      else if(flag==0&&is(s[i])==0)
        continue;
      else if(flag==0&&is(s[i])==1)
      {
           //c/out<<"jj"<<" "<<i<<endl;
           flag=1;
           continue;
           }
    }
    if(flag)
      ans++;
}      
                  
          
        
                  
int main()
{
     
     
     while(cin>>s)
     {
       f();
       }
       cout<<ans<<endl;
       //while(1);
}                      
     
