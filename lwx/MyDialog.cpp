#include "MyDialog.h"

MyDialog::MyDialog(QWidget * parent) :QDialog(parent)
{
	this->resize(500, 450);
	this->setWindowTitle("�Զ��������");
	this->setModal(true);
	this->setObjectName("myDialog");
	//ȥ��dialog���Ͻǰ�����ť
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);
	setWindowFlags(Qt::Drawer);


	//�����Ų�
	m_pLabel1 = new  QLabel(this);
	m_pLabel1->setText("��ѡ������");
	m_pLabel1->setStyleSheet("color:black");
	m_pLabel1->setGeometry(20, 20, 75, 30);
	m_pLabel1->setObjectName("canSelect");

	m_pCob = new QComboBox(this);
	m_pCob->setGeometry(95, 20, 115, 30);
	for (int i = 0; i < 5; i++)
	{
		m_pCob->addItem(methodName[i]);
	}
	connect(m_pCob, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));

	m_pLabel2 = new QLabel(this);
	m_pLabel2->setText("��ѡ������");
	m_pLabel2->setStyleSheet("color:black");
	m_pLabel2->setGeometry(290, 20, 75, 30);
	m_pLabel2->setObjectName("hadSelect");

	m_ButtonUp = new QPushButton(this);
	m_ButtonDown = new QPushButton(this);
	m_ButtonUp->setGeometry(385, 20, 45, 30);
	m_ButtonUp->setText("����");
	m_ButtonUp->setObjectName("upButton");

	m_ButtonDown->setGeometry(435, 20, 45, 30);
	m_ButtonDown->setText("����");
	m_ButtonDown->setObjectName("downButton");
	connect(m_ButtonUp, SIGNAL(clicked(bool)), this, SLOT(listWidgetItemUp()));
	connect(m_ButtonDown, SIGNAL(clicked(bool)), this, SLOT(listWidgetItemDown()));

	listWidget1 = new QListWidget(this);
	listWidget1->setGeometry(20,70,190,300);
	connect(listWidget1, SIGNAL(itemSelectionChanged()),this, SLOT(acquireItemIndex()));
	listItemNum = 41;
	for (int i = 0; i < listItemNum; i++)
	{
		listWidget1->addItem(textHintOnView[i]);	
	}

	listWidget2 = new QListWidget(this);
	listWidget2->setGeometry(290,70,190,300);
	connect(listWidget2, SIGNAL(itemSelectionChanged()), this,SLOT(acquireItemIndex2()));

	//��ӣ�ɾ����ť
	m_OneGet = new QPushButton(this);
	m_OneGet->setGeometry(230,70,45,30);
	m_OneGet->setObjectName("OneGet");
	m_OneGet->setToolTip("���һ����ѡ��");
	connect(m_OneGet,SIGNAL(clicked(bool)),this,SLOT(addOne()));

	m_AllGet = new QPushButton(this);
	m_AllGet->setGeometry(230, 110, 45, 30);
	m_AllGet->setObjectName("AllGet");
	m_AllGet->setToolTip("������п�ѡ��");
	connect(m_AllGet, SIGNAL(clicked(bool)), this, SLOT(addAll()));

	m_OneReturn = new QPushButton(this);
	m_OneReturn->setGeometry(230, 300, 45, 30);
	m_OneReturn->setObjectName("OneReturn");
	m_OneReturn->setToolTip("ɾ��һ����ѡ��");
	connect(m_OneReturn, SIGNAL(clicked(bool)), this, SLOT(deleteOne()));

	m_AllReturn = new QPushButton(this);
	m_AllReturn->setGeometry(230,340, 45, 30);
	m_AllReturn->setObjectName("AllReturn");
	m_AllReturn->setToolTip("ɾ��������ѡ��");
	connect(m_AllReturn, SIGNAL(clicked(bool)), this, SLOT(deleteAll()));

	//ȷ�ϣ�ȡ��
	m_ok = new QPushButton(this);
	m_ok->setGeometry(385,390,45,30);
	m_ok->setObjectName("Ok");
	m_ok->setText("ȷ��");
	connect(m_ok, SIGNAL(clicked(bool)), this, SLOT(ok()));
	m_cannel = new QPushButton(this);
	m_cannel->setGeometry(435, 390, 45, 30);
	m_cannel->setObjectName("Cannel");
	m_cannel->setText("ȡ��");
	connect(m_cannel, SIGNAL(clicked(bool)), this, SLOT(cannel()));

	//��ʼ��
	comboBoxLevel = 0;
	currentSelectItemIndex = -1;
	currentSelectItemIndex2 = -1;
	listItemNum = 41;


	connect(this, SIGNAL(changeVectorInfo()), parent, SLOT(infoRecvchangItem()));
}


