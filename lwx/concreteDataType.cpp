#include "concreteDataType.h"

//FMIA
FMIA::FMIA(QVector<QPointF>& _newVector,int _x,int _y):decorateDataType(_x,_y),m_newVector(_newVector)
{
	/*m_painter = NULL;
	m_value = NULL;*/
}

void FMIA::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void FMIA::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void FMIA::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLinePoOr(m_painter, m_newVector, m_x, m_y);
		longLineLIALI(m_painter, m_newVector, m_x, m_y);
	}
}

void FMIA::addCalculate()
{
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[26] != QPointF(-200.0, -200.0) && m_newVector[27] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[21], m_newVector[0], m_newVector[27], m_newVector[26]);
		if(m_value !=NULL)
			m_value[0] = angel;
	}
	else {
		if(m_value!=NULL)
			m_value[0] = -1;
	}
}

//FMA
FMA::FMA( QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void FMA::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void FMA::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void FMA::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLinePoOr(m_painter, m_newVector, m_x, m_y);
		longLineT2Me(m_painter, m_newVector, m_x, m_y);
	}
}
  
void FMA::addCalculate()
{
	//FMA
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[11] != QPointF(-200.0, -200.0) && m_newVector[10] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[0], m_newVector[21], m_newVector[10], m_newVector[11]);
		if (m_value != NULL)
			m_value[1] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[1] = -1;
	}
}

//IMPA
IMPA::IMPA(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void IMPA::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void IMPA::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void IMPA::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineLIALI(m_painter, m_newVector, m_x, m_y);
		longLineT2Me(m_painter, m_newVector, m_x, m_y);
	}
}

void IMPA::addCalculate()
{
	if (m_newVector[10] != QPointF(-200.0, -200.0) && m_newVector[11] != QPointF(-200.0, -200.0) && m_newVector[27] != QPointF(-200.0, -200.0) && m_newVector[26] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[10], m_newVector[11], m_newVector[27], m_newVector[26]);
		if (m_value != NULL)
			m_value[2] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[2] = -1;
	}
}

//SNA
SNA::SNA(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void SNA::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void SNA::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void SNA::addLineJudge()
{
	if (m_painter != NULL)
	{
		radialNS(m_painter, m_newVector, m_x, m_y);
		lineNA(m_painter, m_newVector);
	}
}

void SNA::addCalculate()
{
	if (m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[20] != QPointF(-200.0, -200.0) && m_newVector[2] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[19], m_newVector[20], m_newVector[19], m_newVector[2]);
		if (m_value != NULL)
			m_value[3] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[3] = -1;
	}
}

//SNB
SNB2::SNB2(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void SNB2::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void SNB2::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void SNB2::addLineJudge()
{
	if (m_painter != NULL)
	{
		radialNS(m_painter, m_newVector, m_x, m_y);
		lineNB(m_painter, m_newVector);
	}
}

void SNB2::addCalculate()
{
	if (m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[20] != QPointF(-200.0, -200.0) && m_newVector[6] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[19], m_newVector[20], m_newVector[19], m_newVector[6]);
		if (m_value != NULL)
			m_value[4] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[4] = -1;
	}
}

//ANB
ANB::ANB(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void ANB::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void ANB::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void ANB::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineNA(m_painter, m_newVector);
		lineNB(m_painter, m_newVector);
	}
}

void ANB::addCalculate()
{
	if (m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[2] != QPointF(-200.0, -200.0) && m_newVector[6] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[19], m_newVector[6], m_newVector[19], m_newVector[2]);
		if (m_value != NULL)
			m_value[5] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[5] = -1;
	}
}

//AO-BO
AOBO::AOBO(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void AOBO::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void AOBO::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void AOBO::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineQ1Q2(m_painter, m_newVector);
	}
}

void AOBO::addCalculate()
{
	if (m_newVector[2] != QPointF(-200.0, -200.0) && m_newVector[6] != QPointF(-200.0, -200.0) && m_newVector[24] != QPointF(-200.0, -200.0) && m_newVector[26] != QPointF(-200.0, -200.0)&& m_newVector[28] != QPointF(-200.0, -200.0) && m_newVector[29] != QPointF(-200.0, -200.0))
	{
		QPointF Q1;//UILI中点
		QPointF Q2;//U6L6中点
		Q1.setX((m_newVector[24].x() + m_newVector[26].x()) / 2);
		Q1.setY((m_newVector[24].y() + m_newVector[26].y()) / 2);
		Q2.setX((m_newVector[28].x() + m_newVector[29].x()) / 2);
		Q2.setY((m_newVector[28].y() + m_newVector[29].y()) / 2);
		QPointF C1 = footPoint(Q1,Q2,m_newVector[2]);
		QPointF C2 = footPoint(Q1,Q2,m_newVector[6]);
		double distance = lineDistance(C1,C2);
		if (m_value != NULL)
			m_value[6] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[6] = -1;
	}
}

