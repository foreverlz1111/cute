#include "drawer.h"
#include "ui_drawer.h"
#include"ui_mainwindow.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include"QToolBox"
#include"QtGui"
Drawer::Drawer(QWidget *parent) :
    QToolBox(parent),
    ui(new Ui::Drawer)
{
   ui->setupUi(this);
   setWindowTitle(tr("【QT任务3.4】"));
    QGroupBox *groupBox1 = new QGroupBox();//第一个组内含5成员
        toolbutton1_1 = new QToolButton();//==========1
        toolbutton1_1->setText(tr("A"));
        toolbutton1_1->setIcon(QPixmap(":/qqimg/qqimg/1105121514853810.png"));
        toolbutton1_1->setIconSize(QPixmap(":/qqimg/qqimg/1105121514853810.png").size());
        toolbutton1_1->setAutoRaise(true);
        toolbutton1_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        toolbutton1_2 = new QToolButton();//==========2
        toolbutton1_2->setText(tr("B"));
        toolbutton1_2->setIcon(QPixmap(":/qqimg/qqimg/1105121514853810.png"));
        toolbutton1_2->setIconSize(QPixmap(":/qqimg/qqimg/1105121514853810.png").size());
        toolbutton1_2->setAutoRaise(true);
        toolbutton1_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        toolbutton1_3 = new QToolButton();//==========3
        toolbutton1_3->setText(tr("C"));
        toolbutton1_3->setIcon(QPixmap(":/qqimg/qqimg/110512151485384.png"));
        toolbutton1_3->setIconSize(QPixmap(":/qqimg/qqimg/110512151485384.png").size());
        toolbutton1_3->setAutoRaise(true);
        toolbutton1_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        toolbutton1_4 = new QToolButton();//==========4
        toolbutton1_4->setText(tr("D"));
        toolbutton1_4->setIcon(QPixmap(":/qqimg/qqimg/110512151485385.png"));
        toolbutton1_4->setIconSize(QPixmap(":/qqimg/qqimg/110512151485385.png").size());
        toolbutton1_4->setAutoRaise(true);
        toolbutton1_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        toolbutton1_5 = new QToolButton();//==========5
        toolbutton1_5->setText(tr("E"));
        toolbutton1_5->setIcon(QPixmap(":/qqimg/qqimg/110512151485386.png"));
        toolbutton1_5->setIconSize(QPixmap(":/qqimg/qqimg/110512151485386.png").size());
        toolbutton1_5->setAutoRaise(true);
        toolbutton1_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        QVBoxLayout *layout1 = new QVBoxLayout(groupBox1);
        layout1->setMargin(10);
        layout1->setAlignment(Qt::AlignCenter);
        layout1->addWidget(toolbutton1_1);
        layout1->addWidget(toolbutton1_2);
        layout1->addWidget(toolbutton1_3);
        layout1->addWidget(toolbutton1_4);
        layout1->addWidget(toolbutton1_5);
        layout1->addStretch();

        QGroupBox *groupBox2 = new QGroupBox();//一个组内含2成员
        toolbutton2_1 = new QToolButton();//==========1
        toolbutton2_1->setText(tr("F"));
        toolbutton2_1->setIcon(QPixmap(":/qqimg/qqimg/110512151485387.png"));
        toolbutton2_1->setIconSize(QPixmap(":/qqimg/qqimg/110512151485387.png").size());
        toolbutton2_1->setAutoRaise(true);
        toolbutton2_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        toolbutton2_2 = new QToolButton();//==========2
        toolbutton2_2->setText(tr("G"));
        toolbutton2_2->setIcon(QPixmap(":/qqimg/qqimg/110512151485388.png"));
        toolbutton2_2->setIconSize(QPixmap(":/qqimg/qqimg/110512151485388.png").size());
        toolbutton2_2->setAutoRaise(true);
        toolbutton2_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
        layout2->setMargin(10);
        layout2->setAlignment(Qt::AlignCenter);
        layout2->addWidget(toolbutton2_1);
        layout2->addWidget(toolbutton2_2);
        layout2->addStretch();

        QGroupBox *groupBox3 = new QGroupBox();//一个组内含2成员
        toolbutton3_1 = new QToolButton();//==========1
        toolbutton3_1->setText(tr("H"));
        toolbutton3_1->setIcon(QPixmap(":/qqimg/qqimg/110512151485389.png"));
        toolbutton3_1->setIconSize(QPixmap(":/qqimg/qqimg/110512151485389.png").size());
        toolbutton3_1->setAutoRaise(true);
        toolbutton3_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        toolbutton3_2 = new QToolButton();//==========1
        toolbutton3_2->setText(tr("I"));
        toolbutton3_2->setIcon(QPixmap(":/qqimg/qqimg/qq.png"));
        toolbutton3_2->setIconSize(QPixmap(":/qqimg/qqimg/qq.png").size());
        toolbutton3_2->setAutoRaise(true);
        toolbutton3_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
        layout3->setMargin(10);
        layout3->setAlignment(Qt::AlignCenter);
        layout3->addWidget(toolbutton3_1);
        layout3->addWidget(toolbutton3_2);
        layout3->addStretch();
        ui->page->deleteLater();
        this->addItem((QWidget*)groupBox1,tr("我的好友"));//添加至窗口

        this->addItem((QWidget*)groupBox2,tr("陌生人"));

        this->addItem((QWidget*)groupBox3,tr("黑名单"));

}

Drawer::~Drawer()
{
    //delete *ui;
}
