#pragma once
#ifndef _POLYGON_H
#define _POLYGON_H
#include"Figure.h"

class Polygon : public Figure
{
public:
	vector<QPoint> point;
	Polygon(void);
	Polygon(vector<QPoint> points, QColor color,int width, Qt::PenStyle style);
	~Polygon(void);
	void update(const QPoint _end_point);
public:
	void Draw(QPainter& paint);

private:
	QPoint start_point;
	QPoint end_point;
};
#endif 


