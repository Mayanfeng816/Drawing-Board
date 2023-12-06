#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniDraw.h"
#include"ViewWidgets.h"
//在MiniDraw中声明变量
class MiniDraw : public QMainWindow
{
    Q_OBJECT

public:
    MiniDraw(QWidget* parent = Q_NULLPTR);
    ~MiniDraw();

private:
    Ui::MiniDrawClass ui;

    QAction* action[9];                   //声明动作数组
    QToolBar* toolbar;                    // 声明工具栏

    ViewWidgets* view_widget_;             //声明ViewWidget指针

    QDial* width_dial_;//宽度格子
    QDial* style_dial_;

    void Init();
    void CreateButtons();
};