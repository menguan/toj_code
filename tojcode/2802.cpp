//******************************************************************8
//************         ************************************************************8
//************  *****  ******************************************************************8
//************  *****  ********************************************************************
//************         **********************************************************************
//*******************************************************************************************
#include <stdio.h>

#include <cstring>

#include <iostream>

#include <queue>

#define MAX 110

using namespace std;

typedef struct node

{

    int step;

    int num;

    node(){};

    node(int ss,int nn)

    {

        step=ss;

        num=nn;

    }

    friend bool operator<(node a,node b)

    {

        return a.step>b.step;

    }

}Point;

priority_queue<Point>Q;

Point p,temp;

int n,MM;

struct node1

{

    int step;

    int mark;

    int to;

}data[MAX];

void Init()

{

    int i;

    int a,b,s;

    for(i=0;i<MAX;i++)

    {

        data[i].step=-1;

        data[i].mark=-1;

        data[i].to=0;

    }

    for(i=0;i<n;i++)

    {

        cin>>a>>b>>s;

        data[a].mark=b;

        data[a].to=s;

        if(b==1)

            data[a].to*=-1;

    }

}

void BFS()

{

    int i;

    while(!Q.empty())

        Q.pop();

    Q.push(node(0,0));

    data[0].step=0;


    while(!Q.empty())

    {

        p=Q.top();

        Q.pop();

        if(p.num==100)
        {

            return ;

        }

        if(data[p.num].mark==-1)

        {

            temp.step=p.step+1;

            for(i=1;i<=6;i++)

            {

                temp.num=p.num+i;

                if(temp.num>100)

                    temp.num=200-temp.num;

                if(data[temp.num].step==-1||temp.step<data[temp.num].step)

                {

                    data[temp.num].step=temp.step;

                    Q.push(temp);

                }

            }

        }

        else

        {

            temp.step=p.step;

            if(data[p.num].mark==2)

            {

                temp.num=data[p.num].to;

            }

            else

            {

                temp.num=p.num+data[p.num].to;

                if(temp.num>100)

                    temp.num=200-temp.num;

                if(temp.num<0)

                    temp.num=0;

            }

            if(data[temp.num].step==-1||temp.step<data[temp.num].step)

            {

                data[temp.num].step=temp.step;

                Q.push(temp);

            }

        }

    }

}

int main()

{

    while(cin>>n)

    {

        Init();

        BFS();

        cout<<data[100].step<<endl;

    }

}
