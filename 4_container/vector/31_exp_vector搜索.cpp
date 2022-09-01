#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<string> a;
	string val;
	for(int i=1;i<=5;i++)
	{
		cout << "请输入字符串: ";
		cin >> val;
		a.push_back(val);
	}

	cout << "输入已完成----" <<endl;
	vector<string>::iterator it;
	int pos=0;
	while(1){
		cout << "请输入要搜索的 字符串: ";
		cin >> val;
		if(val == "exit")
		{
			cout << "退出运行!!" << endl;
			break;
		}
			
		for(it=a.begin();it<a.end(); it++)
		{
			if(*it == val){
				pos ++;
				break;
			}
			pos ++;
		}

		if(it == a.end())
		{
			cout << "未发现字符串" << endl;
		}
		else{
			cout << "字符串位置:" << pos <<endl;
		}
	}



    return 0;
}
/*
测试:

请输入字符串: aaa
请输入字符串: vvv
请输入字符串: ccc
请输入字符串: bbb
请输入字符串: ddd
输入已完成
请输入要搜索的 字符串: vvv
字符串位置:2
请输入要搜索的 字符串: abc
未发现字符串
*/