#include<iostream>//找到第二组名字中 在第一组名字中且不在第三组名字中的 名字 按所给顺序输出 
#include<string>
#include<map>
using namespace std;
map<string,int>s1,s2,s3,s4;
string str[10001];
int main()
{
    int n,m,k;string s;
    while(cin>>n>>m>>k)
    {
        s1.clear();
        s2.clear();
        s3.clear();
        s4.clear();
        for(int i=0;i<n;i++)
        {
            cin>>s;
            s1[s]=1;
        }
        for(int i=0;i<m;i++)
        {
            cin>>s;
            s2[s]=1;
            str[i]=s;
        }
        for(int i=0;i<k;i++)
        {
            cin>>s;
            s3[s]=1;
        }
        int num=0;
        map<string,int>::iterator it;
        map<string,int>::iterator iter1;
        map<string,int>::iterator iter2;
        for(it=s2.begin();it!=s2.end();it++)
        {
            iter1=s1.find(it->first);
            iter2=s3.find(it->first);
            if(iter1!=s1.end()&&iter2==s3.end())
            {
                num++;
                s4[it->first]=1;
            }
        }
        map<string,int>::iterator iter3;
        if(num==0) cout<<"No enemy spy"<<endl;
        else
        {
             bool flag=0;
             for(int i=0;i<m;i++)
             {
                 iter3=s4.find(str[i]);
                 if(iter3!=s4.end())
                 {
                     if(flag) cout<<" ";
                     cout<<str[i];
                     flag=1;
                 }
             }
             cout<<endl;
        }
    }
}
