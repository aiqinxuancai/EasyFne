#include "EasyFne.h"

/*
@ ���� ���嵼�� 
*/

#ifndef __E_STATIC_LIB

LIB_CONST_INFO constStruct[] =
{
	/*
	��������ע��
	@ ��������
	@ Ӣ������
	@ �����Ľ���
	@ �����ѧϰ�Ѷȼ���
	@ ��������
	@ �ı����ʹ�ŵ�����
	@ �������� �������ʹ�ŵ�����
	*/
	{ _WT("ELB_VERSION"), _WT("ȡELIB�汾"), _WT("��ȡ֧�ֿ�汾�� �����ı�������"), LVL_HIGH, CT_TEXT, _WT("1.0"), NULL },//�ı�����
	{_WT("ELB_BOOL"),_WT("ELB�������ͳ���"),_WT("����ELB�������� �������ز�����������"),LVL_SIMPLE,CT_BOOL,NULL,1},
	{ _WT("ELB_DOUBLE"),_WT("ELBС�����ͳ���"),_WT("����ELB�������� �������ظ�����������"),LVL_SIMPLE,CT_NUM,NULL,1}

};
/*
@ ���� �ṹ������
*/
LIB_DATA_TYPE_ELEMENT structIntType[] =
{
	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,ö������ ,Ĭ��ֵ}*/
	{ SDT_INT, NULL,_T("���"), _T("left"), _T("left"), NULL, 0},
	{ SDT_INT, NULL,_T("����"), _T("top"), _T("top"), NULL, 0 },
	{ SDT_INT, NULL,_T("�ұ�"), _T("right"), _T("right"), NULL, 0 },
	{ SDT_INT, NULL,_T("�ױ�"), _T("bottom"), _T("bottom"), NULL, 0 }
};
LIB_DATA_TYPE_ELEMENT structTypes[] =
{
	/*{ ��Ա���� ,�����Ա , �������� ,Ӣ������ ,��Ա���� ,ö������ ,Ĭ��ֵ}*/
	{ SDT_TEXT, NULL,_T("��������"), _T("data"), _T("Ҫ���͵��ı�����"), NULL, 0},
	{ SDT_SHORT, NULL,_T("����������"), _T("short"), _T("���������Ͳ���"), NULL, 0 },
	{ SDT_FLOAT, NULL,_T("С�����Ͳ���"), _T("float"), _T("С�����Ͳ���"), NULL, 0 },
	{ SDT_BOOL, NULL,_T("��������"), _T("Boolean"), _T("�������Ͳ���"), NULL, 0 },
	{ SDT_DATE_TIME, NULL,_T("����ʱ�����Ͳ���"), _T("TimeDate"), _T("����ʱ�����Ͳ���"), NULL, 0 },
	{ SDT_SUB_PTR, NULL,_T("�ӳ���ָ�����Ͳ���"), _T("SUBPTR"), _T("�ӳ���ָ�����Ͳ���"), NULL, 0 },
	{ SDT_BIN, NULL,_T("�ֽڼ����Ͳ���"), _T("bin"), _T("�ֽڼ����Ͳ���"), NULL, 0 }
};

static LIB_DATA_TYPE_INFO DataTypes[] =
{
	/* { ��������, Ӣ������, ��������, ��������, ��������, ����״̬, ͼ������, �¼�����, �¼�ָ��, ��������, ����ָ��, ����ָ��, Ԫ������, Ԫ��ָ�� } */
	{ _WT("����"), _WT("RECT"), _WT("���ھ������ݽṹ"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(structIntType) / sizeof(structIntType[0]), structIntType },
	{ _WT("�������ݽṹ"), _WT("Struct"), _WT("���Զ�����������"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(structTypes) / sizeof(structTypes[0]), structTypes }
};
#endif // !1

/*
������ʵ�ֶ���Ҫ�����ں�������Ա㾲̬�Ͷ�̬�ⶼ��ʹ�ã���ExecuteCommand��Commands��ֻ�趨���ں�����湩��̬��ʹ�á�
pRetData �������ָ�롣����ӦCMD_INFO��m_dtRetTypeΪ_SDT_NULL���������޷���ֵ��ʱ��pRetData��Ч��
iArgCount ������������
pArgInf ��������ָ��
*/
EXTERN_C void AddFunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	if (iArgCount==2)
	{
		pRetData->m_int = pArgInf[0].m_int + pArgInf[1].m_int;
	}
	return;
}

EXTERN_C void SubFunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	if (iArgCount == 2)
	{
		pRetData->m_int = pArgInf[0].m_int - pArgInf[1].m_int;
	}
	return;
}

