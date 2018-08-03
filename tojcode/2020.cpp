#include<iostream>
#include<string>
using namespace std;
bool f(char a,char b)
{
   if((a=='E'&&b=='3')||(a=='3'&&b=='E'))
     return 1;
   else if((a=='H'&&b=='H')||(a=='H'&&b=='H')) 
     return 1;
   else if((a=='A'&&b=='A')||(a=='A'&&b=='A')) 
     return 1;
     else if((a=='I'&&b=='I')||(a=='I'&&b=='I')) 
     return 1;
     else if((a=='L'&&b=='I')||(a=='I'&&b=='L')) 
     return 1;
     else if((a=='M'&&b=='M')||(a=='M'&&b=='M')) 
     return 1;
     else if((a=='O'&&b=='O')||(a=='O'&&b=='O')) 
     return 1;
     else if((a=='S'&&b=='2')||(a=='2'&&b=='S')) 
     return 1;
     else if((a=='T'&&b=='T')||(a=='T'&&b=='T')) 
     return 1;
     else if((a=='U'&&b=='U')||(a=='U'&&b=='U')) 
     return 1;
     else if((a=='V'&&b=='V')||(a=='V'&&b=='V')) 
     return 1;
     else if((a=='W'&&b=='W')||(a=='W'&&b=='W')) 
     return 1;
     else if((a=='X'&&b=='X')||(a=='X'&&b=='X')) 
     return 1;
     else if((a=='Y'&&b=='Y')||(a=='Y'&&b=='Y')) 
     return 1;
     else if((a=='Z'&&b=='5')||(a=='5'&&b=='Z')) 
     return 1;
     else if((a=='1'&&b=='1')||(a=='1'&&b=='1')) 
     return 1;
     else if((a=='8'&&b=='8')||(a=='8'&&b=='8')) 
     return 1;
     else 
     return 0;
}      
     
int main()
{
   string s;
   while(cin>>s)
   {
     bool mi=0,pa=0;
     int len=s.length();
     int i;
     for(i=0;i<=len/2;i++)
     {
       if(s[i]!=s[len-i-1])
         break;
     }
     if(i==len/2+1)
       pa=1;
       
     for(i=0;i<=len/2;i++)
     {
       if(!f(s[i],s[len-i-1]))
         break;
     } 
     if(i==len/2+1)
       mi=1;
     if(pa&&mi==0)
       cout<<s<<" -- is a regular palindrome."<<endl;
     else if(pa==0&&mi)
       cout<<s<<" -- is a mirrored string."<<endl;
     else if(pa&&mi)
       cout<<s<<" -- is a mirrored palindrome."<<endl;
     else
       cout<<s<<" -- is not a palindrome."<<endl;
   cout<<endl;}
}   