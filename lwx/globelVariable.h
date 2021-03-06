#pragma once
#include<string>
#pragma execution_character_set("utf-8")
static const char* toothPosition_ENGLISH[]
{
	//上颌部
	"Or","ANS","A",
	"PNS","Ptm","Pt",
	//下颌部
	"B","D","Pog","Gn","Me","T2",
	"T1","Ar","Go","Pcd","Co","C","J",
	//颅底部
	"N","S","Po","Ba","Bo",
	//牙/牙槽部
	"UI","UIA","LI","LIA","U6","L6","SPr","Id",
	//软组织
	"G","NS","Prn","Cm","Sn","A'","UL'","UL","LL","LL'","B'","Pos",
	"1cmA","1cmB"
};

static const char *toothPosition_CHINA[46]
{
	"框点","前鼻棘点","上齿槽座点","后鼻棘点","翼上颌裂点","翼点",
	"下齿槽座点","下颌联合体中心点","颏前点","颏顶点","颏下点","下颌角后下缘",
	"下颌升支后缘","关节点","下颌角点","髁突后援点","髁突点","颗突中心点","内下颌角点",
	"鼻根点","蝶鞍中心点","机械耳点","颅底点","Bolton点",
	"上中切牙点","上中切牙根尖点","下切牙点","下切牙根尖点","上颌第一磨牙近中颊尖点","下颌第一磨牙近中颊尖点","上牙槽源点","下牙槽源点",
	"额点","软组织鼻根点","鼻顶点","鼻小柱点","鼻下点","上唇凹点","上唇源点","上唇突点","下唇突点","下唇源点","下唇凹点","软组织颏前点",
	"标准A","标准B"
};

//显示在视图上的文字提示
static  char *textHintOnView[]
{
	"FMIA(68°)",
	"FMA(22°～28°)",
	"IMPA(88°)",
	"SNA(80°～84°)",
	"SNB(78°～82°)",
	"ANB(1°～5°)" ,
	"AO-BO(0～4mm)",
	"OP角(8°～12°)",
	"Z角(70°～80°)",
	"上唇厚度",
	"全颏厚度",
	"后面高",
	"前面高",
	"面高比(0.65～0.75)",
	"面角",
	"颌凸角",
	"AB面角",
	"下颌平面角",
	"Y轴角(66.3°±7.1)",
	"上下中切牙角",
	"LI-MP(92.6°±7.0)",
	"LI-OP",
	"上中切牙凸距",
	"Co-Pog",
	"Ptm-s",
	"ANS-Ptm",
	"CO-S",
	"全面高N-Me",
	"面上部高N-ANS",
	"面下部高ANS-Me",
	"面上部高百分比",
	"面下部高百分比",
	"Ptm-U6",
	"鼻唇角",
	"上唇倾斜角",
	"下唇倾斜角",
	"上下唇角",
	"面凸角",
	"全面凸角",
	"颏唇沟角",
	"FCA(7.3±4.4)"
};

//文字提示单位
static  char * textUnit[]
{
	"°","°","°","°","°","°",
	"mm","°","°","mm","mm","mm","mm","","°","°","°","°","°","°","°","°","mm",
	"mm","mm","mm","mm","mm","mm","mm","","","mm",
	"°","°","°","°","°","°","°","°"
};

//测试方法名
static char * methodName[]
{
	"默认","Tweed","Downs","Wyile","软组织"
};

//记录鼠标点集+2记录标准点
static QVector<QPointF>  linePos{46, QPointF(-200.0,-200.0) };

//不同方法需要的点，不包含44、45，因为每个都需要所有且要前置添加
static const int DefalutPoint[44] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43};

static const int Tweed[21] = { 0,1,2,3,6,10,11,12,13,19,20,21,24,26,27,28,29,30,39,40,43 };

static const int Downs[16] = {0,2,6,8,9,10,11,19,20,21,24,25,26,27,28,29};

static const int Wylie[11] = {0,1,4,8,10,11,14,19,20,21,28};

static const int tissue[15] = {0,2,8,19,21,32,33,34,35,36,37,38,41,42,43};

//不同方法需要计算的数据类型，序号
static const int dataType_default[10] = { 3,4,5,14,17,18,20,24,28,29 };//具体设计的默认选项测试项

static const int dataType_default2[41] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};//自定义选项中的可选项

static const int dataType_Tweed[14] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };

static const int dataType_Downs[10] = { 14,15,16,17,18,7,19,20,21,22 };

static const int dataType_Wyile[10] = { 23,24,25,26,27,28,29,30,31,32 };

static const int dataType_tissue[9] = { 15,33,34,35,36,37,38,39,40 };


static const QVector<const int *> dataVector{ dataType_default2,dataType_Tweed,dataType_Downs,dataType_Wyile,dataType_tissue};
//不同测试方法的测试项个数
static const int  testItemNum[5] = { 41,14,10,10,9};