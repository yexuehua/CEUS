#include "CalculateDays.h"
#include <atltime.h>

//公共函数
void CalculateDays::setYear(int year){
	m_year = year;
}
void CalculateDays::setMonth(int month){
	m_month = month;
}
void CalculateDays::setDay(int day){
	m_day = day;
}

int CalculateDays::getYear(){
	return m_year;
}
int CalculateDays::getMonth(){
	return m_month;
}
int CalculateDays::getDay(){
	return m_day;
}

bool CalculateDays::isLeap(int year){
	return  ((year%4==0)&&(year%100!=0)||(year%400==0));//真返回为1，假为0
}

int CalculateDays::daysOfMonth(int year,int month)
{

	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(month!=2)
		return day[month-1];
	else 
		return 28+isLeap(year);
}

 int CalculateDays::daysFromToday(){ 
	CTime t = CTime::GetCurrentTime();
	CalculateDays currentDate;
	currentDate.setYear(t.GetYear());
	currentDate.setMonth(t.GetMonth());
	currentDate.setDay(t.GetDay());
	bool i = daysOfDate()>currentDate.daysOfDate();
	return ((daysOfDate()>(currentDate.daysOfDate())) ? (daysOfDate()-currentDate.daysOfDate()) : ( currentDate.daysOfDate()-daysOfDate()) ) ;
}

bool CalculateDays::smallOrEqualThanCurrentdate(){
	CTime t = CTime::GetCurrentTime();
	int currentYear = t.GetYear();
	int currentMonth = t.GetMonth();
	int currentDay = t.GetDay();
	if(this->getYear()>currentYear){
		return false;
	}else{
		if(this->getYear()==currentYear){
			if (this->getMonth()>currentMonth)
			{
				return false;
			} 
			else
			{
				if(this->getMonth()==currentMonth){
					if (this->getDay()>currentDay)
					{
						return false;
					}else{
						return true;
					}
				}
			}

		}
	}
	return true;
}

//受保护的函数
int CalculateDays::daysOfDate()
{
	int year = this->getYear();
	int month = this->getMonth();
	int days=this->getDay();
	for(int y=1;y<year;y++)//计算年
		days+=365+isLeap(y);
	for(int m=1;m<month;m++)//计算月
		days+=daysOfMonth(year,m);
	return days;
}