#include<iostream>
using namespace std;
#include"guessSystem.h"

int main()
{
	//ʵ�����²�ϵͳ����
	GuessSystem gs;

	//�����������
	srand((unsigned int)time(NULL));

	while (true)
	{
		//���ý��溯��
		gs.showMenu();

		int choice = 0;
		cin >> choice;

		switch (choice)
		{
		case 1://��ʼ��Ϸ
			gs.startGame();
			break;
		case 2://��ʾ����
			gs.showRule();
			break;
		case 3://��ʾ��ʷ��¼
			gs.showAllScore();
			break;
		case 4://�����ʷ��¼
			gs.clearScore();
			break;
		case 0://�˳�����
			gs.exitGame();
			break;
		default:
			cout << "��������ȷѡ�����\a" << endl;
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