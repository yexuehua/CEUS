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

	void readDwVolSerial();										//从计算机中读取电脑C盘序列号，并且内部调用setDwVolSerial()设置m_dwVolSerial 
	DWORD getDwVolSerial();										//返回m_dwVolSerial
	void changeDwVolSerialWithRSHash();							//将m_dwVolSerial经过RSHash(char *str)处理后然后调用setAfterRSHashDwVolSerial(unsigned int afterRSHashDwVolSerial)设置m_afterRSHashDwVolSerial
	unsigned int getAfterRSHashDwVolSerial();					//返回m_afterRSHashDwVolSerial

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

	bool readLicense(string str);											//读取License.lic里面的数据，并且设置m_line0,m_line1,m_line2,m_line3 m_line97EncodeQstringBeginYear  98  216  217  233  234
	bool checkVersion(string str);								//检查版本(内部是和m_afterRSHashDwVolSerial再进行一次加密) str可以为"AK","CK","OK","TK"
	/************************************************************************/
	/* 
	   1.是否在符合版本要求;str可以为"AK","CK","OK","TK"
	   2.是否匹配经过RSHashc处理后的dwVolSerial序列;
	   3.是否在使用的期限内
	*/
	/************************************************************************/
	bool checkAuthorization (string str);									

protected:
	QString EncodeXOR(QString OriginalText,QString keyText);    //异或处理进行加密
	unsigned int RSHash(char *str);								//进行RSHash变化
	void setDwVolSerial( DWORD dwVolSerial );					//设置dwVolSerial
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
	DWORD m_dwVolSerial;				   						 //电脑C盘序列号
	unsigned int m_afterRSHashDwVolSerial;						 //经过RSHashc处理后的dwVolSerial序列

	QString m_line0;											 //license中第一行的数据  ：经过哈希处理之后的序列号
	QString m_line1;											 //license中第二行的数据  ：没有用
	QString m_line2;											 //license中第三行的数据  ：能使用的天数
	QString m_line3;											 //license中第四行的数据  ：
																 //91行+5行=96行所以从97行
	QString m_line97EncodeQstringBeginYear;						 //加密后的开始的年                      
	QString m_line98EncodeQstringEndYear;						 //加密后的结束的年                    
	QString m_line216EncodeQstringBeginMonth;					 //加密后的开始的月                    
	QString m_line217EncodeQstringEndMonth;						 //加密后的结束的月
	QString m_line233EncodeQstringBeginDay;					     //加密后的开始的日                    
	QString m_line234EncodeQstringEndDay;						 //加密后的结束的日


   static	const unsigned long long randomNumber =  20150306;				//对应生成license中的QT界面Random Number(<=8bit)中输入的数值
   
};
#endif
