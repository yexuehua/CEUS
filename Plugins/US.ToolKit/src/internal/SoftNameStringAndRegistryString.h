#ifndef SOFTNAMESTRINGANDREGISTRYSTRING_H
#define SOFTNAMESTRINGANDREGISTRYSTRING_H
#include<iostream>
#include<QString>
#include<string>
//#include<vector>
extern const std::string g_softNameString[];
extern const std::string g_registryString[];
extern const QString g_licenseQString[];

extern const int g_MAX_SOFTER_NAME_COUNT; // ����������ڱ���������ĸ������ɵ�����9��21�η�
namespace softerNameStringNameSpace
{
	int findNameIndex(std::string str);
}
#endif SOFTNAMESTRINGANDREGISTRYSTRING_H