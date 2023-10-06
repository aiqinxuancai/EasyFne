#ifndef __ELIBFNE__
#define __ELIBFNE__
#include <windows.h>
#include <tchar.h>
#include <cassert>
#include <lib2.h>
#include <lang.h>
#include <fnshare.h>
#include <fnshare.cpp>

#define LIBARAYNAME "AQMessageCenter_MessageNotify"
//����
EXTERN_C void fn_NotificationPost(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
//ע��
EXTERN_C void fn_NotificationRegister(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
//��ע��
EXTERN_C void fn_NotificationUnregister(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);

EXTERN_C void fn_isCanCall(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);

EXTERN_C INT WINAPI  AQMessageCenter_MessageNotify(INT nMsg, DWORD dwParam1, DWORD dwParam2);

#ifndef __E_STATIC_LIB
#define LIB_GUID_STR "EA968347-300C-4515-7777-F1D3BA3DF67E" /*GUID��*/
#define LIB_MajorVersion 1 /*�����汾��*/
#define LIB_MinorVersion 1 /*��ΰ汾��*/
#define LIB_BuildNumber 20180810 /*�����汾��*/
#define LIB_SysMajorVer 3 /*ϵͳ���汾��*/
#define LIB_SysMinorVer 0 /*ϵͳ�ΰ汾��*/
#define LIB_KrnlLibMajorVer 3 /*���Ŀ����汾��*/
#define LIB_KrnlLibMinorVer 0 /*���Ŀ�ΰ汾��*/
#define LIB_NAME_STR "����ȫ�ֲ�������VS2017" /*֧�ֿ���*/
#define LIB_DESCRIPTION_STR "����ȫ�ֲ�������VS2017" /*��������*/
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
