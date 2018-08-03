#include<iostream>    //自己写了一个更长的结果调试不对  最后找了一个照着打的
#include<stdio.h>
#include<cstring>  
#include<vector>    
#include<string>    
using namespace std;      
int pd[4][2]={0,1,1,0,0,-1,-1,0};   
int pi[4][2]={1,0,0,1,1,1,0,0};   
class item{   
public:   
    int dir,x,y;   
    item(){}   
    item(int fangxiang,int weizhi1,int weizhi2){dir=fangxiang;x=weizhi1;y=weizhi2;}   
    item(const item & s){dir=s.dir;x=s.x;y=s.y;}   
};   
bool cango(vector<vector<int> > & map,int i,int j,int m,int n){   
    if(i>=0&&j>=0&&i<m&&j<n&&map[i][j]==0) return true;   
    else return false;   
}   
int main(){   
    int j,k,l,i,m,n,d,ai,aj,t,h;   
    string s;   
    while(cin>>m>>n&&m!=0){   
       vector<int> _vec(n,0);   
       vector<vector<int> > map(m,_vec),__vec(m,_vec);   
       for(i=0;i<m;i++) for(j=0;j<n;j++) cin>>map[i][j];   
       cin>>i>>j>>ai>>aj>>s;   
       i-=1;j-=1;ai-=1;aj-=1;   
       if(i==ai&&j==aj) {cout<<"0\n"; continue;}   
       if(s=="east") d=0;   
       else if(s=="south") d=1;   
       else if(s=="west") d=2;   
       else d=3;   
       item begin(d,i,j);   
       vector<vector<vector<int> > > cmp(4,__vec);   
       cmp[d][i][j]=1;   
       vector<item> last,now; last.push_back(begin);   
       t=0;   
       while(last.size()){   
           t++;      
           for(i=0;i<last.size();i++){   
              item temp1(last[i]),temp2(last[i]);   
              temp1.dir=(temp1.dir+1+4)%4; temp2.dir=(temp2.dir-1+4)%4;    
              if(cmp[temp1.dir][temp1.x][temp1.y]==0) {now.push_back(temp1);cmp[temp1.dir][temp1.x][temp1.y]=1;}   
              if(cmp[temp2.dir][temp2.x][temp2.y]==0) {now.push_back(temp2);cmp[temp2.dir][temp2.x][temp2.y]=1;}   
              j=1;      
              k=last[i].x+pd[last[i].dir][0];l=last[i].y+pd[last[i].dir][1];   
              for(h=0;h<4;h++){   
                  if(!cango(map,k+pi[h][1],l+pi[h][0],m,n)){   
                      j=0;break;   
                  }   
              }   
              if(j==1&&cmp[last[i].dir][k][l]==0){   
                  now.push_back(item(last[i].dir,k,l));   
                  cmp[last[i].dir][k][l]=1;   
                  if(k==ai&&l==aj) {cout<<t; goto out;}   
              }       
              if(j==1){   
                  k+=pd[last[i].dir][0];l+=pd[last[i].dir][1];   
                  for(h=0;h<4;h++){   
                     if(!cango(map,k+pi[h][1],l+pi[h][0],m,n)){   
                       j=0;break;   
                     }   
                  }   
                  if(j==1&&cmp[last[i].dir][k][l]==0){   
                     now.push_back(item(last[i].dir,k,l));   
                     cmp[last[i].dir][k][l]=1;   
                     if(k==ai&&l==aj) {cout<<t; goto out;}   
                  }   
              }       
              if(j==1){   
                  k+=pd[last[i].dir][0];l+=pd[last[i].dir][1];   
                  for(h=0;h<4;h++){   
                     if(!cango(map,k+pi[h][1],l+pi[h][0],m,n)){   
                       j=0;break;   
                     }   
                  }   
                  if(j==1&&cmp[last[i].dir][k][l]==0){   
                     now.push_back(item(last[i].dir,k,l));   
                     cmp[last[i].dir][k][l]=1;   
                     if(k==ai&&l==aj) {cout<<t; goto out;}   
                  }   
              }   
           }   
           last=now; now.clear();   
       }   
       cout<<"-1";   
       out:   
       cout<<endl;   
    }   
}  

