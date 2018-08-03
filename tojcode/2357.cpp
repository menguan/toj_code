#include<iostream>
#define MAX 65536
using namespace std;
int que[MAX*2];
int front,rear;
bool isVis[MAX];  
int step[MAX];        //记录到达id==i的状态所需翻转次数
int main(){
    char color;
    int id=0,tmp;
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){     //输入初始状态并转换为id
            cin>>color;
            id<<=1;
            if(color=='b')id+=1;
        }
    }
    if(id==0||id==65535){cout<<0<<endl;return 0;}   //如果初始状态已经满足要求直接输出
    que[rear++]=id;      //将初始状态id入队
    isVis[id]=true;
    step[id]=0;            //到达初始状态所需次数为0
    while(front<rear){   //如果队列不为空，继续操作
        tmp=que[front++];   //将队头元素出队
        id=tmp;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++){
                tmp=id;       //需要遍历队头元素的16种操作，每次都要还原tmp
                if(i==0)tmp^=1<<(11-4*i-j);          //翻转的位置为15-(4*(i+1)+j)
                else if(i==3)tmp^=1<<(19-4*i-j);   //翻转的位置为15-(4*(i-1)+j)
                else{
                    tmp^=1<<(11-4*i-j);
                    tmp^=1<<(19-4*i-j);
                }
                if(j==0)tmp^=3<<(14-4*i-j);          //翻转的位置为15-(4*i+j)、15-(4*i+j+1)
                else if(j==3)tmp^=3<<(15-4*i-j);  //翻转的位置为15-(4*i+j-1)、15-(4*i+j)
                else{
                    tmp^=7<<(14-4*i-j);                //翻转的位置为15-(4*i+j-1)、15-(4*i+j)、15-(4*i+j+1)
                }
                if(tmp==0||tmp==65535){
                    cout<<step[id]+1<<endl;
                    return 0;
                }
                if(!isVis[tmp]){      //如果是新的状态，入队
                    que[rear++]=tmp;
                    isVis[tmp]=true;
                    step[tmp]=step[id]+1;   //当前次数=到达队头元素所需次数+1
                }
            }
    }
    cout<<"Impossible"<<endl;
    
    return 0;
}       
