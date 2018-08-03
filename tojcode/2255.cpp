#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib> 
using namespace std;
int main()

{

   int cases,n,press,wait;

   long long num;

   char str[1001];

   cin>>cases;

   while(cases--)

   {

       cin>>press>>wait;            

       getchar();

       gets(str);

       num=0;

       int len=strlen(str); 

       for(int i=0;i<len;i++)

      {

       if(str[i]=='A'||str[i]=='D'||str[i]=='G'||str[i]=='J'||str[i]=='M'||str[i]=='P'||str[i]=='T'||str[i]=='W'||str[i]==' ')

       {num+=press;continue;}

       if(str[i]=='B'||str[i]=='E'||str[i]=='H'||str[i]=='K'||str[i]=='N'||str[i]=='Q'||str[i]=='U'||str[i]=='X')

       {num+=2*press;continue;}

       if(str[i]=='S'||str[i]=='Z')

       {num+=4*press;continue;}

       num+=3*press;

      }

      

      for(int i=0;i<len-1;i++)

      {

         if((str[i]=='A'||str[i]=='B'||str[i]=='C')&&(str[i+1]=='A'||str[i+1]=='B'||str[i+1]=='C'))              

         num+=wait; 

         if((str[i]=='D'||str[i]=='E'||str[i]=='F')&&(str[i+1]=='D'||str[i+1]=='E'||str[i+1]=='F'))              

         num+=wait; 

         if((str[i]=='G'||str[i]=='H'||str[i]=='I')&&(str[i+1]=='G'||str[i+1]=='H'||str[i+1]=='I'))              

         num+=wait; 

         if((str[i]=='J'||str[i]=='K'||str[i]=='L')&&(str[i+1]=='J'||str[i+1]=='K'||str[i+1]=='L'))              

         num+=wait; 

         if((str[i]=='M'||str[i]=='N'||str[i]=='O')&&(str[i+1]=='M'||str[i+1]=='N'||str[i+1]=='O'))              

         num+=wait; 

          if((str[i]=='P'||str[i]=='Q'||str[i]=='R'||str[i]=='S')&&(str[i+1]=='P'||str[i+1]=='Q'||str[i+1]=='R'||str[i+1]=='S'))              

         num+=wait;

          if((str[i]=='T'||str[i]=='U'||str[i]=='V')&&(str[i+1]=='T'||str[i+1]=='U'||str[i+1]=='V'))              

         num+=wait;

          if((str[i]=='W'||str[i]=='X'||str[i]=='Y'||str[i]=='Z')&&(str[i+1]=='W'||str[i+1]=='X'||str[i+1]=='Y'||str[i+1]=='Z'))              

         num+=wait;

      }  

      cout<<num<<endl;             

   } 

   return 0;   

}