//OP角
OP::OP(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void OP::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void OP::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void OP::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineQ1Q2(m_painter, m_newVector);
		longLinePoOr(m_painter,m_newVector,m_x,m_y);
	}
}

void OP::addCalculate()
{
	if (m_newVector[24] != QPointF(-200.0, -200.0) && m_newVector[26] != QPointF(-200.0, -200.0) && m_newVector[28] != QPointF(-200.0, -200.0) && m_newVector[29] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0))
	{
		QPointF Q1;//UILI中点
		QPointF Q2;//U6L6中点
		Q1.setX((m_newVector[24].x() + m_newVector[26].x()) / 2);
		Q1.setY((m_newVector[24].y() + m_newVector[26].y()) / 2);
		Q2.setX((m_newVector[28].x() + m_newVector[28].x()) / 2);
		Q2.setY((m_newVector[29].y() + m_newVector[29].y()) / 2);
		double angel = lineAngle(m_newVector[21], m_newVector[0], Q1, Q2);
		if (m_value != NULL)
			m_value[7] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[7] = -1;
	}
}

//Z角
Z::Z(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void Z::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void Z::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void Z::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineLLPos(m_painter, m_newVector,m_x,m_y);
		longLinePoOr(m_painter, m_newVector, m_x, m_y);
	}
}

void Z::addCalculate()
{
	if (m_newVector[40] != QPointF(-200.0, -200.0) && m_newVector[43] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[40], m_newVector[43], m_newVector[0] , m_newVector[21]);
		if (m_value != NULL)
			m_value[8] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[8] = -1;
	}
}

//上唇厚度
labrumDistance::labrumDistance(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void labrumDistance::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void labrumDistance::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void labrumDistance::addLineJudge()
{
}

void labrumDistance::addCalculate()
{
	if (m_newVector[30] != QPointF(-200.0, -200.0) && m_newVector[39] != QPointF(-200.0, -200.0))
	{
		double distance = lineDistance(m_newVector[30], m_newVector[39]);
		if (m_value != NULL)
			m_value[9] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[9] = -1;
	}
}

//全颏厚度
chinDistance::chinDistance(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void chinDistance::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void chinDistance::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void chinDistance::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineNB(m_painter, m_newVector);
	}
}

void chinDistance::addCalculate()
{
	if (m_newVector[43] != QPointF(-200.0, -200.0) && m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[6] != QPointF(-200.0, -200.0))
	{
		double distance = pointToLine(m_newVector[19], m_newVector[6],m_newVector[43]);
		if (m_value != NULL)
			m_value[10] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[10] = -1;
	}
}

//后面高
ART1::ART1(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void ART1::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void ART1::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void ART1::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineART1(m_painter, m_newVector,m_x,m_y);
	}
}

void ART1::addCalculate()
{
	if (m_newVector[13] != QPointF(-200.0, -200.0) && m_newVector[12] != QPointF(-200.0, -200.0))
	{
		double distance =lineDistance(m_newVector[13], m_newVector[12]);
		if (m_value != NULL)
			m_value[11] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[11] = -1;
	}
}

//前面高
PNSANS::PNSANS(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void PNSANS::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void PNSANS::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void PNSANS::addLineJudge()
{
	if (m_painter != NULL)
	{
		linePNSANS(m_painter, m_newVector);
	}
}

void PNSANS::addCalculate()
{
	if (m_newVector[3] != QPointF(-200.0, -200.0) && m_newVector[1] != QPointF(-200.0, -200.0))
	{
		double distance = lineDistance(m_newVector[3], m_newVector[1]);
		if (m_value != NULL)
			m_value[12] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[12] = -1;
	}
}

//面高比
surfaceHeightRatio::surfaceHeightRatio(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void surfaceHeightRatio::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void surfaceHeightRatio::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void surfaceHeightRatio::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineART1(m_painter, m_newVector, m_x, m_y);
		linePNSANS(m_painter, m_newVector);
	}
}

