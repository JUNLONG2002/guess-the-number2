#include"recorder.h"

Recorder::Recorder()
{
	this->m_Time = 0;
	this->m_Number = 0;
	this->m_Ral = 0;
	this->m_Max = 100;
	this->m_Min = 0;
	this->m_Difficalty = 0;
}

void Recorder::showInfo()
{
	cout << "��������ڵ�����Ϊ " << this->m_Min << " ~ " << this->m_Max << endl;
	cout << "������ " << this->m_Difficalty - this->m_Time << " �β²����" << endl;
}

Recorder::~Recorder()
{
}
