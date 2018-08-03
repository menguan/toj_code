#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef struct{
	char name[20];
 	int age;
}Name;
typedef struct{
	char father[20];
 	char son[20];
  	int fage;
}Origin;
typedef map<string,int>record;
int n,k,i,j,len,x;
string a,b;
bool cmp(const Name& a,const Name& b)
{	
    if(a.age>b.age)return true;
	if(a.age==b.age&&strcmp(a.name,b.name)<0)return true;
 	return false;
}int main()
{	
    cin>>n;
   	for(i=1;i<=n;i++){
    		cin>>x;
      		record re;
    		string s="Ted";
      		re[s]=100;
    		len=0;
      		Origin ori[100];
    		Name name[100];
      		for(j=0;j<x;j++)
            {		
            	cin>>ori[j].father>>ori[j].son>>ori[j].fage;
         		if(re[ori[j].father]&&!re[ori[j].son])
                {			
                	re[ori[j].son]=re[ori[j].father]-ori[j].fage;		
             		len++;	
           		}		
            }		
            while(len<x)
            {			
                for(j=0;j<x&&len<x;j++)
                {		
            	   if(re[ori[j].father]&&!re[ori[j].son])
                   {			
                    	re[ori[j].son]=re[ori[j].father]-ori[j].fage;	
             			len++;		
            	   }		 
                }		
            }		
            for(j=0;j<x;j++)
            {		
            	strcpy(name[j].name,ori[j].son);	
         		name[j].age=re[ori[j].son];		
            }		
            sort(name,name+x,cmp);
    		cout<<"DATASET "<<i<<endl;	
      	    for(j=0;j<x;j++)
              cout<<name[j].name<<" "<<name[j].age<<endl;
     	}	
}