void surfaceHeightRatio::addCalculate()
{
	if (m_newVector[13] != QPointF(-200.0, -200.0) && m_newVector[12] != QPointF(-200.0, -200.0) && m_newVector[3] != QPointF(-200.0, -200.0) && m_newVector[1] != QPointF(-200.0, -200.0))
	{
		double distance1 = lineDistance(m_newVector[13], m_newVector[12]);
		double distance2 = lineDistance(m_newVector[3], m_newVector[1]);
		if (m_value != NULL)
			m_value[13] = distance1/distance2;
	}
	else
	{
		if (m_value != NULL)
			m_value[13] = -1;
	}
}

//面角
surfaceAngle::surfaceAngle(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void surfaceAngle::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void surfaceAngle::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void surfaceAngle::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLinePoOr(m_painter, m_newVector, m_x, m_y);
		lineNPog(m_painter, m_newVector);
	}
}

void surfaceAngle::addCalculate()
{
	if (m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[8] != QPointF(-200.0, -200.0) && m_newVector[19] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[21], m_newVector[0], m_newVector[8], m_newVector[19]);
		if (m_value != NULL)
			m_value[14] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[14] = -1;
	}
}

//颌凸角
jawRaiseAngle::jawRaiseAngle(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void jawRaiseAngle::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void jawRaiseAngle::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void jawRaiseAngle::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter,m_newVector,2,19);//段NA
		radialXtoY(m_painter, m_newVector,m_x,m_y,8,2);//射PogA
	}
}

void jawRaiseAngle::addCalculate()
{
	if (m_newVector[2] != QPointF(-200.0, -200.0) && m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[8] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[2], m_newVector[19], m_newVector[8], m_newVector[2]);
		bool symbol = judgePointAndLineRelationship(m_newVector[19], m_newVector[8], m_newVector[2]);
	
		if (m_value != NULL)
		{
			if (symbol)
			{
				m_value[15] = -angel;
			}
			else
			{
				m_value[15] = angel;
			}
			
		}
			
	}
	else
	{
		if (m_value != NULL)
			m_value[15] = -1;
	}
}

//AB面角
ABSurfaceAngle::ABSurfaceAngle(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void ABSurfaceAngle::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void ABSurfaceAngle::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void ABSurfaceAngle::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter, m_newVector, 2, 6);//段AB
		lineXtoY(m_painter, m_newVector, 19, 8);//段NPog
	}
}

void ABSurfaceAngle::addCalculate()
{
	if (m_newVector[2] != QPointF(-200.0, -200.0) && m_newVector[6] != QPointF(-200.0, -200.0) && m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[8] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[2], m_newVector[6], m_newVector[19], m_newVector[8]);
		bool symbol = judgePointAndLineRelationship(m_newVector[19], m_newVector[8], m_newVector[2]);
		if (m_value != NULL)
		{
			if (symbol)
			{
				m_value[16] = -angel;
			}
			else
			{
				m_value[16] = angel;
			}

		}
	}
	else
	{
		if (m_value != NULL)
			m_value[16] = -1;
	}
}

//下颌平面角
underjawSurfaceAngle::underjawSurfaceAngle(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void underjawSurfaceAngle::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void underjawSurfaceAngle::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void underjawSurfaceAngle::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y,21 ,0);
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 11,10);
	}
}

void underjawSurfaceAngle::addCalculate()
{
	if (m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[11] != QPointF(-200.0, -200.0) && m_newVector[10] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[21], m_newVector[0], m_newVector[11], m_newVector[10]);
		if (m_value != NULL)
			m_value[17] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[17] = -1;
	}
}

//Y轴角
YAxisAngle::YAxisAngle(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void YAxisAngle::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void YAxisAngle::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void YAxisAngle::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter, m_newVector,20, 9);
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
	}
}

void YAxisAngle::addCalculate()
{
	if (m_newVector[20] != QPointF(-200.0, -200.0) && m_newVector[9] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[20], m_newVector[9], m_newVector[21], m_newVector[0]);
		if (m_value != NULL)
			m_value[18] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[18] = -1;
	}
}

//上下中切牙角
UIUIA::UIUIA(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void UIUIA::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void UIUIA::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void UIUIA::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter, m_newVector, 24, 25);
		lineXtoY(m_painter, m_newVector, 26,27);
	}
}

