#include "Rectangle.h"

Rectangle::Rectangle(void)
{
}

Rectangle::Rectangle(int start_point_x, int start_point_y, int end_point_x, int end_point_y, QColor color,int width, Qt::PenStyle style)
{
	start_point_x_ = start_point_x;
	start_point_y_ = start_point_y;
	end_point_x_ = end_point_x;
	end_point_y_ = end_point_y;
	mycolor = color;
	mywidth = width;
	mystyle = style;
}

Rectangle::~Rectangle(void)
{
}

void Rectangle::Draw(QPainter& paint)
{
	paint.setRenderHint(QPainter::Antialiasing, true);
	paint.setPen(QPen(mycolor, mywidth, mystyle));
	paint.drawRect(start_point_x_, start_point_y_, end_point_x_ - start_point_x_, end_point_y_ - start_point_y_);
}