#pragma once
#include"Figure.h"

class Curve : public Figure
{
public:
	Curve(void);
	Curve(int start_point_x, int start_point_y, int end_point_x, int end_point_y);
	~Curve(void);
	void setCon(int con1x, int con1y, int con2x, int con2y);

public:
	void Draw(QPainter& paint);

private:
	QPainterPath path;
	int	start_point_x_, start_point_y_, end_point_x_, end_point_y_;
	int con_1_x, con_1_y, con_2_x, con_2_y;
};
/*
#pragma once
#ifndef _CURVE_H
#define _CURVE_H
#include"Figure.h"

class Curve : public Figure
{
public:
	vector<QPoint> mybpoint;
	Curve(void);
	Curve(vector<QPoint> bpoints);
	~Curve(void);
	void update(const QPoint _end_point);

public:
	void Draw(QPainter& paint);

private:
	QPainterPath mypath;

	QPoint start_point;
	QPoint end_point;
};
#endif
#*/