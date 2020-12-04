#include "EasyFne.h"

/*
@ 常量 定义导出 
*/

#ifndef __E_STATIC_LIB

LIB_CONST_INFO constStruct[] =
{
	/*
	常量参数注释
	@ 中文名称
	@ 英文名称
	@ 常量的介绍
	@ 命令的学习难度级别
	@ 常量类型
	@ 文本类型存放的内容
	@ 布尔类型 浮点类型存放的内容
	*/
	{ _WT("ELB_VERSION"), _WT("取ELIB版本"), _WT("获取支持库版本号 返回文本型内容"), LVL_HIGH, CT_TEXT, _WT("1.0"), NULL },//文本常量
	{_WT("ELB_BOOL"),_WT("ELB布尔类型常量"),_WT("测试ELB布尔类型 常量返回布尔类型内容"),LVL_SIMPLE,CT_BOOL,NULL,1},
	{ _WT("ELB_DOUBLE"),_WT("ELB小数类型常量"),_WT("测试ELB浮点类型 常量返回浮点类型内容"),LVL_SIMPLE,CT_NUM,NULL,1}

};
/*
@ 导出 结构体类型
*/
LIB_DATA_TYPE_ELEMENT structIntType[] =
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,枚举类型 ,默认值}*/
	{ SDT_INT, NULL,_T("左边"), _T("left"), _T("left"), NULL, 0},
	{ SDT_INT, NULL,_T("定边"), _T("top"), _T("top"), NULL, 0 },
	{ SDT_INT, NULL,_T("右边"), _T("right"), _T("right"), NULL, 0 },
	{ SDT_INT, NULL,_T("底边"), _T("bottom"), _T("bottom"), NULL, 0 }
};
LIB_DATA_TYPE_ELEMENT structTypes[] =
{
	/*{ 成员类型 ,数组成员 , 中文名称 ,英文名称 ,成员解释 ,枚举类型 ,默认值}*/
	{ SDT_TEXT, NULL,_T("数据内容"), _T("data"), _T("要发送的文本数据"), NULL, 0},
	{ SDT_SHORT, NULL,_T("短整数类型"), _T("short"), _T("短整数类型测试"), NULL, 0 },
	{ SDT_FLOAT, NULL,_T("小数类型测试"), _T("float"), _T("小数类型测试"), NULL, 0 },
	{ SDT_BOOL, NULL,_T("布尔类型"), _T("Boolean"), _T("布尔类型测试"), NULL, 0 },
	{ SDT_DATE_TIME, NULL,_T("日期时间类型测试"), _T("TimeDate"), _T("日期时间类型测试"), NULL, 0 },
	{ SDT_SUB_PTR, NULL,_T("子程序指针类型测试"), _T("SUBPTR"), _T("子程序指针类型测试"), NULL, 0 },
	{ SDT_BIN, NULL,_T("字节集类型测试"), _T("bin"), _T("字节集类型测试"), NULL, 0 }
};

static LIB_DATA_TYPE_INFO DataTypes[] =
{
	/* { 中文名称, 英文名称, 数据描述, 索引数量, 命令索引, 对象状态, 图标索引, 事件数量, 事件指针, 属性数量, 属性指针, 界面指针, 元素数量, 元素指针 } */
	{ _WT("矩形"), _WT("RECT"), _WT("窗口矩形数据结构"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(structIntType) / sizeof(structIntType[0]), structIntType },
	{ _WT("复杂数据结构"), _WT("Struct"), _WT("测试多种数据类型"), 0, NULL, NULL, 0, 0, NULL, 0, NULL, NULL, sizeof(structTypes) / sizeof(structTypes[0]), structTypes }
};
#endif // !1

/*
函数的实现都需要定义在宏的外面以便静态和动态库都能使用，但ExecuteCommand，Commands则只需定义在宏的里面供动态库使用。
pRetData 输出数据指针。当对应CMD_INFO中m_dtRetType为_SDT_NULL（即定义无返回值）时，pRetData无效；
iArgCount 函数参数个数
pArgInf 函数参数指针
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
	// 所有需要库中调用的  函数  都列在这里，用逗号隔开
	AddFunc,
	SubFunc,
	MulFunc,
	DivFunc
};

static const char* const CommandNames[] =
{
	// 所有需要库中调用的  函数名  都写在这里，用逗号隔开
	"AddFunc",
	"SubFunc",
	"MulFunc",
	"DivFunc"
};
/*----------------定义支持库命令参数表-----------------------*/
ARG_INFO AddFunc_CommandArgs[] =
{
	//函数参数数组定义写在这里，每个{}为一个参数的表述，用逗号隔开
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("arg1"), _WT("arg1"), 0, 0, SDT_INT, NULL, NULL },
	{ _WT("arg2"), _WT("arg2"), 0, 0, SDT_INT, NULL, NULL }
};
ARG_INFO SubFunc_CommandArgs[] =
{
	//函数参数数组定义写在这里，每个{}为一个参数的表述，用逗号隔开
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("arg1"), _WT("arg1"), 0, 0, SDT_INT, NULL, NULL },
	{ _WT("arg2"), _WT("arg2"), 0, 0, SDT_INT, NULL, NULL }
};
ARG_INFO MulFunc_CommandArgs[] =
{
	//函数参数数组定义写在这里，每个{}为一个参数的表述，用逗号隔开
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("arg1"), _WT("arg1"), 0, 0, SDT_INT, NULL, NULL },
	{ _WT("arg2"), _WT("arg2"), 0, 0, SDT_INT, NULL, NULL }
};
ARG_INFO DivFunc_CommandArgs[] =
{
	//函数参数数组定义写在这里，每个{}为一个参数的表述，用逗号隔开
	/* { 参数名称, 参数描述, 图像索引, 图像数量, 参数类型(参见SDT_), 默认数值, 参数类别(参见AS_) } */
	{ _WT("arg1"), _WT("arg1"), 0, 0, SDT_INT, NULL, NULL },
	{ _WT("arg2"), _WT("arg2"), 0, 0, SDT_INT, NULL, NULL }
};

