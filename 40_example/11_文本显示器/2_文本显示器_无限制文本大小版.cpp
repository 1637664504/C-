/*
功能:实现一个类似 less 的文本显示器
移动命令:
j 上一页 l 下一页

n	显示行号切换
//f	搜索文本 -->待实现
e	退出

问题缺陷：fseek(fp,-256,SEEK_CUR) 未知原因，不生效
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class screenText{
private:
	int screen_row = 16;
	int screen_column = 64;

public:
	FILE *fp;
	string file;
	char text[256];

	int open(string &File)
	{
		file = File;
		fp = fopen(file.c_str(),"r");
		if(fp == NULL)
		{
			return -1;
		}

		return 0;
	};

	int read()
	{
		memset(text,'\0',sizeof(text));
		return fread(text,sizeof(text),1,fp);
	};

	void close()
	{
		fclose(fp);
	};

	void show_text()
	{
		read();
		cout << text <<endl;
	};

	void show_help()
	{
		static string help =R"(
---------------------------
指令:
j 上一页
l 下一页
e 退出
---------------------------
)";
		cout << help <<endl;
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
		if(cmd == 'j')
		{
			pos = -256;
			cout << "pre 上一页" <<endl;
		}
		else if(cmd == 'l')
		{
			pos = 0;
			cout << "nex 下一页" <<endl;
		}
		else if(cmd == 'e')
			return 0;
		
		if(pos)
			handle_cmd(pos);
		
		return 1;
	};
	void handle_cmd(int pos)
	{
		int ret = 0;
		fpos_t old;
		fpos_t cur;
		fgetpos(fp,&old);
		if(pos)
		{
			ret = fseek(fp,pos,SEEK_CUR);
			fgetpos(fp,&cur);
			memset(text,'\0',sizeof(text));
			fread(text,sizeof(text),1,fp);
		}
	};

};

void set_input_noBlock(void)
{
    system("stty -icanon");
}

int main(int argc, char *argv[])
{
	screenText a;
	string file = "3.txt";
	if(argc == 2)
		file = argv[1];

	a.open(file);
	a.show_text();
	a.show_help();
	set_input_noBlock();

	while(a.getcmd())
	{
		//a.screen_clear();
		a.show_text();
		a.show_help();
	}
	a.close();

	return 0;
}