EXTERN_C void MulFunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	if (iArgCount == 2)
	{
		pRetData->m_int = pArgInf[0].m_int * pArgInf[1].m_int;
	}
	return;
}

EXTERN_C void DivFunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf)
{
	if (iArgCount == 2 && pArgInf[0].m_int!=0)
	{
		pRetData->m_int = pArgInf[0].m_int / pArgInf[1].m_int;
	}
	return;
}


#ifndef __E_STATIC_LIB
PFN_EXECUTE_CMD ExecuteCommand[] =
{
	// ������Ҫ���е��õ�  ����  ����������ö��Ÿ���
	AddFunc,
	SubFunc,
	MulFunc,
	DivFunc
};

static const char* const CommandNames[] =
{
	// ������Ҫ���е��õ�  ������  ��д������ö��Ÿ���
	"AddFunc",
	"SubFunc",
	"MulFunc",
	"DivFunc"
};
/*----------------����֧�ֿ����������-----------------------*/
ARG_INFO AddFunc_CommandArgs[] =
{
	//�����������鶨��д�����ÿ��{}Ϊһ�������ı������ö��Ÿ���
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("arg1"), _WT("arg1"), 0, 0, SDT_INT, NULL, NULL },
	{ _WT("arg2"), _WT("arg2"), 0, 0, SDT_INT, NULL, NULL }
};
ARG_INFO SubFunc_CommandArgs[] =
{
	//�����������鶨��д�����ÿ��{}Ϊһ�������ı������ö��Ÿ���
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("arg1"), _WT("arg1"), 0, 0, SDT_INT, NULL, NULL },
	{ _WT("arg2"), _WT("arg2"), 0, 0, SDT_INT, NULL, NULL }
};
ARG_INFO MulFunc_CommandArgs[] =
{
	//�����������鶨��д�����ÿ��{}Ϊһ�������ı������ö��Ÿ���
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("arg1"), _WT("arg1"), 0, 0, SDT_INT, NULL, NULL },
	{ _WT("arg2"), _WT("arg2"), 0, 0, SDT_INT, NULL, NULL }
};
ARG_INFO DivFunc_CommandArgs[] =
{
	//�����������鶨��д�����ÿ��{}Ϊһ�������ı������ö��Ÿ���
	/* { ��������, ��������, ͼ������, ͼ������, ��������(�μ�SDT_), Ĭ����ֵ, �������(�μ�AS_) } */
	{ _WT("arg1"), _WT("arg1"), 0, 0, SDT_INT, NULL, NULL },
	{ _WT("arg2"), _WT("arg2"), 0, 0, SDT_INT, NULL, NULL }
};

