#include "testMethod.h"

testMethod::testMethod()
{
}

void testMethod::drawLineJudge()
{
}

void testMethod::datacalculate()
{
}

void testMethod::drawPoint(QPainter * painter, qreal x, qreal y)
{
	//设置画点时画笔的颜色，线型,线宽
	QPen pen;
	QBrush brush;
	pen.setColor(QColor(240, 40, 60));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(1);
	painter->setPen(pen);
	//设置笔刷,画实心矩形点
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(QColor(240, 40, 60));
	painter->setBrush(brush);
	//QRectF rectangle(x, y, 5, 5);
	//painter->drawRoundedRect(rectangle,15.0, 15.0);
	painter->drawRect(QRect(x - 3, y - 3, 6, 6));
}

void testMethod::drawLine(QPainter * painter, qreal startx, qreal starty, qreal endx, qreal endy)
{
	//划线深蓝色（0,0,139）
	QPen pen;
	pen.setColor(QColor(0, 0, 139));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(1);
	painter->setPen(pen);
	painter->drawLine(startx, starty, endx, endy);
}

void testMethod::drawText(QPainter * painter, qreal x, qreal y, const char * textContent)
{
	//使用字体
	QFont font;
	font.setFamily("Microsoft YaHei");
	//大小
	font.setPointSize(8);
	//设置字符间距
	font.setLetterSpacing(QFont::AbsoluteSpacing, 2);
	painter->setFont(font);
	QPen pen;
	pen.setColor(QColor(240, 40, 60));
	painter->setPen(pen);
	painter->drawText(x + 10, y, textContent);
}

void testMethod::drawlongLine(QPainter * painter, QPointF firstPoint, QPointF secondPoint,int m_x,int m_y)
{

	//划线深蓝色（0,0,139）
	QPen pen;
	pen.setColor(QColor(0, 0, 139));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(1);

	double x1 = firstPoint.x();
	double y1 = firstPoint.y();
	double x2 = secondPoint.x();
	double y2 = secondPoint.y();
	if (x2 - x1 != 0)
	{
		double a = (y2 - y1) / (x2 - x1);
		double b = (x2 * y1 - x1 * y2) / (x2 - x1);
		//QPointF topLeft(0,0);
		//QPointF rightBottom(m_x,m_y);
		//QRectF rect(topLeft,rightBottom);
		//if(rect.contains())
		QPointF newX1;
		QPointF newY1;
		if (b < 0)
		{
			newX1.setX(-b / a);
			newX1.setY(0);
		}
		else if (b >= 0 && b <= m_y)
		{
			newX1.setX(0);
			newX1.setY(b);
		}
		else if (b>m_y)
		{
			newX1.setX((m_y - b) / a);
			newX1.setY(m_y);
		}

		double  newY1_y = m_x*a + b;
		if (newY1_y < 0)
		{
			newY1.setX(-b / a);
			newY1.setY(0);
		}
		else if (newY1_y >= 0 && newY1_y <= m_y)
		{
			newY1.setX(m_x);
			newY1.setY(newY1_y);
		}
		else if (newY1_y>m_y)
		{
			newY1.setX((m_y - b) / a);
			newY1.setY(m_y);
		}
		painter->setPen(pen);
		painter->drawLine(newX1, newY1);
	}
	else
	{
		QPointF newX1(x1, 0);
		QPointF newY1(x1, m_y);
		painter->setPen(pen);
		painter->drawLine(newX1, newY1);
		return;
	}



}

