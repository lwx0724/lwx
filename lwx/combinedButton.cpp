#include "combinedButton.h"

combinedButton::combinedButton( qreal _posX, qreal _posY, MyItem *item, tutorialCartoon *cartoon,QWidget *parent )
	:posX(_posX), posY(_posY)
{
	 pixmap_havePos =new QPixmap(".\\Black\\success.png");
	 pixmap_noPos =new QPixmap(".\\Black\\warning.png");
	
	bgroup = new QButtonGroup(parent);
	int bigWidth = 40;
	int bigHeight = 20;
	int smallWidth = 15;
	int smallHeight = 15;

	currentIndex_big = 0;
	currentIndex_small = 0;
	
	bInitialize = false;
	//上颌部排列
	//lable
	pLabelgroup[0] = new  QLabel(parent);
	pLabelgroup[0]->setText("上颌部");
	pLabelgroup[0]->setStyleSheet("color:white");
	pLabelgroup[0]->setGeometry(posX,posY,75,20);
	for (int i = 0; i < 6; i++)
	{
		bigGroup[i] = new QPushButton(parent);
		smallGroup[i] = new QPushButton(parent);
		bgroup->addButton(bigGroup[i],i*2);
		bgroup->addButton(smallGroup[i], i * 2 + 1);
		bigGroup[i]->setGeometry(posX, posY+(i+1)*25, bigWidth, bigHeight);//QString(QLatin1String(toothPosition_ENGLISH[0]))

		smallGroup[i]->setGeometry(posX + bigWidth + 5, posY + 5+(i+1)*25, smallWidth, smallHeight);
	}

	//下颌部排列
	pLabelgroup[1] = new  QLabel(parent);
	pLabelgroup[1]->setText("下颌部");
	pLabelgroup[1]->setStyleSheet("color:white");
	pLabelgroup[1]->setGeometry(posX+80, posY, 75, 20);

	for (int i = 6; i < 19; i++)
	{
		bigGroup[i] = new QPushButton(parent);
		smallGroup[i] = new QPushButton(parent);
		bgroup->addButton(bigGroup[i], i * 2);
		bgroup->addButton(smallGroup[i], i * 2 + 1);
		bigGroup[i]->setGeometry(posX+80, posY + (i-5) * 25, bigWidth, bigHeight);//QString(QLatin1String(toothPosition_ENGLISH[0]))
		
		smallGroup[i]->setGeometry(posX+80 + bigWidth + 5, posY + 5 + (i-5) * 25, smallWidth, smallHeight);
	}

	//颅底部排列
	pLabelgroup[2] = new  QLabel(parent);
	pLabelgroup[2]->setText("颅底部");
	pLabelgroup[2]->setStyleSheet("color:white");
	pLabelgroup[2]->setGeometry(posX +160, posY, 75, 20);

	for (int i = 19; i < 24; i++)
	{
		bigGroup[i] = new QPushButton(parent);
		smallGroup[i] = new QPushButton(parent);
		bgroup->addButton(bigGroup[i], i * 2);
		bgroup->addButton(smallGroup[i], i * 2 + 1);
		bigGroup[i]->setGeometry(posX +160, posY + (i - 18) * 25, bigWidth, bigHeight);//QString(QLatin1String(toothPosition_ENGLISH[0]))

		smallGroup[i]->setGeometry(posX + 160 + bigWidth + 5, posY + 5 + (i - 18) * 25, smallWidth, smallHeight);

	}


	//牙\牙槽部
	pLabelgroup[3] = new  QLabel(parent);
	pLabelgroup[3]->setText("牙\\牙槽部");
	pLabelgroup[3]->setStyleSheet("color:white");
	pLabelgroup[3]->setGeometry(posX + 240, posY, 75, 20);
	for (int i = 24; i <32; i++)
	{
		bigGroup[i] = new QPushButton(parent);
		smallGroup[i] = new QPushButton(parent);
		bgroup->addButton(bigGroup[i], i * 2);
		bgroup->addButton(smallGroup[i], i * 2 + 1);
		bigGroup[i]->setGeometry(posX + 240, posY + (i - 23) * 25, bigWidth, bigHeight);//QString(QLatin1String(toothPosition_ENGLISH[0]))

		smallGroup[i]->setGeometry(posX + 240 + bigWidth + 5, posY + 5 + (i - 23) * 25, smallWidth, smallHeight);
	}

	//软组织
	pLabelgroup[4] = new  QLabel(parent);
	pLabelgroup[4]->setText("软组织");
	pLabelgroup[4]->setStyleSheet("color:white");
	pLabelgroup[4]->setGeometry(posX + 320, posY, 75, 20);
	for (int i = 32; i <44; i++)
	{
		bigGroup[i] = new QPushButton(parent);
		smallGroup[i] = new QPushButton(parent);
		bgroup->addButton(bigGroup[i], i * 2);
		bgroup->addButton(smallGroup[i], i * 2 + 1);
		bigGroup[i]->setGeometry(posX + 320, posY + (i - 31) * 25, bigWidth, bigHeight);//QString(QLatin1String(toothPosition_ENGLISH[0]))

		smallGroup[i]->setGeometry(posX + 320 + bigWidth + 5, posY + 5 + (i - 31) * 25, smallWidth, smallHeight);
	}
	

	bigGroup[44] = new QPushButton(parent);
	smallGroup[44] = new QPushButton(parent);

	bgroup->addButton(bigGroup[44], 44* 2);
	bgroup->addButton(smallGroup[44], 44 * 2 + 1);
	bigGroup[44]->setGeometry(posX + 240, (parent->height() - 40) / 2, 50, 30);//QString(QLatin1String(toothPosition_ENGLISH[0]))
	bigGroup[44]->setText("标准点A");
	bigGroup[44]->setCheckable(true);
	bigGroup[44]->setAutoExclusive(true);
	bigGroup[44]->installEventFilter(this);
	smallGroup[44]->setGeometry(posX + 290, (parent->height() - 40) / 2+10, 20, 20);
	smallGroup[44]->setCheckable(true);
	smallGroup[44]->setAutoExclusive(true);
	smallGroup[44]->setFlat(true);
	smallGroup[44]->setStyleSheet(" border-color: #E6E6FA;border-width: 1px;border-style: solid;");
	smallGroup[44]->installEventFilter(this);



	bigGroup[45] = new QPushButton(parent);
	smallGroup[45] = new QPushButton(parent);

	
	bgroup->addButton(bigGroup[45],45*2); 
	bgroup->addButton(smallGroup[45],45*2+1);
	bigGroup[45]->setGeometry(posX + 320, (parent->height() - 40) / 2, 50, 30);//QString(QLatin1String(toothPosition_ENGLISH[0]))
	bigGroup[45]->setText("标准点B");
	bigGroup[45]->setCheckable(true);
	bigGroup[45]->setAutoExclusive(true);
	bigGroup[45]->installEventFilter(this);
	smallGroup[45]->setGeometry(posX + 370, (parent->height() - 40) / 2+10, 20, 20);
	smallGroup[45]->setCheckable(true);
	smallGroup[45]->setAutoExclusive(true);
	smallGroup[45]->setFlat(true);
	smallGroup[45]->setStyleSheet(" border-color: #E6E6FA;border-width: 1px;border-style: solid;");
	smallGroup[45]->installEventFilter(this);


	//44个按钮的通用设置
	for (int i = 0; i < 44; i++)
	{
		bigGroup[i]->setToolTip(toothPosition_CHINA[i]);
		bigGroup[i]->setText(toothPosition_ENGLISH[i]);
		bigGroup[i]->setCheckable(true);
		bigGroup[i]->setAutoExclusive(true);
		bigGroup[i]->installEventFilter(this);

		smallGroup[i]->setCheckable(true);
		smallGroup[i]->setAutoExclusive(true);
		smallGroup[i]->setFlat(true);
		smallGroup[i]->setStyleSheet(" border-color: #E6E6FA;border-width: 1px;border-style: solid;");
		smallGroup[i]->installEventFilter(this);

	}

	connect(this, SIGNAL(buttonNumberInfo(int &)), item, SLOT(infoRecvUpdata(int &)));
	connect(this, SIGNAL(buttonNumberInfo(int &)), cartoon, SLOT(infoRecvCartoon(int &)));
	connect(this, SIGNAL(smallInfo(int &)), item, SLOT(infoRecvClear(int &)));
	connect(this, SIGNAL(smallInfo2(int &)), item, SLOT(infoRecvClear2(int &)));

	text = new int[46];//初始化测试方法，默认为全部
	text[0] = 44;
	text[1] = 45;
	for (int i = 2; i < 46; i++)
	{
		text[i] = i - 2;
	}
	topNum = 46;
	
	//初始化自定义点
	num = 2;
	customPoint = new int[num];
	customPoint[0] = 44; customPoint[1] = 45;
}

