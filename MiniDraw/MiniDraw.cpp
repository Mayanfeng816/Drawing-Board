#include "MiniDraw.h"

MiniDraw::MiniDraw(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	width_dial_ = new QDial(this);//初始化标度盘
	width_dial_->setFixedSize(60,60);
	width_dial_->setRange(1, 20);//设置线条宽度范围
	width_dial_->setWrapping(true);                //设置是否包裹
	width_dial_->wrapping();                       //获取是否设置包裹
	width_dial_->setNotchesVisible(true);//设置标度盘刻度可见

	style_dial_ = new QDial(this);//初始化标度盘
	style_dial_->setFixedSize(60, 60);
	style_dial_->setRange(1, 5);//设置线条宽度范围
	style_dial_->setNotchesVisible(true);//设置标度盘刻度可见

	Init();                      //调用函数
	CreateButtons();
}

MiniDraw::~MiniDraw()
{
}

void MiniDraw::Init()                           //实例代码中将绘图控件的实例化放在Init函数中
{                                               //Init函数将在MiniDraw的构造函数中被调用
	view_widget_ = new ViewWidgets();            //实例化ViewWidget控件窗口
	setCentralWidget(view_widget_);             //将ViewWidget控件设置为主窗口的中心位置
}

void MiniDraw::CreateButtons()
{
	//创建各项功能
	action[0] = new QAction(tr("&Curve"), this);
	action[1] = new QAction(tr("&Line"), this);
	action[2] = new QAction(tr("&Ellipse"), this);
	action[3] = new QAction(tr("&Rectangle"), this);
	action[4] = new QAction(tr("&Polygon"), this);
	action[5] = new QAction(tr("&Undo"), this);
	action[6] = new QAction(tr("&Clear"), this);
	action[7] = new QAction(tr("&Color"), this);
	////连接信号与槽函数
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

	//信号为&对象（不要忘记&符号）此例中信号为triggered函数的返回值
	toolbar = addToolBar(tr("&Figure Tool"));

	////添加到工具栏
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