void UIUIA::addCalculate()
{
	if (m_newVector[24] != QPointF(-200.0, -200.0) && m_newVector[25] != QPointF(-200.0, -200.0) && m_newVector[26] != QPointF(-200.0, -200.0) && m_newVector[27] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[24], m_newVector[25], m_newVector[26], m_newVector[27]);
		if (m_value != NULL)
			m_value[19] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[19] = -1;
	}
}

//LI-MP
LIMP::LIMP(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void LIMP::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void LIMP::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void LIMP::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector,m_x,m_y,10, 11);
		lineXtoIntersection(m_painter, m_newVector,10,11,26,27);
	}
}

void LIMP::addCalculate()
{
	if (m_newVector[10] != QPointF(-200.0, -200.0) && m_newVector[11] != QPointF(-200.0, -200.0) && m_newVector[26] != QPointF(-200.0, -200.0) && m_newVector[27] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[10], m_newVector[11], m_newVector[27], m_newVector[26]);
		if (m_value != NULL)
			m_value[20] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[20] = -1;
	}
} 

//LI-OP
LIOP::LIOP(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void LIOP::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void LIOP::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void LIOP::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineQ1Q2(m_painter, m_newVector);
		lineXtoY(m_painter, m_newVector,26, 27);
	}
}

void LIOP::addCalculate()
{
	if (m_newVector[24] != QPointF(-200.0, -200.0) && m_newVector[26] != QPointF(-200.0, -200.0) && m_newVector[28] != QPointF(-200.0, -200.0) && m_newVector[27] != QPointF(-200.0, -200.0) && m_newVector[29] != QPointF(-200.0, -200.0))
	{
		QPointF Q1;//UILI中点
		QPointF Q2;//U6L6中点
		Q1.setX((m_newVector[24].x() + m_newVector[26].x()) / 2);
		Q1.setY((m_newVector[24].y() + m_newVector[26].y()) / 2);
		Q2.setX((m_newVector[28].x() + m_newVector[29].x()) / 2);
		Q2.setY((m_newVector[28].y() + m_newVector[29].y()) / 2);
		double angel = lineAngle(m_newVector[10], m_newVector[11], m_newVector[27], m_newVector[26]);
		if (m_value != NULL)
			m_value[21] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[21] = -1;
	}
}

//上中切牙凸距
UI_APog::UI_APog(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void UI_APog::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void UI_APog::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void UI_APog::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter, m_newVector, 2, 8);
		lineXtoFoot(m_painter, m_newVector,2,8,24);
	}
}

void UI_APog::addCalculate()
{
	if (m_newVector[24] != QPointF(-200.0, -200.0) && m_newVector[2] != QPointF(-200.0, -200.0) && m_newVector[8] != QPointF(-200.0, -200.0))
	{
		double distance = pointToLine(m_newVector[2], m_newVector[8], m_newVector[24]);
		if (m_value != NULL)
			m_value[22] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[22] = -1;
	}
}

//Co-Pog
Co_Pog::Co_Pog(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void Co_Pog::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void Co_Pog::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void Co_Pog::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y,11,10);
		lineXtoFoot(m_painter, m_newVector, 11, 10, 16);
		lineXtoFoot(m_painter, m_newVector, 11, 10, 8);
	}
}

void Co_Pog::addCalculate()
{
	if (m_newVector[16] != QPointF(-200.0, -200.0) && m_newVector[8] != QPointF(-200.0, -200.0) && m_newVector[11] != QPointF(-200.0, -200.0) && m_newVector[10] != QPointF(-200.0, -200.0))
	{
		QPointF foot1 = footPoint(m_newVector[11], m_newVector[10], m_newVector[16]);
		QPointF foot2 = footPoint(m_newVector[11], m_newVector[10], m_newVector[8]);
		double distance = lineDistance(foot1,foot2);
		if (m_value != NULL)
			m_value[23] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[23] = -1;
	}
}

//Ptm-s
Ptm_S::Ptm_S(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void Ptm_S::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void Ptm_S::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void Ptm_S::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 20);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 4);
	}
}

void Ptm_S::addCalculate()
{
	if (m_newVector[20] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[4] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0))
	{
		QPointF foot1 = footPoint(m_newVector[21], m_newVector[0], m_newVector[20]);
		QPointF foot2 = footPoint(m_newVector[21], m_newVector[0], m_newVector[4]);
		double distance = lineDistance(foot1, foot2);
		if (m_value != NULL)
			m_value[24] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[24] = -1;
	}
}

