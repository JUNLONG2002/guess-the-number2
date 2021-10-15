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
	cout << "===============  ��ӭ������������Ϸ������̨�汾�� ==============\n" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.��ʼ��Ϸ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��Ϸ����           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.��ʷ��¼           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          4.��ռ�¼           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";
}

void GuessSystem::showRule()
{
	Sleep(700);

	cout << "\n����һ���򵥵Ĳ�����С��Ϸ��ϵͳ��Ϊ������ṩһ�� 1~100 ֮��������\n"
		<< "������ѡ��ͬ���ѶȽ�����Ϸ��\n\n"
		<< "1.ŷ�ʡ��� 1 �β²����\n"
		<< "2.���ѡ��� 3 �β²����\n"
		<< "3.��ͨ���� 6 �β²����\n"
		<< "4.�򵥡��� 8 �β²����\n"
		<< "5.�������� 12 �β²����\n" << endl;

}


void GuessSystem::startGame()
{
	//�趨�Ѷ�
	this->setDifficulty();

	//�趨�����
	this->setNumber();

	//���Դ���
	//cout <<"�𰸣�" << this->m_Rec.m_Number;

	//�²Ⲣ���бȽ�
	this->compare();

	//��������
	this->save();

	//��ʼ����Ϣ
	this->initSystem();
	this->lodeInfo();
}

void GuessSystem::setDifficulty()
{
	int difficalty = 0;
	
	while (true)
	{
		cout << "�����뱾����Ϸ���Ѷȵȼ���1 ~ 5��" << endl;
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
			cout << "��������ȷ���Ѷ�ѡ��" << endl;
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

		cout << "��������Ĳ²⣺" << endl;
		cin >> ral;

		this->m_Rec.m_Ral = ral;

		if (this->m_Rec.m_Ral == this->m_Rec.m_Number)
		{	
			this->isSeccess = true;

			if (this->m_Rec.m_Difficalty == UNBELIEVABLE)
			{
				cout << "�ۣ�ŷ��ţѽ��һ�����У���:" << this->m_Rec.m_Number << endl;
			}
			else if (this->m_Rec.m_Difficalty == HARD)
			{
				cout << "����ѽ���ⶼ�³����ˣ���:" << this->m_Rec.m_Number << endl;
			}
			else
			{
				cout << "��ϲ����������𰸾���" << this->m_Rec.m_Number << endl;
			}

			return;
		}

		//��Ŀ������߽�
		(this->m_Rec.m_Ral > this->m_Rec.m_Number) ? (this->m_Rec.m_Max = this->m_Rec.m_Ral) : (this->m_Rec.m_Min = this->m_Rec.m_Ral);

		this->m_Rec.m_Time++;
	}

	cout << "��ϧ�ˣ��²�������þ�����Ϊ��" << this->m_Rec.m_Number << endl;
	this->isSeccess = false;
	
}

void GuessSystem::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);

	ofs << this->m_Index << " " << this->m_Rec.m_Difficalty << "/" << this->m_Rec.m_Time + 1 << endl;

	this->m_Index++;

	ofs.close();
	cout << "�ѱ����¼" << endl;
}

void GuessSystem::showAllScore()
{
	if (this->fileIsEmpty)
	{
		cout << "��¼Ϊ�ջ򲻴���" << endl;
		return;
	}

	for (int i = 0; i < this->m_Map.size(); i++)
	{
		cout << "������" << this->m_Index << " �Ѷ�/���Դ�����" << this->m_Map[i] << endl;
	}

}

void GuessSystem::clearScore()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::trunc);
	ofs.close();
	this->fileIsEmpty = true;
	cout << "��ճɹ���" << endl;
}

void GuessSystem::exitGame()
{
	cout << "��ӭ�´�����" << endl;
	system("pause");
	exit(0);
}

GuessSystem::~GuessSystem()
{
}
