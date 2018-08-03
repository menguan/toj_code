#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
//int d[200][100];//带1 
//int p[200][100];//不带1 
int ans[101]={0,0,0,1,1,2,3,4,5,7,9,11,14,17,21,26,31,37,45,53,63,75,88,103,121,141,164,191,221,255,295,339,389,447,511,584,667,759,863,981,1112,1259,1425,1609,1815,2047,2303,2589,2909,3263,3657,4096,4581,5119,5717,6377,7107,7916,8807,9791,10879,12075,13393,14847,16443,18199,20131,22249,24575,27129,29926,32991,36351,40025,44045,48445,53249,58498,64233,70487,77311,84755,92863,101697,111321,121791,133183,145577,159045,173681,189585,206847,225584,245919,267967,291873,317787,345855,376255,409173,444792};
bool vis[200];
int cnt;
void dfs(int pos,int left)
{
     //cout<<pos<<" "<<left<<endl;
     if(left==0)
     {
       cnt++;
       return ;
     }
     for(int i=pos+1;i<=100;i++)
     {
         if(i<=left)
         {
            dfs(i,left-i);
         }
     }
}            
void init()
{
   memset(ans,0,sizeof(ans));
   for(int i=3;i<=100;i++)
   {
       memset(vis,0,sizeof(vis));
       cnt=0;
       dfs(0,i);
       ans[i]=cnt;           
   }   
}
int main()
{
    int n;
    /*
    init();
    ofstream outfile("3511.txt",ios::out);
    
    for(int i=0;i<=100;i++)
    {
         outfile<<ans[i]-1<<",";
    }
    outfile.close();   
    */
    while(cin>>n,n)
    {
      cout<<ans[n]<<endl;
    }
}          