void MyDialog::indexChanged(int a)
{
		comboBoxLevel = a;
		changeItem();
}

void MyDialog::getVector(QVector<int> &a)
{
	for (int i = a.size(); i > 0; i--)
	{
		a.remove(i - 1);
	}
	for (int i = 0; i < hadSelectItem.size(); i++)
	{
		a.append(hadSelectItem.at(i));
	}
}

MyDialog::~MyDialog()
{

}

void MyDialog::listWidgetItemUp()
{
	//currentSelectItemIndex2 = listWidget2->currentRow();
	int tempIndex = currentSelectItemIndex2;
	if (tempIndex - 1 >= 0)
	{
		QListWidgetItem *pItem = listWidget2->item(tempIndex);
		QString temp = pItem->text();
		listWidget2->removeItemWidget(pItem);
		delete pItem;//ɾ����currentSelectItem�Զ�-1
		QListWidgetItem * newItem = new QListWidgetItem(temp);
		listWidget2->insertItem(tempIndex - 1, newItem);
		currentSelectItemIndex2 = tempIndex - 1;
		listWidget2->setFocus();
		listWidget2->setCurrentItem(newItem); //����'dd'Ϊ��ǰ��
	}
}
	
void MyDialog::listWidgetItemDown()
{
	int tempIndex = currentSelectItemIndex2;
	int currentListWidget2ItemNum = listWidget2->count();
	if (tempIndex +1 < currentListWidget2ItemNum)
	{
		QListWidgetItem *pItem = listWidget2->item(tempIndex);
		QString temp = pItem->text();
		listWidget2->removeItemWidget(pItem);
		delete pItem;//ɾ����currentSelectItem�Զ�-1
		QListWidgetItem * newItem = new QListWidgetItem(temp);
		listWidget2->insertItem(tempIndex +1, newItem);
		currentSelectItemIndex2 = tempIndex + 1;
		listWidget2->setFocus();
		listWidget2->setCurrentItem(newItem); //����'dd'Ϊ��ǰ��
	}
}

void MyDialog::acquireItemIndex()
{
	currentSelectItemIndex = listWidget1->currentRow();
}

void MyDialog::acquireItemIndex2()
{
	currentSelectItemIndex2 = listWidget2->currentRow();
}

void MyDialog::addOne()
{
	int currentListWidget2ItemNum = listWidget2->count();
	bool exist = false;
	judgeExist(currentListWidget2ItemNum, currentSelectItemIndex, exist);
	if (!exist)
	{
		currentSelectItemIndex2 += 1;
		listWidget2->insertItem(currentSelectItemIndex2, textHintOnView[dataVector[comboBoxLevel][currentSelectItemIndex]]);
	}
	QListWidgetItem *pItem = listWidget2->item(currentSelectItemIndex2);
	listWidget2->setFocus();
	listWidget2->setCurrentRow(currentSelectItemIndex2);

}

void MyDialog::addAll()
{
	int currentListWidget2ItemNum = listWidget2->count();
	for (int i = 0; i < testItemNum[comboBoxLevel]; i++)
	{
		bool exist = false;
		judgeExist(currentListWidget2ItemNum, i, exist);
		if (!exist)
		{
			listWidget2->addItem(textHintOnView[dataVector[comboBoxLevel][i]]);
			currentSelectItemIndex2 += 1;
		}	
	}	
	QListWidgetItem *pItem = listWidget2->item(currentSelectItemIndex2);
	listWidget2->setFocus();
	listWidget2->setCurrentRow(currentSelectItemIndex2);
}

