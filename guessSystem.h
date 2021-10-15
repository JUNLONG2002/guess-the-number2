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

//猜测系统对象
class GuessSystem
{
public:
	GuessSystem();

	//初始化信息
	void initSystem();

	void lodeInfo();

	//菜单
	void showMenu();

	//规则
	void showRule();

	//游戏开始函数
	void startGame();

	//设定难度
	void setDifficulty();

	//设定随机数
	void setNumber();

	//进行比较
	void compare();

	//保存记录
	void save();

	//显示历史记录
	void showAllScore();

	//清空历史记录
	void clearScore();

	//退出游戏
	void exitGame();

	~GuessSystem();

	Recorder m_Rec;

	bool isSeccess;

	bool fileIsEmpty;

	//游戏局数
	int m_Index;

	map<int, string> m_Map;
};