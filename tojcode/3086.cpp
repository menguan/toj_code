#include<iostream>
#include<cstring>
using namespace std;
char a[120];
int len;int ans;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       cin>>a;       
       len=strlen(a);
       ans=0;
       int pos;
       for(pos=0;pos<len;pos++)
       {
          if(a[pos]=='M')
            ans+=1000;
          else
            break;
       }
       bool hyaku=1;
       if(a[pos]!='C'&&a[pos]!='D'&&pos<len)
         hyaku=0;
       if(hyaku)
       {
          
             if(a[pos]=='D'&&a[pos+1]=='C' &&a[pos+2]=='C'&&a[pos+3]=='C')
             {ans+=800,pos+=4;}
             else if(a[pos]=='C'&&a[pos+1]=='C' &&a[pos+2]=='C')
             {ans+=300,pos+=3;}
             else if(a[pos]=='D'&&a[pos+1]=='C' &&a[pos+2]=='C')
             {ans+=700,pos+=3;}                                                               
             else if(a[pos]=='D'&&a[pos+1]=='C')
             {ans+=600,pos+=2;}
             else if(a[pos]=='C'&&a[pos+1]=='D' )
             {ans+=400,pos+=2;}
             else if(a[pos]=='C'&&a[pos+1]=='M' )
             {ans+=900,pos+=2;}
             else if(a[pos]=='C'&&a[pos+1]=='C' )
             {ans+=200,pos+=2;}
             else if(a[pos]=='C')
             {ans+=100,pos+=1;}
             else if(a[pos]=='D')
             {ans+=500,pos+=1;}
       }
       bool jiu=1;
       if(a[pos]!='X'&&a[pos]!='L'&&pos<len)
         jiu=0;
       if(jiu)
       {
          
             if(a[pos]=='L'&&a[pos+1]=='X' &&a[pos+2]=='X'&&a[pos+3]=='X')
             {ans+=80,pos+=4;}
             else if(a[pos]=='X'&&a[pos+1]=='X' &&a[pos+2]=='X')
             {ans+=30,pos+=3;}
             else if(a[pos]=='L'&&a[pos+1]=='X' &&a[pos+2]=='X')
             {ans+=70,pos+=3;}                                                               
             else if(a[pos]=='L'&&a[pos+1]=='X')
             {ans+=60,pos+=2;}
             else if(a[pos]=='X'&&a[pos+1]=='L' )
             {ans+=40,pos+=2;}
             else if(a[pos]=='X'&&a[pos+1]=='C' )
             {ans+=90,pos+=2;}
             else if(a[pos]=='X'&&a[pos+1]=='X' )
             {ans+=20,pos+=2;}
             else if(a[pos]=='X')
             {ans+=10,pos+=1;}
             else if(a[pos]=='L')
             {ans+=50,pos+=1;}
       }
       bool YIJI=1;
       if(a[pos]!='I'&&a[pos]!='V'&&pos<len)
         YIJI=0;
       if(YIJI)
       {
          
             if(a[pos]=='V'&&a[pos+1]=='I' &&a[pos+2]=='I'&&a[pos+3]=='I')
             {ans+=8,pos+=4;}
             else if(a[pos]=='I'&&a[pos+1]=='I' &&a[pos+2]=='I')
             {ans+=3,pos+=3;}
             else if(a[pos]=='V'&&a[pos+1]=='I' &&a[pos+2]=='I')
             {ans+=7,pos+=3;}                                                               
             else if(a[pos]=='V'&&a[pos+1]=='I')
             {ans+=6,pos+=2;}
             else if(a[pos]=='I'&&a[pos+1]=='V' )
             {ans+=4,pos+=2;}
             else if(a[pos]=='I'&&a[pos+1]=='X' )
             {ans+=9,pos+=2;}
             else if(a[pos]=='I'&&a[pos+1]=='I' )
             {ans+=2,pos+=2;}
             else if(a[pos]=='I')
             {ans+=1,pos+=1;}
             else if(a[pos]=='V')
             {ans+=5,pos+=1;}
       }
       cout<<ans<<endl;
    }
}  
