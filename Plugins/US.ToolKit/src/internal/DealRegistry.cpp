#include "DealLicense.h"
#include "DealRegistry.h"
#include "CalculateDays.h"
#include <atltime.h>
#include "SoftNameStringAndRegistryString.h"
//#define Prototype RUN;    //证明使用原型
#define LxbDebug MyTest;	//证明使用测试

int DealRegistry::readRegistry(string str){
	//cout << "read Registry" <<endl;
	CTime t = CTime::GetCurrentTime();
	CString a;
	char direct[256];
	unsigned char value[256];
	HKEY keyRet;

	int i = 99999;				//存储已经使用了多少天了
	char year[10];
	year[0] = NULL;
	char month[5];
	month[0] = NULL;
	char day[5];
	day [0] = NULL;
	
	CString registryName = "";

	int localSofterNameIndex = softerNameStringNameSpace::findNameIndex(str);
	if(localSofterNameIndex != g_MAX_SOFTER_NAME_COUNT)
	{
		registryName  = registryName + (g_registryString[localSofterNameIndex]).c_str();
	}

	/*CString registryName;
	if(str=="AK"){
		registryName  = "Software\\Windows_Active";
	}
	if(str=="CK"){
		registryName  = "Software\\Windows_Control";
	}
	if(str=="OK"){
		registryName  = "Software\\Windows_Object";
	}
	if(str=="EK"){
		registryName  = "Software\\Windows_Executive";
	}
	if(str=="MK"){
		registryName  = "Software\\Windows_Memory";
	}*/
	long returnCode = RegOpenKeyEx(HKEY_CURRENT_USER ,registryName, 0, KEY_READ|KEY_WRITE|KEY_ALL_ACCESS|KEY_WOW64_64KEY,&keyRet);
	if (returnCode == ERROR_SUCCESS){
		DWORD type=REG_SZ;
		DWORD size = 256;
		value[0] = 0;
		if (RegQueryValueEx(keyRet,_T("versionTime"),NULL,&type,value,&size) == ERROR_SUCCESS)	
		{
			//到找versionTime(是第二次运行及以后运行软件) 上次运行的日期oldDate 和 当前运行该软件时间currentDate 之间的时间差 useSpaceTime
			//然后修改 i = i + useSpaceTime;（其中i代表已经使用的天数） 将currentDate写入计算机中

			//对获取到的value进行处理
			/***************************begin 对写入注册表中的明文进行简单的处理*************************/
			{
				//这样处理的原因：因为本来该部分采用的Unicode编码注册表将会是密文，但是在加入到K-serial中的时候要使用Use Multi-Byte Character Set编码则为明文，所以目前加入以下简单处理
				unsigned char deCodeDirect[256];
				//cout<<"我得到注册表中的文本全部输出内容为 ： "<<endl;
				int n=0;
				int m=0;
				for( ;(value[m])!='\0';m++)
				{
					n++;
					//cout<<value[m];
					deCodeDirect[m] = value[m] - 10; 
				}	
				deCodeDirect[m] = '\0'; 
				cout<<endl;
				//cout<<"字符数组的长度 ： " <<n<<endl; 

								//为了不改变后面的值，将deCodeDirect全部复制给value  ， 只是为了兼容之前写的代码
				for( int j=0 ;(deCodeDirect[j])!='\0';j++)
				{
					value[j]=deCodeDirect[j]  ; 	
				}
			}			
			/***************************end 对写入注册表中的明文进行简单的处理*************************/


			sscanf((char*)value, "%d-0098007-05662-1111-%[0-9]-1111-%[0-9]-1111-%[0-9]-1111", &i, day , year, month);
			int currentYear = t.GetYear();
			int currentMonth = t.GetMonth();
			int currentDay = t.GetDay();
			cout<<"currentDate :  "<<currentYear<<"  "<<currentMonth<<"  "<<currentDay<<endl;
			cout<<"The Software has been used for "<< i << " days!"<<endl;

			int tempYear = atoi(year);
			int tempMonth = atoi(month);
			int tempDay = atoi(day);
			//cout<<"oldDate: "<<tempYear<<" "<<tempMonth<<"  "<<tempDay<<endl;
			CalculateDays cDays;
			cDays.setYear(tempYear);
			cDays.setMonth(tempMonth);
			cDays.setDay(tempDay);
			bool tempBoolDay = cDays.smallOrEqualThanCurrentdate();			//判断注册表中的天数是否小于等于当前系统的时间
			int spaceDays = 0;												//初始化跨越（持续不关机或者持续关机）的天数为0天
			if (tempBoolDay)												//如果小于当前系统的时间，则表中的数据进行更新
			{
				int spaceDays = cDays.daysFromToday();						//持续不关机或者持续关机的天数
				i += spaceDays;
				//cout<<"持续不关机或者持续关机的天数 : "<<spaceDays<<endl;
				sprintf(year, "%d", currentYear);		//将currentYear转为10进制表示的year字符串。
				sprintf(month, "%d", currentMonth);		//将currentMonth转为10进制表示的month字符串。
				sprintf(day, "%d", currentDay);			//将currentDay转为10进制表示的day字符串。
				//sprintf((char*)value, "%d-0098007-05662-1111-%[0-9]-1111-%[0-9]-1111-%[0-9]-1111", i, day , year, month);
				sprintf((char*)value, "%d-0098007-05662-1111-%s-1111-%s-1111-%s-1111", i, day , year, month);

				/***************************begin 对写入注册表中的明文进行简单的处理*************************/
				{
					//这样处理的原因：因为本来该部分采用的Unicode编码注册表将会是密文，但是在加入到K-serial中的时候要使用Use Multi-Byte Character Set编码则为明文，所以目前加入以下简单处理
					unsigned char codeDirect[256];
					//cout<<"我的数组的文本是否全部输出： "<<endl;
					int n=0;
					int m=0;
					for( ;(value[m])!='\0';m++)
					{
						n++;
						//cout<<value[m];
						codeDirect[m] = value[m] + 10; 
					}	
					codeDirect[m] = '\0'; 
					cout<<endl;
					//cout<<"字符数组的长度read part n  ： " <<n<<endl; 
					DWORD nowsize=n;//strlen(codeDirect);
 					RegSetValueEx(keyRet,_T("versionTime"),NULL,REG_SZ,(unsigned char*)codeDirect,nowsize);
				}
				/***************************end 对写入注册表中的明文进行简单的处理*************************/

				//DWORD nowsize=strlen((char*)value);
				//cout<<"length Value: "<<nowsize<<endl;
				//RegSetValueEx(keyRet,_T("versionTime"),NULL,REG_SZ,(unsigned char*)value,nowsize);//MProductId
				RegCloseKey(keyRet);
			}
			return ( ((i>0)||(i==0))?i:0 );
		}
	}else{
		return -1;
	}
}