void testMethod::drawRadial(QPainter * painter, QPointF firstPoint, QPointF secondPoint,int m_x,int m_y)
{
	//划线深蓝色（0,0,139）
	QPen pen;
	pen.setColor(QColor(0, 0, 139));
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(1);

	double x1 = firstPoint.x();
	double y1 = firstPoint.y();
	double x2 = secondPoint.x();
	double y2 = secondPoint.y();
	if (x2 - x1 != 0)
	{
		double a = (y2 - y1) / (x2 - x1);
		double b = (x2 * y1 - x1 * y2) / (x2 - x1);

		//判断射线方向
		if (x1 - x2 > 0)
		{
			//射线向左
			QPointF newX1;
			
			if (b < 0)
			{
				newX1.setX(-b / a);
				newX1.setY(0);
			}
			else if (b >= 0 && b <= m_y)
			{
				newX1.setX(0);
				newX1.setY(b);
			}
			else if (b>m_y)
			{
				newX1.setX((m_y - b) / a);
				newX1.setY(m_y);
			}
			painter->setPen(pen);
			painter->drawLine(firstPoint, newX1);

		}
		else
		{
			//射线向右
			QPointF newY1;
			double  newY1_y = m_x*a + b;
			if (newY1_y < 0)
			{
				newY1.setX(-b / a);
				newY1.setY(0);
			}
			else if (newY1_y >= 0 && newY1_y <= m_y)
			{
				newY1.setX(m_x);
				newY1.setY(newY1_y);
			}
			else if (newY1_y>m_y)
			{
				newY1.setX((m_y - b) / a);
				newY1.setY(m_y);
			}
			painter->setPen(pen);
			painter->drawLine(firstPoint, newY1);
		}
	
	}
	else
		return;

}

double testMethod::lineDistance(QPointF p1, QPointF p2)
{
	return sqrt(double(square(p2.x() - p1.x()) + square(p2.y() - p1.y())));
}

double testMethod::square(const double num)
{
	return num * num;
}