//ANS-Ptm
ANS_Ptm::ANS_Ptm(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
	
}

void ANS_Ptm::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void ANS_Ptm::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void ANS_Ptm::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 1);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 4);
	}
}

void ANS_Ptm::addCalculate()
{
	if (m_newVector[1] != QPointF(-200.0, -200.0) && m_newVector[4] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		QPointF foot1 = footPoint(m_newVector[21], m_newVector[0], m_newVector[1]);
		QPointF foot2 = footPoint(m_newVector[21], m_newVector[0], m_newVector[4]);
		double distance = lineDistance(foot1, foot2);
		if (m_value != NULL)
			m_value[25] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[25] = -1;
	}
}

//Co-S
Co_S::Co_S(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void Co_S::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void Co_S::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void Co_S::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 20);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 16);
	}
}

void Co_S::addCalculate()
{
	if (m_newVector[20] != QPointF(-200.0, -200.0) && m_newVector[16] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		QPointF foot1 = footPoint(m_newVector[21], m_newVector[0], m_newVector[20]);
		QPointF foot2 = footPoint(m_newVector[21], m_newVector[0], m_newVector[16]);
		double distance = lineDistance(foot1, foot2);
		if (m_value != NULL)
			m_value[26] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[26] = -1;
	}
}


//N-Me
N_Me::N_Me(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void N_Me::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void N_Me::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void N_Me::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 19);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 10);
	}
}

void N_Me::addCalculate()
{
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[10] != QPointF(-200.0, -200.0) && m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		//判断N，Me是否在PoOr同侧
		bool temp1 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[19]);
		bool temp2 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[10]);
		double distance = 0.0;
		double distance1 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[19]);
		double distance2 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[10]);
		if (temp1 == temp2)
		{			
			if (distance1 >= distance2)
			{
				distance =distance1 -distance2;
			}
			else
			{
				distance = distance2 - distance1;
			}
		}
		else
		{
			distance = distance2 +distance1;
		}
		if (m_value != NULL)
			m_value[27] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[27] = -1;
	}
}

//N-ANS
N_ANS::N_ANS(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void N_ANS::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void N_ANS::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void N_ANS::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 19);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 1);
	}
}

void N_ANS::addCalculate()
{
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[10] != QPointF(-200.0, -200.0) && m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		//判断N，ANS是否在PoOr同侧
		bool temp1 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[19]);
		bool temp2 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[1]);
		double distance = 0.0;
		double distance1 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[19]);
		double distance2 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[1]);
		if (temp1 == temp2)
		{
			if (distance1 >= distance2)
			{
				distance = distance1 - distance2;
			}
			else
			{
				distance = distance2 - distance1;
			}
		}
		else
		{
			distance = distance2 + distance1;
		}
		if (m_value != NULL)
			m_value[28] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[28] = -1;
	}
}

//ANS-Me
ANS_Me::ANS_Me(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void ANS_Me::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void ANS_Me::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void ANS_Me::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 10);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 1);
	}
}

void ANS_Me::addCalculate()
{
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[10] != QPointF(-200.0, -200.0) && m_newVector[1] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		//判断ANS，Me是否在PoOr同侧
		bool temp1 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[1]);
		bool temp2 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[10]);
		double distance = 0.0;
		double distance1 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[1]);
		double distance2 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[10]);
		if (temp1 == temp2)
		{
			if (distance1 >= distance2)
			{
				distance = distance1 - distance2;
			}
			else
			{
				distance = distance2 - distance1;
			}
		}
		else
		{
			distance = distance2 + distance1;
		}
		if (m_value != NULL)
			m_value[29] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[29] = -1;
	}
}

//面上部高百分比
N_ANS_Ratio::N_ANS_Ratio(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void N_ANS_Ratio::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void N_ANS_Ratio::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void N_ANS_Ratio::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 10);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 1);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 19);
	}
}

