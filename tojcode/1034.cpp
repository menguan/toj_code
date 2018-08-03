//Memory Time 
//452K 0MS 

/*DFS*/

#include<iostream>
using namespace std;

int n[7];  //价值为i的物品的个数
int SumValue;  //物品总价值
int HalfValue;  //物品平分价值
bool flag;    //标记是否能平分SumValue

void DFS(int value,int pre)
{
	if(flag)
		return;

	if(value==HalfValue)
	{
		flag=true;
		return;
	}

	for(int i=pre;i>=1;i--)
	{
		if(n[i])
		{
			if(value+i<=HalfValue)
			{
				n[i]--;
				DFS(value+i,i);

				if(flag)
					break;
			}
		}
	}
	return;
}

int main(int i)
{
	int test=1;
	while(cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]>>n[6])
	{
		SumValue=0;  //物品总价值

		for(i=1;i<=6;i++)
			SumValue+=i*n[i];

		if(SumValue==0)
			break;

		if(SumValue%2)    //sum为奇数，无法平分
		{
			cout<<"Collection #"<<test++<<':'<<endl;
			cout<<"Can't be divided."<<endl<<endl;    //注意有空行
			continue;
		}

		HalfValue=SumValue/2;
		flag=false;

		DFS(0,6);

		if(flag)
		{
			cout<<"Collection #"<<test++<<':'<<endl;
			cout<<"Can be divided."<<endl<<endl;
			continue;
		}
		else
		{
			cout<<"Collection #"<<test++<<':'<<endl;
			cout<<"Can't be divided."<<endl<<endl;
			continue;
		}
	}
	return 0;
}