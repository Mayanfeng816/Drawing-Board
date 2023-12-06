#pragma once
#pragma once
#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include"Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle(void);
	Rectangle(int start_point_x, int start_point_y, int end_point_x, int end_point_y, QColor color,int width, Qt::PenStyle style);
	~Rectangle(void);

public:
	void Draw(QPainter& paint);

private:
	int	start_point_x_, start_point_y_, end_point_x_, end_point_y_;
};

#endif 
