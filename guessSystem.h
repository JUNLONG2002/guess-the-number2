#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<map>
using namespace std;
#include"recorder.h"
#define FILENAME "score.txt"

//�²�ϵͳ����
class GuessSystem
{
public:
	GuessSystem();

	//��ʼ����Ϣ
	void initSystem();

	void lodeInfo();

	//�˵�
	void showMenu();

	//����
	void showRule();

	//��Ϸ��ʼ����
	void startGame();

	//�趨�Ѷ�
	void setDifficulty();

	//�趨�����
	void setNumber();

	//���бȽ�
	void compare();

	//�����¼
	void save();

	//��ʾ��ʷ��¼
	void showAllScore();

	//�����ʷ��¼
	void clearScore();

	//�˳���Ϸ
	void exitGame();

	~GuessSystem();

	Recorder m_Rec;

	bool isSeccess;

	bool fileIsEmpty;

	//��Ϸ����
	int m_Index;

	map<int, string> m_Map;
};