double testMethod::lineAngle(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{
	////用标准式表示直线，保存ABC，Ax+By+C =0
	//double A1, B1, C1;
	//double A2, B2, C2;
	//returnLineABC(p1, p2, A1, B1, C1);
	//returnLineABC(p3, p4, A2, B2, C2);

	//double v = A1*A2 + B1*B2;
	//if (v == 0)
	//	return 90;

	//double t = (A1*B2 - A2*B1) / v;
	//if (t < 0)
	//	t = -t;

	//return atan(t) * 180.0 / 3.1415927;

	//向量求角度
	QPointF newVector1;//向量p1p2
	QPointF newVector2;//向量p3p4
	newVector1.setX(p2.x()-p1.x());
	newVector1.setY(p2.y()-p1.y());
	newVector2.setX(p4.x()-p4.x());
	newVector2.setY(p4.y()-p4.x());
	//acos(v1*v2/||v1||||v2||)
	double  product = newVector1.x()* newVector2.x() + newVector1.y() + newVector2.y();
	double temp = sqrt(square(newVector1.x())+square(newVector1.y()))*sqrt(square(newVector2.x())+square(newVector2.y()));
	return  acos(product / temp)* 180.0 / 3.1415927;
}

void testMethod::returnLineABC(QPointF p1, QPointF p2, double & A, double & B, double & C)
{
	if (p1.x() == p2.x())
	{
		A = 1;
		B = 0;
		C = -p1.x();
	}
	else if (p1.y() == p2.y())
	{
		A = 0;
		B = 1;
		C = -p1.y();
	}
	else
	{
		A = p2.y() - p1.y();
		B = p1.x() - p2.x();
		C = p2.x()*p1.y() - p1.x()*p2.y();
	}
}

double testMethod::pointToLine(QPointF p1, QPointF p2, QPointF P3)
{
	double A1, B1, C1;
	returnLineABC(p1, p2, A1, B1, C1);
	//   d = ( Ax0 + By0 + C ) / sqrt ( A*A + B*B );

	return (A1*P3.x() + B1*P3.y() + C1) / sqrt(A1*A1+B1*B1);
}

QPointF testMethod::footPoint(QPointF p1, QPointF p2, QPointF P3)
{
	double A1, B1, C1;
	returnLineABC(p1, p2, A1, B1, C1);
	//x = (  B*B*x0  -  A*B*y0  -  A*C  ) / ( A*A + B*B );
	//y = (-A*B*x0 + A*A*y0 - B*C) / (A*A + B*B);
	QPointF foot;
	foot.setX((B1*B1*P3.x()-A1*B1*P3.y()-A1*C1) / (A1*A1 + B1 + B1));
	foot.setY(((-A1)*B1*P3.x()+A1*A1*P3.y()-B1*C1)/(A1*A1+B1*B1));
	return foot;
}

bool testMethod::judgePointAndLineRelationship(QPointF p1, QPointF p2, QPointF p3)
{
	double x1 = p1.x();
	double y1 = p1.y();
	double x2 = p2.x();
	double y2 = p2.y();
	double a = (y2 - y1) / (x2 - x1);
	double b = (x2 * y1 - x1 * y2) / (x2 - x1);

	if ((a*p3.x() + b) > p3.y())//点在直线下方
	{
		return false;
	}
	else
	{
		return true;
	}
}

QPointF testMethod::lineIntersection(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{
	double A1, B1, C1;
	returnLineABC(p1, p2, A1, B1, C1);
	double A2, B2, C2;
	returnLineABC(p1, p2, A2, B2, C2);
	QPointF intersection;//向量p1p2
	double D = A1*B2 - A2*B1;
	if (D != 0)
	{
		intersection.setX((B1*C2 - B2*C1) / D);
		intersection.setY((A2*C1 - A1*C2) / D);
		return intersection;
	}
	else
	{
		return p4;
	}

}

void testMethod::longLinePoOr(QPainter * painter, QVector<QPointF>& _newVector, int _x, int _y)
{
	//or与po
	if (_newVector[0] != QPointF(-200.0, -200.0) && _newVector[21] != QPointF(-200.0, -200.0))
	{
		drawlongLine(painter, _newVector[0], _newVector[21], _x,  _y);
	}
}

void testMethod::longLineLIALI(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y)
{
	//LIA与LI
	if (_newVector[27] != QPointF(-200.0, -200.0) && _newVector[26] != QPointF(-200.0, -200.0))
	{
		drawlongLine(painter, _newVector[27], _newVector[26],m_x,m_y);
	}
}

void testMethod::longLineT2Me(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y)
{
	//T2与me
	if (_newVector[10] != QPointF(-200.0, -200.0) && _newVector[11] != QPointF(-200.0, -200.0))
	{
		drawlongLine(painter, _newVector[10], _newVector[11],m_x,m_y);
	}
}

void testMethod::longLineLLPos(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y)
{
	if (_newVector[40] != QPointF(-200.0, -200.0) && _newVector[43] != QPointF(-200.0, -200.0))
	{
		drawlongLine(painter, _newVector[40], _newVector[43], m_x, m_y);
	}
}

void testMethod::longLineART1(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y)
{
	if (_newVector[13] != QPointF(-200.0, -200.0) && _newVector[12] != QPointF(-200.0, -200.0))
	{
		drawlongLine(painter, _newVector[13], _newVector[12], m_x, m_y);
	}
}

void testMethod::lineNA(QPainter * painter, QVector<QPointF>& _newVector)
{
	//段NA
	if (_newVector[19] != QPointF(-200.0, -200.0) && _newVector[2] != QPointF(-200.0, -200.0))
	{
		drawLine(painter, _newVector[19].x(), _newVector[19].y(),_newVector[2].x(),_newVector[2].y());
	}
}

void testMethod::lineNB(QPainter * painter, QVector<QPointF>& _newVector)
{
	if (_newVector[19] != QPointF(-200.0, -200.0) && _newVector[6] != QPointF(-200.0, -200.0))
	{
		drawLine(painter, _newVector[19].x(), _newVector[19].y(), _newVector[6].x(), _newVector[6].y());
	}
}

void testMethod::linePNSANS(QPainter * painter, QVector<QPointF>& _newVector)
{
	if (_newVector[3] != QPointF(-200.0, -200.0) && _newVector[1] != QPointF(-200.0, -200.0))
	{
		drawLine(painter, _newVector[3].x(), _newVector[3].y(), _newVector[1].x(), _newVector[1].y());
	}
}

void testMethod::lineNPog(QPainter * painter, QVector<QPointF>& _newVector)
{
	if (_newVector[8] != QPointF(-200.0, -200.0) && _newVector[19] != QPointF(-200.0, -200.0))
	{
		drawLine(painter, _newVector[8].x(), _newVector[8].y(), _newVector[19].x(), _newVector[19].y());
	}
}

void testMethod::lineXtoIntersection(QPainter * painter, QVector<QPointF>& _newVector, int i, int j, int m, int n)
{
	if (_newVector[10] != QPointF(-200.0, -200.0) && _newVector[11] != QPointF(-200.0, -200.0) && _newVector[26] != QPointF(-200.0, -200.0) && _newVector[27] != QPointF(-200.0, -200.0))
	{
		QPointF intersection = lineIntersection(_newVector[10], _newVector[11], _newVector[26], _newVector[27]);
		drawLine(painter, _newVector[m].x(), _newVector[m].y(),intersection.x(), intersection.y());
	}
	
}

void testMethod::lineXtoFoot(QPainter * painter, QVector<QPointF>& _newVector, int i, int j, int m)
{
	QPointF temp =footPoint(_newVector[i], _newVector[j], _newVector[m]);//垂足
	drawLine(painter, _newVector[m].x(), _newVector[m].y(), temp.x(), temp.y());
}


void testMethod::lineQ1Q2(QPainter * painter, QVector<QPointF>& _newVector)
{
	if (_newVector[24] != QPointF(-200.0, -200.0) && _newVector[26] != QPointF(-200.0, -200.0) && _newVector[28] != QPointF(-200.0, -200.0) && _newVector[29] != QPointF(-200.0, -200.0))
	{
		QPointF Q1;//UILI中点
		QPointF Q2;//U6L6中点
		Q1.setX((_newVector[24].x()+_newVector[26].x())/2);
		Q1.setY((_newVector[24].y()+_newVector[26].y())/2);
		Q2.setX((_newVector[28].x() + _newVector[29].x()) / 2);
		Q2.setY((_newVector[28].y() + _newVector[29].y()) / 2);
		drawLine(painter, Q1.x(), Q1.y(), Q2.x(), Q2.y());
	}
}

void testMethod::radialNS(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y)
{
	//射线NS
	if (_newVector[19] != QPointF(-200.0, -200.0) && _newVector[20] != QPointF(-200.0, -200.0))
	{
		drawRadial(painter, _newVector[19], _newVector[20],m_x,m_y);
	}

}

void testMethod::longLineXtoY(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y, int i, int j)
{
	if (_newVector[i] != QPointF(-200.0, -200.0) && _newVector[j] != QPointF(-200.0, -200.0))
	{
		drawlongLine(painter, _newVector[i], _newVector[j], m_x, m_y);
	}
}

void testMethod::lineXtoY(QPainter * painter, QVector<QPointF>& _newVector, int i, int j)
{
	if (_newVector[i] != QPointF(-200.0, -200.0) && _newVector[j] != QPointF(-200.0, -200.0))
	{
		drawLine(painter, _newVector[i].x(), _newVector[i].y(), _newVector[j].x(), _newVector[j].y());
	}
}

void testMethod::radialXtoY(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y, int i, int j)
{
	//射线NS
	if (_newVector[i] != QPointF(-200.0, -200.0) && _newVector[j] != QPointF(-200.0, -200.0))
	{
		drawRadial(painter, _newVector[i], _newVector[j], m_x, m_y);
	}
}


void testMethod::drawStructurePoint(QPainter * painter, QVector<QPointF>& _newVector, int structNumber)
{
	for (int i = 0; i < structNumber; i++)
	{
		if (_newVector[i] != QPointF(-200.0, -200.0))
			drawPoint(painter, _newVector[i].x(), _newVector[i].y());
	}
}

void testMethod::drawStructureText(QPainter * painter, QVector<QPointF>& _newVector, int structNumber)
{

	for (int i = 0; i <46; i++)
	{
		if (_newVector[i] != QPointF(-200.0, -200.0))
			drawText(painter, _newVector[i].x(), _newVector[i].y(), toothPosition_ENGLISH[i]);
	}
}

void testMethod::drawStandardLine(QPainter * painter, QVector<QPointF>& _newVector)
{
	if (_newVector[44] != QPointF(-200.0, -200.0)&& _newVector[45] != QPointF(-200.0, -200.0))
		drawLine(painter, _newVector[44].x(), _newVector[44].y(), _newVector[45].x(), _newVector[45].y());
}
