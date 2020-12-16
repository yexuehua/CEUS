#ifndef CALCULATEDAYS_H
#define CALCULATEDAYS_H

class CalculateDays
{
public:
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	int getYear();
	int getMonth();
	int getDay();


	bool isLeap(int year);					//�ж�year�Ƿ�������
	int daysFromToday();					//����CalculateDays�����������죬���ص��Ǿ���ȥȡ��ֵ��
	int daysOfMonth(int year,int month);	//���㱾���ж�����
	bool smallOrEqualThanCurrentdate();			//�жϵ�ǰ�������0000��00��00�յ������Ƿ�С�ڻ��ߵ���ϵͳ���ھ���0000��00��00�յ�����,����Ƿ���ture��������Ƿ���false
protected:
	int daysOfDate();						//���㱾���ھ���0000��00��00���ж�����
private:
	int m_year;
	int m_month;
	int m_day;
};

#endif

