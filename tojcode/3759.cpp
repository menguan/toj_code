#include <iostream>
#include <algorithm>
using namespace std;
int scores[110];
int main()
{
    int num;
    while (cin>>num,num)
    {
          double sum = 0;
          for (int i = 0; i < num; i++)
          {
              cin >> scores[i];
              sum += scores[i];
          }
          sort(scores, scores+num);
          sum -= (scores[0] + scores[num-1]);
          double ans =sum/(num-2);
          cout<<(int)ans<<endl;
    }
    
    
}
