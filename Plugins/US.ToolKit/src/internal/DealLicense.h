#ifndef DEALLICENSE_H
#define DEALLICENSE_H
#include <QString>
#include <Windows.h>
#include <iostream>
using namespace std;

class DealLicense
{
public:
	DealLicense();
	~DealLicense();

	void readDwVolSerial();										//�Ӽ�����ж�ȡ����C�����кţ������ڲ�����setDwVolSerial()����m_dwVolSerial 
	DWORD getDwVolSerial();										//����m_dwVolSerial
	void changeDwVolSerialWithRSHash();							//��m_dwVolSerial����RSHash(char *str)�����Ȼ�����setAfterRSHashDwVolSerial(unsigned int afterRSHashDwVolSerial)����m_afterRSHashDwVolSerial
	unsigned int getAfterRSHashDwVolSerial();					//����m_afterRSHashDwVolSerial

	QString getLine0();
	QString getLine1();
	QString getLine2();
	QString getLine3();

	QString getLine97EncodeQstringBeginYear();
	QString getLine98EncodeQstringEndYear();
	QString getLine216EncodeQstringBeginMonth();
	QString getLine217EncodeQstringEndMonth();
	QString getLine233EncodeQstringBeginDay();
	QString getLine234EncodeQstringEndDay();

	bool readLicense(string str);											//��ȡLicense.lic��������ݣ���������m_line0,m_line1,m_line2,m_line3 m_line97EncodeQstringBeginYear  98  216  217  233  234
	bool checkVersion(string str);								//���汾(�ڲ��Ǻ�m_afterRSHashDwVolSerial�ٽ���һ�μ���) str����Ϊ"AK","CK","OK","TK"
	/************************************************************************/
	/* 
	   1.�Ƿ��ڷ��ϰ汾Ҫ��;str����Ϊ"AK","CK","OK","TK"
	   2.�Ƿ�ƥ�侭��RSHashc������dwVolSerial����;
	   3.�Ƿ���ʹ�õ�������
	*/
	/************************************************************************/
	bool checkAuthorization (string str);									

protected:
	QString EncodeXOR(QString OriginalText,QString keyText);    //�������м���
	unsigned int RSHash(char *str);								//����RSHash�仯
	void setDwVolSerial( DWORD dwVolSerial );					//����dwVolSerial
	void setAfterRSHashDwVolSerial(unsigned int afterRSHashDwVolSerial);

	void setLine0(QString line0);
	void setLine1(QString line1);
	void setLine2(QString line2);
	void setLine3(QString line3);

	void setLine97EncodeQstringBeginYear(QString line97EncodeQstringBeginYear);
	void setLine98EncodeQstringEndYear(QString line98EncodeQstringEndYear);
	void setLine216EncodeQstringBeginMonth(QString line216EncodeQstringBeginMonth);
	void setLine217EncodeQstringEndMonth(QString line217EncodeQstringEndMonth);
	void setLine233EncodeQstringBeginDay(QString line233EncodeQstringBeginDay);
	void setLine234EncodeQstringEndDay(QString line234EncodeQstringEndDay);


private:
	DWORD m_dwVolSerial;				   						 //����C�����к�
	unsigned int m_afterRSHashDwVolSerial;						 //����RSHashc������dwVolSerial����

	QString m_line0;											 //license�е�һ�е�����  ��������ϣ����֮������к�
	QString m_line1;											 //license�еڶ��е�����  ��û����
	QString m_line2;											 //license�е����е�����  ����ʹ�õ�����
	QString m_line3;											 //license�е����е�����  ��
																 //91��+5��=96�����Դ�97��
	QString m_line97EncodeQstringBeginYear;						 //���ܺ�Ŀ�ʼ����                      
	QString m_line98EncodeQstringEndYear;						 //���ܺ�Ľ�������                    
	QString m_line216EncodeQstringBeginMonth;					 //���ܺ�Ŀ�ʼ����                    
	QString m_line217EncodeQstringEndMonth;						 //���ܺ�Ľ�������
	QString m_line233EncodeQstringBeginDay;					     //���ܺ�Ŀ�ʼ����                    
	QString m_line234EncodeQstringEndDay;						 //���ܺ�Ľ�������


   static	const unsigned long long randomNumber =  20150306;				//��Ӧ����license�е�QT����Random Number(<=8bit)���������ֵ
   
};
#endif
