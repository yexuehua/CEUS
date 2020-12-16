#include "DealLicense.h"
#include <QTextCodec>
#include <windows.h>
#include<tchar.h>
#include <QDir>
#include "qtextstream.h "
#include <atltime.h>
//#include <mbilog.h>

//��Release�汾�����ʹ������#include <mbilog.h>�����Ҫ�ڸù��������link
//C:\project\mitk2014\bin\MITK-build\bin\Release\mbilog.lib

//��Debug�汾�����ʹ������#include <mbilog.h>�����Ҫ�ڸù��������link
//mbilog.lib

#include "CalculateDays.h"
#include "DealRegistry.h"
#include "SoftNameStringAndRegistryString.h"
#include <iostream>
using namespace std;



//#define Prototype RUN;    //֤��ʹ��ԭ��
#define LxbDebug MyTest;	//֤��ʹ�ò���

//��������
DealLicense::DealLicense(){

}
DealLicense::~DealLicense(){}
void DealLicense::readDwVolSerial(){
	DWORD dwVolSerial;
	BOOL bIsRetrieved;
	

	//LPCWSTR rote = _T("C:\\");
	//bIsRetrieved = GetVolumeInformation(rote,NULL,NULL,&dwVolSerial,NULL,NULL,NULL,NULL);

	bIsRetrieved = GetVolumeInformation("C:\\",NULL,NULL,&dwVolSerial,NULL,NULL,NULL,NULL);

	if (bIsRetrieved) {
		cout << "Serial number of drive C is " << dwVolSerial << "\n";
	} 
	else {
		cout << "Could not retrieve\n";
	}
	setDwVolSerial(dwVolSerial);
}
DWORD DealLicense::getDwVolSerial(){
	return m_dwVolSerial;
}

void DealLicense::changeDwVolSerialWithRSHash(){
	DWORD dwVolSerial = getDwVolSerial();
	char strHD[50];
	sprintf(strHD, "%lu", dwVolSerial);
	unsigned int hashCode = RSHash(strHD);
	setAfterRSHashDwVolSerial(hashCode);
}
unsigned int DealLicense::getAfterRSHashDwVolSerial(){
	return m_afterRSHashDwVolSerial;
}
QString DealLicense::getLine0(){
	return m_line0;
}
QString DealLicense::getLine1(){
	return m_line1;
}
QString DealLicense::getLine2(){
	return m_line2;
}
QString DealLicense::getLine3(){
	return m_line3;
}
QString DealLicense::getLine97EncodeQstringBeginYear(){
	return m_line97EncodeQstringBeginYear;
}
QString DealLicense::getLine98EncodeQstringEndYear(){
	return m_line98EncodeQstringEndYear;
}
QString DealLicense::getLine216EncodeQstringBeginMonth(){
	return m_line216EncodeQstringBeginMonth;
}
QString DealLicense::getLine217EncodeQstringEndMonth(){
	return m_line217EncodeQstringEndMonth;
}
QString DealLicense::getLine233EncodeQstringBeginDay(){
	return m_line233EncodeQstringBeginDay;
}
QString DealLicense::getLine234EncodeQstringEndDay(){
	return m_line234EncodeQstringEndDay;
}

