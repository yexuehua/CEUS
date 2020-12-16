#include "DealLicense.h"
#include "DealRegistry.h"
#include "CalculateDays.h"
#include <atltime.h>
#include "SoftNameStringAndRegistryString.h"
//#define Prototype RUN;    //֤��ʹ��ԭ��
#define LxbDebug MyTest;	//֤��ʹ�ò���

int DealRegistry::readRegistry(string str){
	//cout << "read Registry" <<endl;
	CTime t = CTime::GetCurrentTime();
	CString a;
	char direct[256];
	unsigned char value[256];
	HKEY keyRet;

	int i = 99999;				//�洢�Ѿ�ʹ���˶�������
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
			//����versionTime(�ǵڶ������м��Ժ��������) �ϴ����е�����oldDate �� ��ǰ���и����ʱ��currentDate ֮���ʱ��� useSpaceTime
			//Ȼ���޸� i = i + useSpaceTime;������i�����Ѿ�ʹ�õ������� ��currentDateд��������

			//�Ի�ȡ����value���д���
			/***************************begin ��д��ע����е����Ľ��м򵥵Ĵ���*************************/
			{
				//���������ԭ����Ϊ�����ò��ֲ��õ�Unicode����ע����������ģ������ڼ��뵽K-serial�е�ʱ��Ҫʹ��Use Multi-Byte Character Set������Ϊ���ģ�����Ŀǰ�������¼򵥴���
				unsigned char deCodeDirect[256];
				//cout<<"�ҵõ�ע����е��ı�ȫ���������Ϊ �� "<<endl;
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
				//cout<<"�ַ�����ĳ��� �� " <<n<<endl; 

								//Ϊ�˲��ı�����ֵ����deCodeDirectȫ�����Ƹ�value  �� ֻ��Ϊ�˼���֮ǰд�Ĵ���
				for( int j=0 ;(deCodeDirect[j])!='\0';j++)
				{
					value[j]=deCodeDirect[j]  ; 	
				}
			}			
			/***************************end ��д��ע����е����Ľ��м򵥵Ĵ���*************************/


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
			bool tempBoolDay = cDays.smallOrEqualThanCurrentdate();			//�ж�ע����е������Ƿ�С�ڵ��ڵ�ǰϵͳ��ʱ��
			int spaceDays = 0;												//��ʼ����Խ���������ػ����߳����ػ���������Ϊ0��
			if (tempBoolDay)												//���С�ڵ�ǰϵͳ��ʱ�䣬����е����ݽ��и���
			{
				int spaceDays = cDays.daysFromToday();						//�������ػ����߳����ػ�������
				i += spaceDays;
				//cout<<"�������ػ����߳����ػ������� : "<<spaceDays<<endl;
				sprintf(year, "%d", currentYear);		//��currentYearתΪ10���Ʊ�ʾ��year�ַ�����
				sprintf(month, "%d", currentMonth);		//��currentMonthתΪ10���Ʊ�ʾ��month�ַ�����
				sprintf(day, "%d", currentDay);			//��currentDayתΪ10���Ʊ�ʾ��day�ַ�����
				//sprintf((char*)value, "%d-0098007-05662-1111-%[0-9]-1111-%[0-9]-1111-%[0-9]-1111", i, day , year, month);
				sprintf((char*)value, "%d-0098007-05662-1111-%s-1111-%s-1111-%s-1111", i, day , year, month);

				/***************************begin ��д��ע����е����Ľ��м򵥵Ĵ���*************************/
				{
					//���������ԭ����Ϊ�����ò��ֲ��õ�Unicode����ע����������ģ������ڼ��뵽K-serial�е�ʱ��Ҫʹ��Use Multi-Byte Character Set������Ϊ���ģ�����Ŀǰ�������¼򵥴���
					unsigned char codeDirect[256];
					//cout<<"�ҵ�������ı��Ƿ�ȫ������� "<<endl;
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
					//cout<<"�ַ�����ĳ���read part n  �� " <<n<<endl; 
					DWORD nowsize=n;//strlen(codeDirect);
 					RegSetValueEx(keyRet,_T("versionTime"),NULL,REG_SZ,(unsigned char*)codeDirect,nowsize);
				}
				/***************************end ��д��ע����е����Ľ��м򵥵Ĵ���*************************/

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
/* ����ֵ(int ����)��
	1����ʾע����Ѿ��������贴��
	2����ʾע�����ʧ��
	3����ʾע������ɹ�����д������ʧ��
	4����ʾע�ᴴ���ɹ���д�����ݳɹ�
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
		//cout<<"ע����Ѿ����ڣ����贴��"<<endl;
		return 1;//����Ѿ����ھ�ֱ�ӷ��أ����贴��
	}else{
		//cout<<"ע������ڣ����ڿ�ʼ����"<<endl;
		RegCreateKeyEx(HKEY_CURRENT_USER ,registryName , 0, NULL, 0, KEY_READ|KEY_WRITE|KEY_ALL_ACCESS|KEY_WOW64_64KEY, NULL, &keyRet, NULL);//������Ӧ��ע���
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
				/***************************begin ��д��ע����е����Ľ��м򵥵Ĵ���*************************/
				{
					//���������ԭ����Ϊ�����ò��ֲ��õ�Unicode����ע����������ģ������ڼ��뵽K-serial�е�ʱ��Ҫʹ��Use Multi-Byte Character Set������Ϊ���ģ�����Ŀǰ�������¼򵥴���
					char codeDirect[256];
					//cout<<"�ҵ�������ı��Ƿ�ȫ������� "<<endl;
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
					//cout<<"�ַ�����ĳ��� �� " <<n<<endl; 
					DWORD nowsize=strlen(codeDirect);
 					returnCode = RegSetValueEx(keyRet,_T("versionTime"),NULL,REG_SZ,(unsigned char*)codeDirect,nowsize);
				}
				/***************************end ��д��ע����е����Ľ��м򵥵Ĵ���*************************/
			   //������������� ����д��ע����е����Ľ��м򵥵Ĵ��� �Ͳ�Ҫע������������
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