/*---------------����Ҫ������֧�ֿ�����----------------------*/
static CMD_INFO Commands[] =
{
	/* { ��������, Ӣ������, ��������, �������(-1���������͵ķ���), ����״̬(CT_), ��������(SDT_), ��ֵ����, ����ȼ�(LVL_), ͼ������, ͼ������, ��������, ������Ϣ } */

	//{ _WT("GetAmongText"), _WT("ȡ�ؼ��ʼ��ı�"), _WT("��ȡ�����ؼ���֮����ı�"), 1,NULL, SDT_TEXT, 0, LVL_SECONDARY,0,0, 5, fnGetAmongstr_CommandArgs } ,

	{ _WT("ELIB_�ӷ�"), _WT("AddFunc"), _WT("�ӷ����� ��������������"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 2, AddFunc_CommandArgs },
	{ _WT("ELIB_����"), _WT("SubFunc"), _WT("�������� ��������������"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 2, SubFunc_CommandArgs },
	{ _WT("ELIB_�˷�"), _WT("MulFunc"), _WT("�˷����� ��������������"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 2, MulFunc_CommandArgs },
	{ _WT("ELIB_����"), _WT("DivFunc"), _WT("�������� ��������������"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 2, DivFunc_CommandArgs },


};

#endif
/*-----------------֧�ֿ���Ϣ������------------------*/

EXTERN_C INT WINAPI ELIB_MessageNotify(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // ������������ʵ�ֺ����ĵĺ�����������(char*[]), ֧�־�̬����Ķ�̬����봦��
		return (INT)CommandNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // ���ش���ϵͳ֪ͨ�ĺ�������(PFN_NOTIFY_LIB��������), ֧�־�̬����Ķ�̬����봦��
		return (INT)LIBARAYNAME;
	else if (nMsg == NL_GET_DEPENDENT_LIBS) return (INT)NULL;
	// ���ؾ�̬����������������̬���ļ����б�(��ʽΪ\0�ָ����ı�,��β����\0), ֧�־�̬����Ķ�̬����봦��
	// kernel32.lib user32.lib gdi32.lib �ȳ��õ�ϵͳ�ⲻ��Ҫ���ڴ��б���
	// ����NULL��NR_ERR��ʾ��ָ�������ļ�  
#endif
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
}
/*����֧�ֿ������Ϣ*/
#ifndef __E_STATIC_LIB
static LIB_INFO LibInfo =
{
	/* { ���ʽ��, GUID����, ���汾��, �ΰ汾��, �����汾��, ϵͳ���汾��, ϵͳ�ΰ汾��, ���Ŀ����汾��, ���Ŀ�ΰ汾��,
	֧�ֿ���, ֧�ֿ�����, ֧�ֿ�����, ֧�ֿ�״̬,
	��������, ��������, ͨ�ŵ�ַ, �绰����, �������, ��������, ��ҳ��ַ, ������Ϣ,
	��������, ����ָ��, �������, �������, ��������, ����ָ��, �������,
	���ӹ���, ��������, ��Ϣָ��, ����ģ��, ģ������,
	��������, ����ָ��, �ⲿ�ļ�} */
	LIB_FORMAT_VER,
	_T(LIB_GUID_STR),
	LIB_MajorVersion,
	LIB_MinorVersion,
	LIB_BuildNumber,
	LIB_SysMajorVer,
	LIB_SysMinorVer,
	LIB_KrnlLibMajorVer,
	LIB_KrnlLibMinorVer,
	_T(LIB_NAME_STR),
	__GBK_LANG_VER,
	_WT(LIB_DESCRIPTION_STR),
	_LIB_OS(__OS_WIN),
	_WT(LIB_Author),
	_WT(LIB_ZipCode),
	_WT(LIB_Address),
	_WT(LIB_Phone),
	_WT(LIB_Fax),
	_WT(LIB_Email),
	_WT(LIB_HomePage),
	_WT(LIB_Other),
	sizeof(DataTypes) / sizeof(DataTypes[0]),
	DataTypes,
	LIB_TYPE_COUNT,
	_WT(LIB_TYPE_STR),
	sizeof(Commands) / sizeof(Commands[0]),
	Commands,
	ExecuteCommand,
	NULL,
	NULL,
	ELIB_MessageNotify,
	NULL,
	NULL,
	sizeof(constStruct) / sizeof(constStruct[0]),
	constStruct,
	NULL
};
PLIB_INFO WINAPI GetNewInf()
{
	return (&LibInfo);
};
#endif