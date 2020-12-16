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
		/* ����ֵ(int����)
				���ڵ���0����������ʾ��ȡ�ɹ����ұ�ʾ�Ѿ�ʹ�õ�����
				-1:��ʾ��ȡʧ��
		*/
		/************************************************************************/
		int readRegistry(string str);
		/************************************************************************/
		/* ����ֵ(int ����)��
			1����ʾע����Ѿ��������贴��
			2����ʾע�����ʧ��
			3����ʾע������ɹ�����д������ʧ��
			4����ʾע�ᴴ���ɹ���д�����ݳɹ�
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