bool combinedButton::eventFilter(QObject * obj, QEvent * e)
{
	for (int i = 0; i < 46; i++)
	{
		if (obj == bigGroup[i])
		{
			if (e->type() == QEvent::MouseButtonRelease)
			{
				QMouseEvent  *ke = static_cast<QMouseEvent  *>(e);
				if (ke->button()== Qt::LeftButton)
				{
					currentIndex_big = i;
					emit buttonNumberInfo(i);
				}
				return true;
			}
		}
	}

	for (int i = 0; i < 46; i++)
	{
		if (obj == smallGroup[i])
		{
			if (e->type() == QEvent::MouseButtonRelease)
			{
				QMouseEvent  *ke = static_cast<QMouseEvent  *>(e);
				if (ke->button() == Qt::LeftButton)
				{
					currentIndex_small = i;
					emit smallInfo(i);
				}
				return true;
			}
		}
	}	
	return QWidget::eventFilter(obj, e);
}

void combinedButton::getSmallGroup(QPushButton *_smallGroup[])
{
	for (int i = 0; i < 46; i++)
	{
		_smallGroup[i] = smallGroup[i];
	}
}

void combinedButton::setSmallGroup(int a,QPushButton * _temp)
{
	smallGroup[a] = _temp;
}

void combinedButton::getBigGroup(QPushButton * _bigGroup[])
{
	for (int i = 0; i < 46; i++)
	{
		_bigGroup[i] = bigGroup[i];
	}
}

