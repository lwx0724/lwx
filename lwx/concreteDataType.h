#pragma once
#include "decorateDataType.h"

class FMIA : public decorateDataType
{
public:
	FMIA(QVector<QPointF>& _newVector,int _x,int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};


class FMA: public decorateDataType
{
public:
	FMA( QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};


class IMPA : public decorateDataType
{
public:
	IMPA(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class SNA : public decorateDataType
{
public:
	SNA(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class SNB2 : public decorateDataType
{
public:
	SNB2(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class ANB : public decorateDataType
{
public:
	ANB(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class AOBO : public decorateDataType
{
public:
	AOBO(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class OP : public decorateDataType
{
public:
	OP(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class Z : public decorateDataType
{
public:
	Z(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class labrumDistance : public decorateDataType
{
public:
	labrumDistance(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class chinDistance : public decorateDataType
{
public:
	chinDistance(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

//后面高
class ART1 : public decorateDataType
{
public:
	ART1(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

//前面高
class PNSANS : public decorateDataType
{
public:
	PNSANS(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class surfaceHeightRatio : public decorateDataType
{
public:
	surfaceHeightRatio(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class surfaceAngle : public decorateDataType
{
public:
	surfaceAngle(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};


class jawRaiseAngle : public decorateDataType
{
public:
	jawRaiseAngle(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class ABSurfaceAngle : public decorateDataType
{
public:
	ABSurfaceAngle(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class underjawSurfaceAngle : public decorateDataType
{
public:
	underjawSurfaceAngle(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class YAxisAngle: public decorateDataType
{
public:
	YAxisAngle(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

//上下中切牙角
class UIUIA : public decorateDataType
{
public:
	UIUIA(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class LIMP : public decorateDataType
{
public:
	LIMP(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class LIOP : public decorateDataType
{
public:
	LIOP(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

//上中切牙凸距
class UI_APog : public decorateDataType
{
public:
	UI_APog(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class Co_Pog : public decorateDataType
{
public:
	Co_Pog(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class Ptm_S : public decorateDataType
{
public:
	Ptm_S(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class ANS_Ptm : public decorateDataType
{
public:
	ANS_Ptm(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class Co_S : public decorateDataType
{
public:
	Co_S(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class N_Me : public decorateDataType
{
public:
	N_Me(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class N_ANS : public decorateDataType
{
public:
	N_ANS(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class ANS_Me : public decorateDataType
{
public:
	ANS_Me(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

//面上部高百分比
class N_ANS_Ratio : public decorateDataType
{
public:
	N_ANS_Ratio(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

//面下部高百分比
class ANS_Me_Ratio : public decorateDataType
{
public:
	ANS_Me_Ratio(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class Ptm_U6 : public decorateDataType
{
public:
	Ptm_U6(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class noseLabrumAngle : public decorateDataType
{
public:
	noseLabrumAngle(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class upperlipSlope : public decorateDataType
{
public:
	upperlipSlope(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class underSlope : public decorateDataType
{
public:
	underSlope(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

//上下唇角
class CmSnUL : public decorateDataType
{
public:
	CmSnUL(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class surfaceRaiseAngle : public decorateDataType
{
public:
	surfaceRaiseAngle(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class allSurfaceRaiseAngle : public decorateDataType
{
public:
	allSurfaceRaiseAngle(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

//颏唇沟角
class LL_B_Pos : public decorateDataType
{
public:
	LL_B_Pos(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};

class FCA : public decorateDataType
{
public:
	FCA(QVector<QPointF>& _newVector, int _x, int _y);
	void drawLineJudge();
	void datacalculate();
private:
	void addLineJudge();
	void addCalculate();
private:
	QVector<QPointF>& m_newVector;
};


