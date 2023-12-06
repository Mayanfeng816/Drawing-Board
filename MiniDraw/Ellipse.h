#pragma once
#ifndef _ELLIPSE_H
#define _ELLIPSE_H
#include"Figure.h"

class Ellipse : public Figure
{
public:
	Ellipse(void);
	Ellipse(int start_point_x, int start_point_y, int end_point_x, int end_point_y,QColor color,int width, Qt::PenStyle style);
	~Ellipse(void);

public:
	void Draw(QPainter& paint);

private:
	int	start_point_x_, start_point_y_, end_point_x_, end_point_y_;
};
#endif 