void combinedButton::getBigGroup(int a, QPushButton * _temp)
{

}

void combinedButton::setCustomPoint(int _num, int * _customPoint)
{
	if (customPoint != NULL)
	{
		delete customPoint;
		customPoint = NULL;
	}
	num = _num;
	customPoint = new int[num];
	for (int i = 0; i < num; i++)
	{
		customPoint[i] = _customPoint[i];
	}	
}

void combinedButton::initializeSmallButton(int level)
{
	int  a = 0;
	const int *temp;//获取当前关卡的所需点的全局数组
	switch (level)
	{
	case 0: a = 46;//本轮测试方法涉及的点加上1cmA和1cmB这两个
		temp = DefalutPoint;
		break;
	case 1: a = 23;
		temp = Tweed;
		break;
	case 2: a = 18;
		temp = Downs;
		break;
	case 3: a = 13;
		temp = Wylie;
		break;
	case 4: a = 17;
		temp = tissue;
		break;
	default:
		a = 46;
		break;
	}
	if (text != NULL)
	{
  		delete text;
		text = NULL;
	}
	
	text = new int[a];
	text[0] = 44;
	text[1] = 45;
	for (int i = 2; i < a; i++)
	{
		text[i] = temp[i - 2];
	}
	//显示小按钮初始图片
	if (!bInitialize)
	{
		for (int i = 0; i < 46; i++)
		{
			emit smallInfo2(i);//初始按钮群小按钮图案
		}
		bInitialize = true;
	}
}

void combinedButton::initializeSmallButton2()
{
	if (text != NULL)
	{
		delete text;
		text = NULL;
	}
	text = new int[num];
	for (int i = 0; i < num; i++)
	{
		text[i] = customPoint[i];
	}
	//显示小按钮初始图片
	if (!bInitialize)
	{
		for (int i = 0; i < 46; i++)
		{
			emit smallInfo2(i);//初始按钮群小按钮图案
		}
		bInitialize = true;
	}
}



void combinedButton::infoRecvText(int a)
{
	
	switch (a)
	{
	case 0:
		bInitialize=false;
		initializeSmallButton(0);
		break;
	case 1:	
		bInitialize = false;
		initializeSmallButton(1);
		break;
	case 2:
		bInitialize = false;
		initializeSmallButton(2);
		break;

	case 3:
		bInitialize = false;
		initializeSmallButton(3);
		break;

	case 4:
		bInitialize = false;
		initializeSmallButton(4);
		break;
	case 5:
		bInitialize = false;
		initializeSmallButton2();
		break;
	default:
		break;
	}
}


