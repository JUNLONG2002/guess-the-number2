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

	//�ڼ��β²����
	int m_Time;

	//Ŀ�������
	int m_Number;

	//�²������
	int m_Ral;

	int m_Min;

	int m_Max;

	int m_Difficalty;
};