#include "MiniDraw.h"

MiniDraw::MiniDraw(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	width_dial_ = new QDial(this);//��ʼ�������
	width_dial_->setFixedSize(60,60);
	width_dial_->setRange(1, 20);//����������ȷ�Χ
	width_dial_->setWrapping(true);                //�����Ƿ����
	width_dial_->wrapping();                       //��ȡ�Ƿ����ð���
	width_dial_->setNotchesVisible(true);//���ñ���̶̿ȿɼ�

	style_dial_ = new QDial(this);//��ʼ�������
	style_dial_->setFixedSize(60, 60);
	style_dial_->setRange(1, 5);//����������ȷ�Χ
	style_dial_->setNotchesVisible(true);//���ñ���̶̿ȿɼ�

	Init();                      //���ú���
	CreateButtons();
}

MiniDraw::~MiniDraw()
{
}

void MiniDraw::Init()                           //ʵ�������н���ͼ�ؼ���ʵ��������Init������
{                                               //Init��������MiniDraw�Ĺ��캯���б�����
	view_widget_ = new ViewWidgets();            //ʵ����ViewWidget�ؼ�����
	setCentralWidget(view_widget_);             //��ViewWidget�ؼ�����Ϊ�����ڵ�����λ��
}

void MiniDraw::CreateButtons()
{
	//���������
	action[0] = new QAction(tr("&Curve"), this);
	action[1] = new QAction(tr("&Line"), this);
	action[2] = new QAction(tr("&Ellipse"), this);
	action[3] = new QAction(tr("&Rectangle"), this);
	action[4] = new QAction(tr("&Polygon"), this);
	action[5] = new QAction(tr("&Undo"), this);
	action[6] = new QAction(tr("&Clear"), this);
	action[7] = new QAction(tr("&Color"), this);
	////�����ź���ۺ���
	connect(action[0], &QAction::triggered, view_widget_, &ViewWidgets::set_figure_type_to_curve);
	connect(action[1], &QAction::triggered, view_widget_, &ViewWidgets::set_figure_type_to_line);
	connect(action[2], &QAction::triggered, view_widget_, &ViewWidgets::set_figure_type_to_ellipse);
	connect(action[3], &QAction::triggered, view_widget_, &ViewWidgets::set_figure_type_to_rectangle);
	connect(action[4], &QAction::triggered, view_widget_, &ViewWidgets::set_figure_type_to_polygon);
	connect(action[5], &QAction::triggered, view_widget_, &ViewWidgets::Undo);
	connect(action[6], &QAction::triggered, view_widget_, &ViewWidgets::Clear);
	connect(action[7], &QAction::triggered, view_widget_, &ViewWidgets::set_color);

	connect(width_dial_, &QDial::valueChanged, view_widget_, &ViewWidgets::set_width);
	connect(style_dial_, &QDial::valueChanged, view_widget_, &ViewWidgets::set_style);
	//connect(action[5], &QAction::triggered, this, &MiniDraw::Delete);

	//�ź�Ϊ&���󣨲�Ҫ����&���ţ��������ź�Ϊtriggered�����ķ���ֵ
	toolbar = addToolBar(tr("&Figure Tool"));

	////��ӵ�������
	toolbar->addAction(action[0]);
	toolbar->addAction(action[1]);
	toolbar->addAction(action[2]);
	toolbar->addAction(action[3]);
	toolbar->addAction(action[4]);
	toolbar->addAction(action[5]);
	toolbar->addAction(action[6]);
	toolbar->addAction(action[7]); 
	toolbar->addWidget(width_dial_);
	toolbar->addWidget(style_dial_);
}


