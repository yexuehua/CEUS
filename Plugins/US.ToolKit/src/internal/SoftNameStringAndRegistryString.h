#ifndef SOFTNAMESTRINGANDREGISTRYSTRING_H
#define SOFTNAMESTRINGANDREGISTRYSTRING_H
#include<iostream>
#include<QString>
#include<string>
//#include<vector>
extern const std::string g_softNameString[];
extern const std::string g_registryString[];
extern const QString g_licenseQString[];

extern const int g_MAX_SOFTER_NAME_COUNT; // 定义最大用于保护的软件的个数最大可调整到9的21次方
namespace softerNameStringNameSpace
{
	int findNameIndex(std::string str);
}
#endif SOFTNAMESTRINGANDREGISTRYSTRING_H