#include<iostream>
using namespace std;
#include"guessSystem.h"

int main()
{
	//实例化猜测系统对象
	GuessSystem gs;

	//引入随机种子
	srand((unsigned int)time(NULL));

	while (true)
	{
		//调用界面函数
		gs.showMenu();

		int choice = 0;
		cin >> choice;

		switch (choice)
		{
		case 1://开始游戏
			gs.startGame();
			break;
		case 2://显示规则
			gs.showRule();
			break;
		case 3://显示历史记录
			gs.showAllScore();
			break;
		case 4://清空历史记录
			gs.clearScore();
			break;
		case 0://退出程序
			gs.exitGame();
			break;
		default:
			cout << "请输入正确选项！！！\a" << endl;
			Sleep(1000);
			system("cls");
			break;
		}

		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}