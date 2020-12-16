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


	bool isLeap(int year);					//判断year是否是闰年
	int daysFromToday();					//计算CalculateDays距离今天多少天，返回的是经过去取正值的
	int daysOfMonth(int year,int month);	//计算本月有多少天
	bool smallOrEqualThanCurrentdate();			//判断当前对象距离0000年00月00日的天数是否小于或者等于系统日期距离0000年00月00日的天数,如果是返回ture，如果不是返回false
protected:
	int daysOfDate();						//计算本日期距离0000年00月00日有多少天
private:
	int m_year;
	int m_month;
	int m_day;
};

#endif