bool DealLicense::readLicense(string str){
	QString dirName = QDir::currentPath();
	QString filename = dirName;

	{
		//cout<<"��ʼ����1��**********"<<endl;
		int localSofterNameIndex = softerNameStringNameSpace::findNameIndex(str);
		if(localSofterNameIndex != g_MAX_SOFTER_NAME_COUNT)
		{
			//QString fileNamePostfix = QString::fromStdString(g_softNameString[localSofterNameIndex]);
			QString fileNamePostfix = g_licenseQString[localSofterNameIndex];
			//filename.append("/../../License/AkLicense.lic");
			filename.append("/../../License/").append(fileNamePostfix).append("License.lic");
			if (!QFile::exists(filename))
			{
				filename = dirName;
				//filename.append("/../License/AkLicense.lic");
				filename.append("/../License/").append(fileNamePostfix).append("License.lic");
			}
			if (!QFile::exists(filename))
			{
				filename = dirName;
				//filename.append("/License/AkLicense.lic");
				filename.append("/License/").append(fileNamePostfix).append("License.lic");
			}	
			if (!QFile::exists(filename))
			{
				return false;
			}
		}
	}
	
	/*if(str=="AK"){
		filename.append("/../../License/AkLicense.lic");
		if (!QFile::exists(filename))
		{
			filename = dirName;
			filename.append("/../License/AkLicense.lic");
		}
		if (!QFile::exists(filename))
		{
			filename = dirName;
			filename.append("/License/AkLicense.lic");
		}	
		if (!QFile::exists(filename))
		{
			return false;
		}
	}else{
		if (str=="CK")
		{
			filename.append("/../../License/CkLicense.lic");
			if (!QFile::exists(filename))
			{
				filename = dirName;
				filename.append("/../License/CkLicense.lic");
			}
			if (!QFile::exists(filename))
			{
				filename = dirName;
				filename.append("/License/CkLicense.lic");
			}	
			if (!QFile::exists(filename))
			{
				return false;
			}
		}else{
			if(str=="OK"){
				filename.append("/../../License/OkLicense.lic");
				if (!QFile::exists(filename))
				{
					filename = dirName;
					filename.append("/../License/OkLicense.lic");
				}
				if (!QFile::exists(filename))
				{
					filename = dirName;
					filename.append("/License/OkLicense.lic");
				}	
				if (!QFile::exists(filename))
				{
					return false;
				}
			}else{
				if(str=="EK"){
					filename.append("/../../License/EkLicense.lic");
					if (!QFile::exists(filename))
					{
						filename = dirName;
						filename.append("/../License/EkLicense.lic");
					}
					if (!QFile::exists(filename))
					{
						filename = dirName;
						filename.append("/License/EkLicense.lic");
					}	
					if (!QFile::exists(filename))
					{
						return false;
					}
				}else{
					if(str=="MK"){
						filename.append("/../../License/MkLicense.lic");
						if (!QFile::exists(filename))
						{
							filename = dirName;
							filename.append("/../License/MkLicense.lic");
						}
						if (!QFile::exists(filename))
						{
							filename = dirName;
							filename.append("/License/MkLicense.lic");
						}	
						if (!QFile::exists(filename))
						{
							return false;
						}
					}
					
				}
			}
		}
	}*/
	
	QFile file;
	file.setFileName (filename);
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);
	QString line0 = in.readLine();//wrong with index ,increase auto
	QString line1 = in.readLine();//wrong with index ,increase auto
	QString line2 = in.readLine();//wrong with index ,increase auto
	QString line3 = in.readLine();//wrong with index ,increase auto
	QString InvalidVariable = in.readLine(); //��Ч����ֻ��Ϊ�˺��淽��



	{ //����1����ȡ91���������
		for(int i=0;i<91;i++){
			QString InvalidVariable = in.readLine(); //��Ч����ֻ��Ϊ�˺��淽��
		}
	}
	QString line97EncodeQstringBeginYear = in.readLine(); //��ȡ��Ч����
	QString line98EncodeQstringEndYear = in.readLine(); //��ȡ��Ч����
	{ //����2������108���������
		for(int i=0;i<107;i++){
		QString InvalidVariable = in.readLine(); //��Ч����ֻ��Ϊ�˺��淽��
		}
	}																//200+5=205��
	{ //����1������10�����2λ��
		for(int i=0;i<10;i++){
		QString InvalidVariable = in.readLine(); //��Ч����ֻ��Ϊ�˺��淽��
		}
	}																 //210+5=215��
	QString line216EncodeQstringBeginMonth = in.readLine();			 //��ȡ��Ч����   211+5=216��
	QString line217EncodeQstringEndMonth = in.readLine();			 //��ȡ��Ч����   212+5=217��
	{ //����1������3�����2λ��
		for(int i=0;i<15;i++){
			QString InvalidVariable= in.readLine(); //��Ч����ֻ��Ϊ�˺��淽��
		}
	}                                                                 //212+15+5=232��
	QString line233EncodeQstringBeginDay = in.readLine();			 //��ȡ��Ч����   212+5=217��
	QString line234EncodeQstringEndDay = in.readLine();			 //��ȡ��Ч����   212+5=217��

	setLine0(line0);
	setLine1(line1);
	setLine2(line2);
	setLine3(line3);
	setLine97EncodeQstringBeginYear(line97EncodeQstringBeginYear);
	setLine98EncodeQstringEndYear(line98EncodeQstringEndYear);
	setLine216EncodeQstringBeginMonth(line216EncodeQstringBeginMonth);
	setLine217EncodeQstringEndMonth(line217EncodeQstringEndMonth);
	setLine233EncodeQstringBeginDay(line233EncodeQstringBeginDay);
	setLine234EncodeQstringEndDay(line234EncodeQstringEndDay);

	//QString testlin0 = getLine0();
	//QString testlin0 = getLine0();
	//QString testlin0 = getLine0();
	//QString testlin0 = getLine0();
	return true;
}

