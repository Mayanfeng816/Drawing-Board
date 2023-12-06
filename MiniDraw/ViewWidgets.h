#pragma once
#ifndef _VIEWWIDGET_H
#define _VIEWWIDGET_H

#include <QWidget>
#include<QColorDialog>
#include <QMouseEvent>
#include<qdial>
#include <qpainter.h>
#include<vector>
#include "ui_ViewWidgets.h"
#include"QMessageBox"
#include"Figure.h"
#include"Line.h"
#include"Ellipse.h"
#include"Rectangle.h"
#include"Polygon.h"
#include"Curve.h"
using namespace std;

enum FigureType           //ö�������ͼԪ����
{
	kDefault = 0,
	kCurve = 1,
	kLine = 2,
	kRectangle = 3,
	kEllipse = 4,
	kPolygon = 5,
};

typedef struct myLine {
	QPoint start_point_;
	QPoint end_point_;
}myLine;

class ViewWidgets : public QWidget
{
	Q_OBJECT
	vector<Figure* >  figure_array_;  //ͼ�α���       
	FigureType  figure_type_;              

public:
	ViewWidgets(QWidget* parent = Q_NULLPTR);
	~ViewWidgets();

	//���
	void mousePressEvent(QMouseEvent* event);  
	void mouseMoveEvent(QMouseEvent* event);   
	void mouseReleaseEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent*);             

	//����
	void set_figure_type_to_curve();
	void set_figure_type_to_line();
	void set_figure_type_to_ellipse();
	void set_figure_type_to_rectangle();
	void set_figure_type_to_polygon();
	void set_color();
	void set_width(int width);
	void set_style(int style);
	void Undo();
	void Clear();


private:
	Ui::ViewWidgets ui;

	bool draw_status_;             
	QPoint start_point_;           
	QPoint end_point_;             

	QPen *pen;
	QColor color;
	int width;
	int style;//enum ���1~5

	vector<QPoint> points;         //��
	vector<myLine*> lines;         //�߶�

	vector<QPoint> bpoints;  //bezier points
	QPoint con_point1_;           
	QPoint con_point2_;

	QPainterPath path;

	int num=0;

};

#endif