/************************************************************************/
/* 返回值(int 类型)：
	1：表示注册表已经存在无需创建
	2：表示注册表创建失败
	3：表示注册表创建成功但是写入数据失败
	4：表示注册创建成功且写入数据成功
*/
/************************************************************************/
int DealRegistry::createRegistry(string str){
	//cout << "createRegistry" <<endl;
	CTime t = CTime::GetCurrentTime();
	CString a;
	char direct[256];
	unsigned char value[256];
	HKEY keyRet;

	CString registryName = "";

	int localSofterNameIndex = softerNameStringNameSpace::findNameIndex(str);
	if(localSofterNameIndex != g_MAX_SOFTER_NAME_COUNT)
	{
		registryName  = registryName + (g_registryString[localSofterNameIndex]).c_str();
	}

	//if(str=="AK"){
	//	registryName  = "Software\\Windows_Active";
	//}
	//if(str=="CK"){
	//	registryName  = "Software\\Windows_Control";
	//}
	//if(str=="OK"){
	//	registryName  = "Software\\Windows_Object";
	//}
	//if(str=="EK"){
	//	registryName  = "Software\\Windows_Executive";
	//}
	//if(str=="MK"){
	//	registryName  = "Software\\Windows_Memory";
	//}

	long returnCode = RegOpenKeyEx(HKEY_CURRENT_USER ,registryName, 0, KEY_READ|KEY_WRITE|KEY_ALL_ACCESS|KEY_WOW64_64KEY,&keyRet);
	if(returnCode == ERROR_SUCCESS){
		//cout<<"注册表已经存在，无需创建"<<endl;
		return 1;//如果已经存在就直接返回，无需创建
	}else{
		//cout<<"注册表不存在，现在开始创建"<<endl;
		RegCreateKeyEx(HKEY_CURRENT_USER ,registryName , 0, NULL, 0, KEY_READ|KEY_WRITE|KEY_ALL_ACCESS|KEY_WOW64_64KEY, NULL, &keyRet, NULL);//创建相应的注册表
		if (RegOpenKeyEx(HKEY_CURRENT_USER ,registryName, 0, KEY_READ|KEY_WRITE|KEY_ALL_ACCESS|KEY_WOW64_64KEY,&keyRet) == ERROR_SUCCESS){
			DWORD type=REG_SZ;
			DWORD size = 256;
			value[0] = 0;
			if (RegQueryValueEx(keyRet,_T("versionTime"),NULL,&type,value,&size) != ERROR_SUCCESS){

			#ifdef LxbDebug
				a = "00000-0098007-05662";//the number series to hide the day digit
				CString lxbDisturbEncode = "-1111-";
				CString lxbDisturbEncodeEnd = "-1111";
				a = a+ lxbDisturbEncode +(LPCTSTR)t.Format(_T("%d")) + lxbDisturbEncode + (LPCTSTR)t.Format(_T("%Y")) + lxbDisturbEncode + (LPCTSTR)t.Format(_T("%m")) + lxbDisturbEncodeEnd ;
			#endif

				strcpy(direct, (LPCSTR)CStringA((LPCTSTR)a));
				/***************************begin 对写入注册表中的明文进行简单的处理*************************/
				{
					//这样处理的原因：因为本来该部分采用的Unicode编码注册表将会是密文，但是在加入到K-serial中的时候要使用Use Multi-Byte Character Set编码则为明文，所以目前加入以下简单处理
					char codeDirect[256];
					//cout<<"我的数组的文本是否全部输出： "<<endl;
					int n=0;
					int i=0;
					for( ;(direct[i])!='\0';i++)
					{
						n++;
						//cout<<direct[i];
						codeDirect[i] = direct[i] + 10; 
					}	
					codeDirect[i] = '\0'; 
					cout<<endl;
					//cout<<"字符数组的长度 ： " <<n<<endl; 
					DWORD nowsize=strlen(codeDirect);
 					returnCode = RegSetValueEx(keyRet,_T("versionTime"),NULL,REG_SZ,(unsigned char*)codeDirect,nowsize);
				}
				/***************************end 对写入注册表中的明文进行简单的处理*************************/
			   //如果不适用上面 《对写入注册表中的明文进行简单的处理》 就不要注释下面这两行
			   //DWORD nowsize=strlen(direct);
 			   //returnCode = RegSetValueEx(keyRet,_T("versionTime"),NULL,REG_SZ,(unsigned char*)direct,nowsize);
				RegCloseKey(keyRet);
				if (returnCode == ERROR_SUCCESS)
				{
					return 4;
				}else{
					return 3;
				}
			}else{
				cout<<"failed to create registry!"<<endl;
			}
		}
		return 2;
	}
}