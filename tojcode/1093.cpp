#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct
{
    int id;
    int time;
    int period;
}Register;
struct cmp
{
    bool operator()(Register a,Register b)
    {
        if(a.time==b.time)
          return a.id>b.id;
        return a.time>b.time;
    }
};

int main()
{
    priority_queue<Register,vector<Register>,cmp > re;
    string cmd;
    int id;
    int period;
    int count;
    while(1)
    {
        cin>>cmd;
        if(cmd.compare("#")==0)break;
        cin>>id>>period;
        Register r;
        r.id = id;
        r.period = period;
        r.time = period;
        re.push(r);
    }
    cin>>count;
    while(count--)
    {
        Register reg = re.top();
        cout<<reg.id<<endl;
        reg.time += reg.period;
        re.pop();
        re.push(reg);
    }
}
