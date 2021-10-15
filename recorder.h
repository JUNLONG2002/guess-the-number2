#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#define UNBELIEVABLE 1
#define HARD 3
#define SIMPLE 6
#define EASY 8
#define VERY_EASY 12

class Recorder
{
public:
	Recorder();

	void showInfo();

	~Recorder();

	//第几次猜测次数
	int m_Time;

	//目标随机数
	int m_Number;

	//猜测的数字
	int m_Ral;

	int m_Min;

	int m_Max;

	int m_Difficalty;
};