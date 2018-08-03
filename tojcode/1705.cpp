#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int t;int n;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
            
            cin>>n;
            map<string,int>q;
            q.clear();
            map<string,string>con;
            map<string,int> flag;
            string s1,s2;
            for(int i=1;i<n;i++)
            {
                   cin>>s1>>s2;
                   flag[s1]++;flag[s2]++;;
                   con[s1]=s2;
                   q[s2]++;
            }
            
            vector<string> a;
            map<string,int>::iterator iter;
            for(iter=flag.begin();iter!=flag.end();iter++)
            {
                if(iter->second==1&&q[(string)iter->first]!=1)
                  {q[iter->first]==0;break;
                  }
                  }
                  
                                                          
            for(int i=0;i<n;i++)
            {
               for(iter=q.begin();iter!=q.end();iter++)
               {//cout<<iter->second<<endl;
                  if(iter->second==0)
                  {
                     iter->second=-1;
                     
                     a.push_back(iter->first);
                     q[con[iter->first]]--;
                  }
               }
            }//system("pause");
            cout<<"Scenario #"<<j<<":"<<endl;
            for(int i=0;i<n;i++)
            {
              cout<<a[i]<<endl;
              }
            cout<<endl;
    }
}    
                
              
                                                                     
                   
                       