bool DealLicense::checkVersion(string str){
	readLicense(str);						//��ȡLicense.lic��������ݣ���������m_line0,m_line1,m_line2,m_line3
	bool tempBool = false;
	//�������������
	readDwVolSerial();													//��ȡӲ�����к�
	changeDwVolSerialWithRSHash();										//�ı����к�Ϊ����֮���m_afterRSHashDwVolSerial
	QString keyText = QString::number(m_afterRSHashDwVolSerial,10);		//��m_afterRSHashDwVolSerial + randomNumberת��ΪkeyTextΪ������Կ
	//cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMkeyText  :  "<<keyText.toStdString()<<endl;

	//cout<<"��ʼ����2��**********"<<endl;
	int localSofterNameIndex = softerNameStringNameSpace::findNameIndex(str);
	if(localSofterNameIndex != g_MAX_SOFTER_NAME_COUNT)
	{
		QString localSoftNameQstr = QString::fromStdString(g_softNameString[localSofterNameIndex]);
		//tempBool =  m_line3.contains(EncodeXOR("AK", "63031222181"));
		tempBool =  m_line3.contains(EncodeXOR(localSoftNameQstr,keyText ));
		return tempBool;
	}
/*
	if(str=="AK"){
		//tempBool =  m_line3.contains(EncodeXOR("AK", "63031222181"));
		tempBool =  m_line3.contains(EncodeXOR("AK",keyText ));
		return tempBool;
	}
	if(str=="CK"){
		//tempBool =  m_line3.contains(EncodeXOR("CK", "63031222181"));
		tempBool =  m_line3.contains(EncodeXOR("CK",keyText ));
		return tempBool;
	}
	if(str=="OK"){
		//tempBool =  m_line3.contains(EncodeXOR("AK", "63031222181"));
		QString tempQstring = EncodeXOR("OK",keyText );
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   :  "<<tempQstring.toStdString()<<endl;
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   :  "<<m_line3.toStdString()<<endl;
		tempBool =  m_line3.contains(tempQstring);
		cout<<"tempBool tempBool   :  "<<tempBool<<endl;
		//tempBool =  m_line3.contains(EncodeXOR("OK",keyText ));
		return tempBool;
	}
	if(str=="EK"){
		//tempBool =  m_line3.contains(EncodeXOR("AK", "63031222181"));
		QString tempQstring = EncodeXOR("EK",keyText );
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   :  "<<tempQstring.toStdString()<<endl;
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   :  "<<m_line3.toStdString()<<endl;
		tempBool =  m_line3.contains(tempQstring);
		cout<<"tempBool tempBool   :  "<<tempBool<<endl;
		//tempBool =  m_line3.contains(EncodeXOR("OK",keyText ));
		return tempBool;
	}
	if(str=="MK"){
		//tempBool =  m_line3.contains(EncodeXOR("AK", "63031222181"));
		QString tempQstring = EncodeXOR("MK",keyText );
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   :  "<<tempQstring.toStdString()<<endl;
		cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   :  "<<m_line3.toStdString()<<endl;
		tempBool =  m_line3.contains(tempQstring);
		cout<<"tempBool tempBool   :  "<<tempBool<<endl;
		//tempBool =  m_line3.contains(EncodeXOR("OK",keyText ));
		return tempBool;
	}
*/
	return false;
}

bool DealLicense::checkAuthorization (string str){
	bool tempBool = false;
	if(checkVersion(str)){											//���汾
		unsigned int uIntLine0 =  m_line0.toUInt();
		if(uIntLine0 == m_afterRSHashDwVolSerial){                 //�����ܺ�����к�
			tempBool = true;
		}else{
			tempBool = false;
		}
		
		if(tempBool){												  //���汾�ͼ�����кŶ�ͨ��������£��ټ��ʹ���ע����е�ʱ��
			DealRegistry DRegistry;
			int i = DRegistry.createRegistry(str);					  //������Ӧ��ע���
			if (i==3){
				//cout<<" i = "<<i<<endl;
				return false;
			}else{
				 int licenceUsedDay = DRegistry.readRegistry(str);			//��ȡ��Ӧ��ע���
				 if (licenceUsedDay>=0)
				 {
					QString keyText = QString::number(m_afterRSHashDwVolSerial+randomNumber,10);		//��m_afterRSHashDwVolSerial + randomNumberת��ΪkeyTextΪ������Կ
					QString timeCanUse =  EncodeXOR(m_line2,keyText);									//���ܳ�license����ʹ�õ�����
					int timeCanUseInt = timeCanUse.toInt();
					if(licenceUsedDay<timeCanUseInt){
						cout<<"��Ȩʹ��ʱ�仹ʣ�ࣺ "<<(timeCanUseInt-licenceUsedDay)<<endl;
						return true;
					}else{
						cout<<"�Ѿ�������Ȩʹ��ʱ�䣺  "<<(licenceUsedDay-timeCanUseInt)<<endl;
						return false;
					}

				 }
				
			}
		}
	}
	return false;
}

