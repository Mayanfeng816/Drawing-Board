#pragma once
#ifndef _LINE_H
#define _LINE_H
#include"Figure.h"

class Line : public Figure
{
public:
	Line(void);
	Line(int start_point_x, int start_point_y, int end_point_x, int end_point_y,QColor color,int width,Qt::PenStyle style);
	~Line(void);

public:
	void Draw(QPainter& paint);

private:
	int	start_point_x_, start_point_y_, end_point_x_, end_point_y_;//两点确定一条直线
};
#endif 
