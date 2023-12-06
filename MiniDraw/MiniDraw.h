#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniDraw.h"
#include"ViewWidgets.h"
//��MiniDraw����������
class MiniDraw : public QMainWindow
{
    Q_OBJECT

public:
    MiniDraw(QWidget* parent = Q_NULLPTR);
    ~MiniDraw();

private:
    Ui::MiniDrawClass ui;

    QAction* action[9];                   //������������
    QToolBar* toolbar;                    // ����������

    ViewWidgets* view_widget_;             //����ViewWidgetָ��

    QDial* width_dial_;//��ȸ���
    QDial* style_dial_;

    void Init();
    void CreateButtons();
};