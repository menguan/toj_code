#include<iostream>
#include<string>
using namespace std;
bool letter(char a)
{
    if(a=='a'||a=='b'||a=='c'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='j'||a=='k'||a=='l'||a=='m'||a=='n'||a=='o'||a=='p'||a=='q'||a=='r'||a=='s'||a=='t'||a=='u'||a=='v'||a=='w'||a=='x'||a=='y'||a=='z'||a=='A'||a=='Q'||a=='Z'||a=='W'||a=='S'||a=='X'||a=='C'||a=='D'||a=='E'||a=='V'||a=='F'||a=='R'||a=='B'||a=='G'||a=='T'||a=='N'||a=='H'||a=='Y'||a=='M'||a=='J'||a=='U'||a=='K'||a=='I'||a=='L'||a=='O'||a=='P')
      return 1;
    else
      return 0;
    
}
bool number(char a)
{
    if(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9'||a=='0')
      return 1;
    else 
      return 0;
        
}    
int f(string s)
{
   int l=s.length();
   if(l==15||l==18)
   {
       for(int i=0;i<l;i++)
       {
           if(i!=l-1&&s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9'&&s[i]!='0')
               goto cc;
           else if(i==l-1&&s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9'&&s[i]!='0'&&s[i]!='X')
               goto cc;
       }
       cout<<"This is the cardID."<<endl;
       return 0;  
  }             
  cc:;
  if(l>=5&&l<=16)
  {
      if(letter(s[0])==1)
      {
          for(int i=1;i<l;i++)
          {
              if(letter(s[i])==0&&number(s[i])==0)
                  goto dd;
          }
          cout<<"This is a username."<<endl;
          return 0;
      }
  }
  dd:;
  bool mail1=0;
  bool mail2=0;
  bool t1=0;
  bool t2=0;
  for(int i=0;i<l;)
  {
      i++;
      if(s[i]=='@'&&mail1==1)
         goto ee;
      if(s[i]=='.'&&mail2==1)
         goto ee;    
      if(mail1==1&&i<l-1&&s[i]=='.')
          mail2=1;
      
      if(s[i]=='@')
      {
          mail1=1;
          i++;
      }
      
      
  }
  
  if(mail1==1&&mail2==1)
  {
      for(int i=0;i<l;i++)
      {
          if(s[i]=='@'&&t1==1)
            goto ee;
          if(s[i]=='.'&&t2==1)
            goto ee;       
          if(letter(s[i])==0&&number(s[i])==0&&s[i]!='@'&&s[i]!='.')
            goto ee;
          if(s[i]=='@')
          t1=1;
          if(s[i]=='.')
          t2=1;
            
      }
      cout<<"This is an Email."<<endl;
      return 0;
  }    
          
  ee:;
  cout<<"This is the wrong input."<<endl;
  return 0;
}
int main()
{
    string s;
    while(cin>>s)
    {
        f(s);
    }
    return 0;
}  