void MyDialog::deleteOne()
{
	QListWidgetItem *pItem = listWidget2->takeItem(currentSelectItemIndex2);
	listWidget1->removeItemWidget(pItem);
	delete pItem;
	
	listWidget2->setFocus();
	listWidget2->setCurrentRow(currentSelectItemIndex2);
}

void MyDialog::deleteAll()
{
	int itemNum = listWidget2->count();
	for (int i = itemNum - 1; i >= 0; i--)
	{
		QListWidgetItem *pItem = listWidget2->takeItem(i);
		listWidget2->removeItemWidget(pItem);
		delete pItem;
	}
	
}

void MyDialog::ok()
{
	this->hide();
	int itemNum = listWidget2->count();
	//�洢ԭ����hadSelectItem
	QVector<int> temp;
	for (int i = 0; i < hadSelectItem.size(); i++)
	{
		temp.append(hadSelectItem.at(i));
	}

	for (int i = hadSelectItem.size(); i > 0; i--)
	{
		hadSelectItem.remove(i-1);
	}

	for (int i = 0; i < itemNum; i++)
	{
		QListWidgetItem *pItem = listWidget2->item(i);
		//ͨ��item��������λ���ڲ����������λ��
		//����޸��޸��������Ҫ�޸�����41
		for (int j = 0; j < 41; j++)
		{
			if (textHintOnView[j] == pItem->text())
				hadSelectItem.append(j);//���¼�¼vectorǰҪɾ��ԭ��vector
		}
	}	
	bool change=false;//�ж�ȷ��ǰ���Ƿ�仯
	if (temp.size() != hadSelectItem.size())
	{
		change = true;
	}
	else
	{
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp.at(i) != hadSelectItem.at(i))
			{
				change = true;
				break;
			}
		}
	}

	if(change)//��֤���͵�ȷ���źŶ��Ǹı�ģ��������÷���������
		emit changeVectorInfo();
}

void MyDialog::cannel()
{
	this->hide();
	//ȡ����ָ�Ϊ��ȷ���Ĳ�����
	int itemNum = listWidget2->count();
	for (int i = itemNum - 1; i >= 0; i--)
	{
		QListWidgetItem *pItem = listWidget2->takeItem(i);
		listWidget2->removeItemWidget(pItem);
		delete pItem;
	}
	for (int i = 0; i < hadSelectItem.size(); i++)
	{
		listWidget2->addItem(textHintOnView[hadSelectItem.at(i)]);
	}
	currentSelectItemIndex2 = listWidget2->count() - 1;
	listWidget2->setFocus();
	listWidget2->setCurrentRow(currentSelectItemIndex2);
}

void MyDialog::changeItem()
{
	//����ɾ��ԭ����item
	int itemNum = listWidget1->count();
	//��Ϊɾ��һ��item�󣬺���ĵ�index��ı䣬���Ե���ɾ��
	for (int i = itemNum - 1; i >= 0; i--)
	{
		QListWidgetItem *pItem = listWidget1->takeItem(i);
		listWidget1->removeItemWidget(pItem);
		delete pItem;
	}
	//�����item
	for (int i = 0; i < testItemNum[comboBoxLevel]; i++)
	{
		listWidget1->addItem(textHintOnView[dataVector[comboBoxLevel][i]]);	
	}
}

void MyDialog::judgeExist(int existNum, int currentAddItemIndex, bool &exist)
{

	for (int j = 0; j < existNum; j++)
	{
		QListWidgetItem *pItem = listWidget2->item(j);
		if (pItem->text() == textHintOnView[dataVector[comboBoxLevel][currentAddItemIndex]])
		{
			exist = true;
		}
	}
}
