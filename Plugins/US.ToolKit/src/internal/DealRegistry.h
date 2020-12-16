#ifndef DEALREGISTRY_H
#define DEALREGISTRY_H
#include <QString>
#include <Windows.h>
#include "CalculateDays.h"
#include <iostream>
using namespace std;

class DealRegistry{
	public:
		/************************************************************************/
		/* 返回值(int类型)
				大于等于0的整数：表示读取成功，且表示已经使用的天数
				-1:表示读取失败
		*/
		/************************************************************************/
		int readRegistry(string str);
		/************************************************************************/
		/* 返回值(int 类型)：
			1：表示注册表已经存在无需创建
			2：表示注册表创建失败
			3：表示注册表创建成功但是写入数据失败
			4：表示注册创建成功且写入数据成功
		*/
		/************************************************************************/
		int createRegistry(string str);


		
	protected:

	private:
		unsigned int m_registryUsedDays;		
		unsigned int m_registryYear;
		unsigned int m_registryMonth;
		unsigned int m_registryDay;
};
#endif
