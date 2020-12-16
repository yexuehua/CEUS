#include"SoftNameStringAndRegistryString.h"

const std::string g_softNameString[] =
{
	"AK",
	"BK",
	"CK",
	"EK",
	"FK",
	"GK",
	"HK",
	"LK",
	"MK",
	"OK",
	"PK",
	"VK", //LLVK 
	"SM", //CESM
	"RK", //RK
	"DK", //DK
	"CA", //CAK
	"SK", //stroke
	"PL", //PET Lung Kit
	"PM", //PET dynamic Kit
};

/************
注意：在g_registryString[] 数组中的内容要和g_softNameString[] 中的内容相对应（顺序）
**************/

const std::string g_registryString[] =
{
	"Software\\Windows_Active",		//"AK"
	"Software\\Windows_Basement",   //"BK
	"Software\\Windows_Control",	//"CK"
	"Software\\Windows_Executive",	//"EK"
	"Software\\Windows_Foottrap",	//"FK"
	"Software\\Windows_Group",  	//"FK"
	"Software\\Windows_Heat",  	    //"HK"
	"Software\\Windows_Lock",  	    //"LK",
	"Software\\Windows_Memory",     //"MK"
	"Software\\Windows_Object",		//"OK"
	"Software\\Windows_Project",	//"PK"
	"Software\\Windows_Video",		////LLVK
	"Software\\Windows_SystemActive",	////CESM
	"Software\\Windows_RebootActive",	////RK
	"Software\\Windows_DictionaryActive",	////DK
	"Software\\Windows_ControlAlphActive",	////CAK
	"Software\\Windows_StepheActiveKit",	////stroke
	"Software\\Windows_PLActiveKit",	////PET Lung Kit
	"Software\\Windows_PMActive",	////PET dynamic Kit
};
/************
注意：在g_licenseQString[] 数组中的内容要和g_softNameString[] 中的内容相对应（顺序）
**************/
const QString g_licenseQString[] = 
{
	"Ak", //AK
	"Bk", //BK
	"Ck", //CK
	"Ek", //EK
	"Fk", //FK
	"Gk", //GK
	"Hk", //HK
	"Lk", //LK
	"Mk", //MK
	"Ok", //OK
	"Pk", //PK
	"Vk", //LLVK
	"SM", //CESM
	"Rk", //RK
	"Dk", //DK
	"CA", //CAK
	"Sk",//Stroke
	"PL",//PET Lung Kit
	"PM",//PET dynamic Kit
};


const int g_MAX_SOFTER_NAME_COUNT = 99999;

int softerNameStringNameSpace::findNameIndex(std::string str)
{
	//std::cout<<"sizeof(g_softNameString)/sizeof(std::string)"<<sizeof(g_softNameString)/sizeof(std::string)<<std::endl;
	for (int i = 0; i < sizeof(g_softNameString)/sizeof(std::string); i++) {
		if(str.find(g_softNameString[i]) != std::string::npos)
		{
			std::cout<<"soft name: "<<g_softNameString[i]<<std::endl;
			return i;
		}
    }
	return g_MAX_SOFTER_NAME_COUNT;
}