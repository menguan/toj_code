#include<iostream> //树的修复 以后再来做做看 
#include<cstring> 
using namespace std;
char ans[30],bns[30],cns[30];
void print(int a,int b,int c,int l)
{ int i; if(l<=0)return; 
cns[c+l-1]=ans[a]; 
if(l==1)        
return; 
for(i=b;i<b+l;i++)  
if(ans[a]==bns[i])   //找到根 
break; 
print(a+1,b,c,i-b); 
print(a-b+i+1,i+1,c-b+i,l-i+b-1);}
int main()
{ int i,l;
 while(cin>>ans>>bns) 
 {  l=strlen(ans); 
  print(0,0,0,l);  
  for(i=0;i<l;i++)
  cout<<cns[i];
  cout<<endl; } 
  return 0;}
        
