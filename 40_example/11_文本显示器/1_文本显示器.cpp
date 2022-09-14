/*
功能:实现一个类似 less 的文本显示器
移动命令:
	i
j	k	l

n	显示行号切换
//f	搜索文本 -->待实现
e	退出

*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class screenText{
public:
	vector<string> text;
	int lineNum;
	int cur_line;
	string file;
	int numberFlags = 0;

	int init(string &File)
	{
		FILE *fp;
		//const char *File = file.c_str();
		//fp = fopen(File,"r");
		file = File;
		fp = fopen(file.c_str(),"r");
		if(fp == NULL)
		{
			return -1;
		}

		char line[1024];
		while(fgets(line,1024,fp))
		{
			text.push_back(line);
		}
		fclose(fp);

		lineNum = text.size();
		cur_line = 0;

		return 0;
	};

	void show_text()
	{
		vector<string>::iterator it;
		it = text.begin() + cur_line;
		int i=0;
		for(; (it!=text.end()) && (i<10); it++,i++)
		{
			if(numberFlags)
				cout << cur_line+i << ": " << *it;
			else
				cout << *it;
		}
	};

	void screen_clear()
	{
		cout << "\033c";
	};

	int getcmd()
	{
		char cmd;
		int pos = 0;
		cmd = getchar();
		if(cmd == 'i')
			pos = -1;
		else if(cmd == 'k')
			pos = 1;
		else if(cmd == 'j')
			pos = -10;
		else if(cmd == 'l')
			pos = 10;
		else if(cmd == 'n')
			numberFlags = !numberFlags;
		else if(cmd == 'e')
			return 0;
		
		if(pos)
			handle_cmd(pos);
		
		return 1;
	};
	void handle_cmd(int pos)
	{
		if(cur_line+pos > lineNum)
			cur_line = lineNum;
		else if(cur_line+pos < 0)
			cur_line = 0;
		else
			cur_line += pos;
	};

};

void set_input_noBlock(void)
{
    system("stty -icanon");
}

int main(int argc, char *argv[])
{
	screenText a;
	string file = "1.txt";
	if(argc == 2)
		file = argv[1];

	a.init(file);
	a.show_text();
	set_input_noBlock();

	while(a.getcmd())
	{
		a.screen_clear();
		a.show_text();
	}

	return 0;
}