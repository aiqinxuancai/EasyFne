#ifndef __ELIBFNE__
#define __ELIBFNE__
#include <windows.h>
#include <tchar.h>
#include <cassert>
#include <lib2.h>
#include <lang.h>
#include <fnshare.h>
#include <fnshare.cpp>

#define LIBARAYNAME "ELIB_MessageNotify"
EXTERN_C void AddFunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf);
EXTERN_C void SubFunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf);
EXTERN_C void MulFunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf);
EXTERN_C void DivFunc(PMDATA_INF pRetData, INT iArgCount, PMDATA_INF pArgInf);
EXTERN_C INT WINAPI  ELIB_MessageNotify(INT nMsg, DWORD dwParam1, DWORD dwParam2);
#ifndef __E_STATIC_LIB
#define LIB_GUID_STR "{0961812A-BCF6-4639-90C6-64AB71945D22}" /*GUID��*/
#define LIB_MajorVersion 1 /*�����汾��*/
#define LIB_MinorVersion 1 /*��ΰ汾��*/
#define LIB_BuildNumber 20180810 /*�����汾��*/
#define LIB_SysMajorVer 3 /*ϵͳ���汾��*/
#define LIB_SysMinorVer 0 /*ϵͳ�ΰ汾��*/
#define LIB_KrnlLibMajorVer 3 /*���Ŀ����汾��*/
#define LIB_KrnlLibMinorVer 0 /*���Ŀ�ΰ汾��*/
#define LIB_NAME_STR "Elib_TEST" /*֧�ֿ���*/
#define LIB_DESCRIPTION_STR "VS2019+(runtime14.1-xp)��װ����" /*��������*/
#define LIB_Author "" /*��������*/
#define LIB_ZipCode "" /*��������*/
#define LIB_Address "" /*ͨ�ŵ�ַ*/
#define LIB_Phone	"" /*�绰����*/
#define LIB_Fax		"" /*QQ����*/
#define LIB_Email	 "" /*��������*/
#define LIB_HomePage "" /*��ҳ��ַ*/
#define LIB_Other	"" /*������Ϣ*/
#define LIB_TYPE_COUNT 1 /*�����������*/
#define LIB_TYPE_STR "0000��������\0""\0" /*�������*/
#endif

#endif
