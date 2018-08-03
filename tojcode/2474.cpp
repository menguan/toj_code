#include<iostream>
#include<cstring>
#include<ctype.h>
#include<vector>
#include<algorithm>
using namespace std;
char s[120];
//int k,a,n,c,e;
//int p,q,r,s,t;
int main()
{
     while(cin>>s)
     {
         if(strcmp(s,"0")==0)
            return 0;
         int len=strlen(s);
         //k=a=n=c=e=p=q=r=s=t=0;
         vector<char> le;
         vector<char> op;
         le.clear();
         op.clear();
         int n=0;
         for(int i=0;i<len;i++)
         {

               if(s[i]=='p'||s[i]=='q'||s[i]=='r'||s[i]=='s'||s[i]=='t')
               le.push_back(s[i]);

             else

                 if(s[i]=='N')
                    n++;
                 else if(s[i]=='K'||s[i]=='A'||s[i]=='C'||s[i]=='E')
                    op.push_back(s[i]);

         }
         if(le.size()==0)
         {


          cout<<"no WFF possible"<<endl;
           continue;
         }
         int d=min(le.size()-1,op.size());
         while(n--)cout<<"N";
         for(int i=0;i<d;i++)
              cout<<op[i];
         for(int i=0;i<=d;i++)
         {

             cout<<le[i];
         }
         cout<<endl;
     }
}

}