void N_ANS_Ratio::addCalculate()
{
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[1] != QPointF(-200.0, -200.0) && m_newVector[10] != QPointF(-200.0, -200.0) && m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		//全面高
		//判断N，ANS是否在PoOr同侧
		bool temp1 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[19]);
		bool temp2 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[1]);
		double Alldistance = 0.0;
		double distance1 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[19]);
		double distance2 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[1]);
		if (temp1 == temp2)
		{
			if (distance1 >= distance2)
			{
				Alldistance = distance1 - distance2;
			}
			else
			{
				Alldistance = distance2 - distance1;
			}
		}
		else
		{
			Alldistance = distance2 + distance1;
		}
		//面上部高
		//判断N，ANS是否在PoOr同侧
		 temp1 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[19]);
		 temp2 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[1]);
		double upDistance = 0.0;
		 distance1 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[19]);
		distance2 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[1]);
		if (temp1 == temp2)
		{
			if (distance1 >= distance2)
			{
				upDistance = distance1 - distance2;
			}
			else
			{
				upDistance = distance2 - distance1;
			}
		}
		else
		{
				upDistance = distance2 + distance1;
		}

		if (m_value != NULL)
			m_value[30] = upDistance/Alldistance;
	}
	else
	{
		if (m_value != NULL)
			m_value[30] = -1;
	}
}

//面下部高百分比
ANS_Me_Ratio::ANS_Me_Ratio(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void ANS_Me_Ratio::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void ANS_Me_Ratio::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void ANS_Me_Ratio::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 10);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 1);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 19);
	}
}

void ANS_Me_Ratio::addCalculate()
{
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[1] != QPointF(-200.0, -200.0) && m_newVector[10] != QPointF(-200.0, -200.0) && m_newVector[19] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		//全面高
		//判断N，ANS是否在PoOr同侧
		bool temp1 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[19]);
		bool temp2 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[1]);
		double Alldistance = 0.0;
		double distance1 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[19]);
		double distance2 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[1]);
		if (temp1 == temp2)
		{
			if (distance1 >= distance2)
			{
				Alldistance = distance1 - distance2;
			}
			else
			{
				Alldistance = distance2 - distance1;
			}
		}
		else
		{
			Alldistance = distance2 + distance1;
		}
		//面下部高
		//判断ANS，Me是否在PoOr同侧
		 temp1 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[1]);
		 temp2 = judgePointAndLineRelationship(m_newVector[21], m_newVector[0], m_newVector[10]);
			double downDistance = 0.0;
		 distance1 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[1]);
		 distance2 = pointToLine(m_newVector[21], m_newVector[0], m_newVector[10]);
		if (temp1 == temp2)
		{
			if (distance1 >= distance2)
			{
				downDistance = distance1 - distance2;
			}
			else
			{
				downDistance = distance2 - distance1;
			}
		}
		else
		{
			downDistance = distance2 + distance1;
		}

		if (m_value != NULL)
			m_value[31] = downDistance / Alldistance;
	}
	else
	{
		if (m_value != NULL)
			m_value[31] = -1;
	}
}

//Ptm-U6
Ptm_U6::Ptm_U6(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{

}

void Ptm_U6::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void Ptm_U6::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void Ptm_U6::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 4);
		lineXtoFoot(m_painter, m_newVector, 21, 0, 28);
	}
}

void Ptm_U6::addCalculate()
{
	if (m_newVector[4] != QPointF(-200.0, -200.0) && m_newVector[28] != QPointF(-200.0, -200.0) && m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0))
	{
		QPointF foot1 = footPoint(m_newVector[21], m_newVector[0], m_newVector[4]);
		QPointF foot2 = footPoint(m_newVector[21], m_newVector[0], m_newVector[28]);
		double distance = lineDistance(foot1, foot2);
		if (m_value != NULL)
			m_value[32] = distance;
	}
	else
	{
		if (m_value != NULL)
			m_value[32] = -1;
	}
}

//鼻唇角
noseLabrumAngle::noseLabrumAngle(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void noseLabrumAngle::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void noseLabrumAngle::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void noseLabrumAngle::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter, m_newVector, 36, 35);
		lineXtoY(m_painter, m_newVector, 36, 38);
	}
}

void noseLabrumAngle::addCalculate()
{
	if (m_newVector[35] != QPointF(-200.0, -200.0) && m_newVector[36] != QPointF(-200.0, -200.0) && m_newVector[38] != QPointF(-200.0, -200.0) && m_newVector[27] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[36], m_newVector[35], m_newVector[36], m_newVector[38]);
		if (m_value != NULL)
			m_value[33] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[33] = -1;
	}
}

//上唇倾斜角
upperlipSlope::upperlipSlope(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void upperlipSlope::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void upperlipSlope::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate(); 
}

