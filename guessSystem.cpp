#include "guessSystem.h"

GuessSystem::GuessSystem()
{
	this->initSystem();
	this->lodeInfo();
}

void GuessSystem::initSystem()
{
	this->m_Rec.m_Time = 0;
	this->m_Rec.m_Number = 0;
	this->m_Rec.m_Ral = 0;
	this->m_Rec.m_Max = 100;
	this->m_Rec.m_Min = 1;
	this->isSeccess = false;
	this->fileIsEmpty = true;
	this->m_Map.clear();
	this->m_Index = 0;
}

void GuessSystem::lodeInfo()
{
	int index;
	string data;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;

	ifs.putback(ch);

	while (ifs >> index && ifs >> data)
	{
		this->m_Map.insert(make_pair(index, data));
		
		this->m_Index++;
	}
	ifs.close();
}

void GuessSystem::showMenu()
{
	cout << "===============  欢迎来到猜数字游戏（控制台版本） ==============\n" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.开始游戏           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.游戏规则           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.历史记录           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          4.清空记录           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: ";
}

void GuessSystem::showRule()
{
	Sleep(700);

	cout << "\n这是一个简单的猜数字小游戏，系统会为您随机提供一个 1~100 之间的随机数\n"
		<< "您可以选择不同的难度进行游戏：\n\n"
		<< "1.欧皇—— 1 次猜测机会\n"
		<< "2.困难—— 3 次猜测机会\n"
		<< "3.普通—— 6 次猜测机会\n"
		<< "4.简单—— 8 次猜测机会\n"
		<< "5.非酋—— 12 次猜测机会\n" << endl;

}


void GuessSystem::startGame()
{
	//设定难度
	this->setDifficulty();

	//设定随机数
	this->setNumber();

	//测试代码
	//cout <<"答案：" << this->m_Rec.m_Number;

	//猜测并进行比较
	this->compare();

	//保存数据
	this->save();

	//初始化信息
	this->initSystem();
	this->lodeInfo();
}

void GuessSystem::setDifficulty()
{
	int difficalty = 0;
	
	while (true)
	{
		cout << "请输入本次游戏的难度等级（1 ~ 5）" << endl;
		cin >> difficalty;

		if (difficalty == 1)
		{
			this->m_Rec.m_Difficalty = UNBELIEVABLE;
			break;
		}
		else if (difficalty == 2)
		{
			this->m_Rec.m_Difficalty = HARD;
			break;
		}
		else if (difficalty == 3)
		{
			this->m_Rec.m_Difficalty = SIMPLE;
			break;
		}
		else if (difficalty == 4)
		{
			this->m_Rec.m_Difficalty = EASY;
			break;
		}
		else if (difficalty == 5)
		{
			this->m_Rec.m_Difficalty = VERY_EASY;
			break;
		}
		else
		{
			cout << "请输入正确的难度选项" << endl;
			system("pause");
		}
	}
}

void GuessSystem::setNumber()
{
	this->m_Rec.m_Number = rand() % 100 + 1;
}

void GuessSystem::compare()
{
	int ral = 0;

	for (int i = 0; i < this->m_Rec.m_Difficalty; i++)
	{
		this->m_Rec.showInfo();

		cout << "请输入你的猜测：" << endl;
		cin >> ral;

		this->m_Rec.m_Ral = ral;

		if (this->m_Rec.m_Ral == this->m_Rec.m_Number)
		{	
			this->isSeccess = true;

			if (this->m_Rec.m_Difficalty == UNBELIEVABLE)
			{
				cout << "哇！欧皇牛呀，一发命中！答案:" << this->m_Rec.m_Number << endl;
			}
			else if (this->m_Rec.m_Difficalty == HARD)
			{
				cout << "可以呀，这都猜出来了！答案:" << this->m_Rec.m_Number << endl;
			}
			else
			{
				cout << "恭喜你猜中啦！答案就是" << this->m_Rec.m_Number << endl;
			}

			return;
		}

		//三目运算求边界
		(this->m_Rec.m_Ral > this->m_Rec.m_Number) ? (this->m_Rec.m_Max = this->m_Rec.m_Ral) : (this->m_Rec.m_Min = this->m_Rec.m_Ral);

		this->m_Rec.m_Time++;
	}

	cout << "可惜了，猜测机会已用尽。答案为：" << this->m_Rec.m_Number << endl;
	this->isSeccess = false;
	
}

void GuessSystem::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);

	ofs << this->m_Index << " " << this->m_Rec.m_Difficalty << "/" << this->m_Rec.m_Time + 1 << endl;

	this->m_Index++;

	ofs.close();
	cout << "已保存记录" << endl;
}

void GuessSystem::showAllScore()
{
	if (this->fileIsEmpty)
	{
		cout << "记录为空或不存在" << endl;
		return;
	}

	for (int i = 0; i < this->m_Map.size(); i++)
	{
		cout << "轮数：" << this->m_Index << " 难度/尝试次数：" << this->m_Map[i] << endl;
	}

}

void GuessSystem::clearScore()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::trunc);
	ofs.close();
	this->fileIsEmpty = true;
	cout << "清空成功！" << endl;
}

void GuessSystem::exitGame()
{
	cout << "欢迎下次游玩" << endl;
	system("pause");
	exit(0);
}

GuessSystem::~GuessSystem()
{
}