/*---------------声明要导出的支持库命令----------------------*/
static CMD_INFO Commands[] =
{
	/* { 中文名称, 英文名称, 对象描述, 所属类别(-1是数据类型的方法), 命令状态(CT_), 返回类型(SDT_), 此值保留, 对象等级(LVL_), 图像索引, 图像数量, 参数个数, 参数信息 } */

	//{ _WT("GetAmongText"), _WT("取关键词间文本"), _WT("截取两个关键词之间的文本"), 1,NULL, SDT_TEXT, 0, LVL_SECONDARY,0,0, 5, fnGetAmongstr_CommandArgs } ,

	{ _WT("ELIB_加法"), _WT("AddFunc"), _WT("加法运算 返回类型整数型"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 2, AddFunc_CommandArgs },
	{ _WT("ELIB_减法"), _WT("SubFunc"), _WT("减法运算 返回类型整数型"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 2, SubFunc_CommandArgs },
	{ _WT("ELIB_乘法"), _WT("MulFunc"), _WT("乘法运算 返回类型整数型"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 2, MulFunc_CommandArgs },
	{ _WT("ELIB_除法"), _WT("DivFunc"), _WT("除法运算 返回类型整数型"), 1, NULL, SDT_INT, 0, LVL_SIMPLE, 0, 0, 2, DivFunc_CommandArgs },


};

#endif
/*-----------------支持库消息处理函数------------------*/

EXTERN_C INT WINAPI ELIB_MessageNotify(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if (nMsg == NL_GET_CMD_FUNC_NAMES) // 返回所有命令实现函数的的函数名称数组(char*[]), 支持静态编译的动态库必须处理
		return (INT)CommandNames;
	else if (nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME) // 返回处理系统通知的函数名称(PFN_NOTIFY_LIB函数名称), 支持静态编译的动态库必须处理
		return (INT)LIBARAYNAME;
	else if (nMsg == NL_GET_DEPENDENT_LIBS) return (INT)NULL;
	// 返回静态库所依赖的其它静态库文件名列表(格式为\0分隔的文本,结尾两个\0), 支持静态编译的动态库必须处理
	// kernel32.lib user32.lib gdi32.lib 等常用的系统库不需要放在此列表中
	// 返回NULL或NR_ERR表示不指定依赖文件  
#endif
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
}
/*定义支持库基本信息*/
#ifndef __E_STATIC_LIB
static LIB_INFO LibInfo =
{
	/* { 库格式号, GUID串号, 主版本号, 次版本号, 构建版本号, 系统主版本号, 系统次版本号, 核心库主版本号, 核心库次版本号,
	支持库名, 支持库语言, 支持库描述, 支持库状态,
	作者姓名, 邮政编码, 通信地址, 电话号码, 传真号码, 电子邮箱, 主页地址, 其它信息,
	类型数量, 类型指针, 类别数量, 命令类别, 命令总数, 命令指针, 命令入口,
	附加功能, 功能描述, 消息指针, 超级模板, 模板描述,
	常量数量, 常量指针, 外部文件} */
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