void upperlipSlope::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector,m_x,m_y, 21, 0);
		longLineXtoY(m_painter, m_newVector,m_x,m_y ,37, 38);
	}
}

void upperlipSlope::addCalculate()
{
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[37] != QPointF(-200.0, -200.0) && m_newVector[38] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[21], m_newVector[0], m_newVector[37], m_newVector[38]);
		if (m_value != NULL)
			m_value[34] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[34] = -1;
	}
}

//下唇倾斜角
underSlope::underSlope(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void underSlope::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void underSlope::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void underSlope::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 21, 0);
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 42, 41);
	}
}

void underSlope::addCalculate()
{
	if (m_newVector[0] != QPointF(-200.0, -200.0) && m_newVector[21] != QPointF(-200.0, -200.0) && m_newVector[41] != QPointF(-200.0, -200.0) && m_newVector[42] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[21], m_newVector[0], m_newVector[42], m_newVector[41]);
		if (m_value != NULL)
			m_value[35] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[35] = -1;
	}
}

//上下唇角
CmSnUL::CmSnUL(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void CmSnUL::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void CmSnUL::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void CmSnUL::addLineJudge()
{
	if (m_painter != NULL)
	{
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 41, 37);
		longLineXtoY(m_painter, m_newVector, m_x, m_y, 41, 42);
	}
}

void CmSnUL::addCalculate()
{
	if (m_newVector[37] != QPointF(-200.0, -200.0) && m_newVector[41] != QPointF(-200.0, -200.0) && m_newVector[42] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[41], m_newVector[37], m_newVector[41], m_newVector[42]);
		if (m_value != NULL)
			m_value[36] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[36] = -1;
	}
}

//面凸角
surfaceRaiseAngle::surfaceRaiseAngle(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void surfaceRaiseAngle::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void surfaceRaiseAngle::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void surfaceRaiseAngle::addLineJudge()
{
	
}

void surfaceRaiseAngle::addCalculate()
{
	
}

//全面凸角
allSurfaceRaiseAngle::allSurfaceRaiseAngle(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void allSurfaceRaiseAngle::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void allSurfaceRaiseAngle::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void allSurfaceRaiseAngle::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter, m_newVector, 34, 33);
		lineXtoY(m_painter, m_newVector, 34, 43);
	}
}

void allSurfaceRaiseAngle::addCalculate()
{
	if (m_newVector[33] != QPointF(-200.0, -200.0) && m_newVector[34] != QPointF(-200.0, -200.0) && m_newVector[43] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[34], m_newVector[33], m_newVector[34], m_newVector[43]);
		if (m_value != NULL)
			m_value[38] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[38] = -1;
	}
}


//颏唇沟角
LL_B_Pos::LL_B_Pos(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void LL_B_Pos::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void LL_B_Pos::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void LL_B_Pos::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter, m_newVector, 42, 41);
		lineXtoY(m_painter, m_newVector, 42, 43);
	}
}

void LL_B_Pos::addCalculate()
{
	if (m_newVector[41] != QPointF(-200.0, -200.0) && m_newVector[42] != QPointF(-200.0, -200.0) && m_newVector[43] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[42], m_newVector[41], m_newVector[42], m_newVector[43]);
		if (m_value != NULL)
			m_value[39] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[39] = -1;
	}

}

//FCA
FCA::FCA(QVector<QPointF>& _newVector, int _x, int _y) :decorateDataType(_x, _y), m_newVector(_newVector)
{
}

void FCA::drawLineJudge()
{
	decorateDataType::drawLineJudge();
	addLineJudge();
}

void FCA::datacalculate()
{
	decorateDataType::datacalculate();
	addCalculate();
}

void FCA::addLineJudge()
{
	if (m_painter != NULL)
	{
		lineXtoY(m_painter, m_newVector, 36, 32);
		radialXtoY(m_painter, m_newVector,m_x,m_y, 43, 36);
	}
}

void FCA::addCalculate()
{
	if (m_newVector[32] != QPointF(-200.0, -200.0) && m_newVector[36] != QPointF(-200.0, -200.0) && m_newVector[43] != QPointF(-200.0, -200.0))
	{
		double angel = lineAngle(m_newVector[43], m_newVector[36], m_newVector[36], m_newVector[32]);
		if (m_value != NULL)
			m_value[40] = angel;
	}
	else
	{
		if (m_value != NULL)
			m_value[40] = -1;
	}

}