//�ܱ�������
#ifdef LxbDebug
QString DealLicense::EncodeXOR(QString OriginalText,QString keyText)
{
	QString Ciphertext;
	QByteArray byteCiphertext;

	string originalString = OriginalText.toStdString();	
	string keyString = keyText.toStdString();						
	//std::string originalString = std::string((const char*)OriginalText.toLocal8Bit());
	//std::string keyString = std::string((const char*)keyText.toLocal8Bit());
	const char *pOriginalChar = originalString.c_str();

	const char *pKeyChar = keyString.c_str();
	unsigned int originalStringLenth = originalString.length();
	unsigned int keyStringLenth = keyString.length();
	unsigned int len = (originalStringLenth<keyStringLenth)?originalStringLenth:keyStringLenth;
	char *afterXor;
	afterXor = new char[originalStringLenth+1];
	for (int i=0;i<originalStringLenth;i++)
	{
		afterXor[i]='a';							//���г�ʼ��
	}
	afterXor[originalStringLenth]='\0';				//����һ��Ҫ����'/0'���������ַ��������������
	unsigned int i=0,j=0;
	for (i=0;i<originalStringLenth;i++)
	{
		afterXor[i] = (pOriginalChar[i]^pKeyChar[j])+48 ;//ֻ�ǵ��Ե�ʱ��ʹ��
		//afterXor[i] = (pOriginalChar[i]^pKeyChar[j]);
		j++;
		if (j>=keyStringLenth)
		{
			j = 0;
		}
	}	
	string afterXorString = afterXor;
	Ciphertext = QString(QString::fromLocal8Bit(afterXorString.c_str()));//LXB
	//Ciphertext = QString::fromStdString(afterXorString);//��stringת��ΪQString
	return Ciphertext;
}
#endif

unsigned int DealLicense::RSHash(char *str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

void DealLicense::setDwVolSerial( DWORD dwVolSerial ){
	m_dwVolSerial = dwVolSerial;
}

void DealLicense::setAfterRSHashDwVolSerial(unsigned int afterRSHashDwVolSerial){
	m_afterRSHashDwVolSerial = afterRSHashDwVolSerial;
}

void DealLicense::setLine0(QString line0){
	m_line0 = line0;
}
void DealLicense::setLine1(QString line1){
	m_line1 = line1;
}
void DealLicense::setLine2(QString line2){
	m_line2 = line2;
}
void DealLicense::setLine3(QString line3){
	m_line3 = line3;
}
void DealLicense::setLine97EncodeQstringBeginYear(QString line97EncodeQstringBeginYear){
	m_line97EncodeQstringBeginYear = line97EncodeQstringBeginYear;
}
void DealLicense::setLine98EncodeQstringEndYear(QString line98EncodeQstringEndYear){
	m_line98EncodeQstringEndYear = line98EncodeQstringEndYear;
}
void DealLicense::setLine216EncodeQstringBeginMonth(QString line216EncodeQstringBeginMonth){
	m_line216EncodeQstringBeginMonth = line216EncodeQstringBeginMonth;
}
void DealLicense::setLine217EncodeQstringEndMonth(QString line217EncodeQstringEndMonth){
	m_line217EncodeQstringEndMonth=line217EncodeQstringEndMonth;
}
void DealLicense::setLine233EncodeQstringBeginDay(QString line233EncodeQstringBeginDay){
	m_line233EncodeQstringBeginDay = line233EncodeQstringBeginDay;
}
void DealLicense::setLine234EncodeQstringEndDay(QString line234EncodeQstringEndDay){
	m_line234EncodeQstringEndDay = line234EncodeQstringEndDay;
}