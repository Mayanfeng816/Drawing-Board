#include"Polygon.h"

Polygon::Polygon(void)
{
}

Polygon::Polygon(vector<QPoint> points, QColor color,int width, Qt::PenStyle style)
{
	point = points;
	mycolor = color;
	mywidth = width;
	mystyle = style;
}

Polygon::~Polygon(void)
{
	point.clear();
}

void Polygon::update(const QPoint _end_point)
{
	end_point.setX(_end_point.x());
	end_point.setY(end_point.y());
}

void Polygon::Draw(QPainter& paint)
{
	paint.setRenderHint(QPainter::Antialiasing, true);
	paint.setPen(QPen(mycolor, mywidth, mystyle));
	paint.drawPolygon(&point.at(0), point.size(), Qt::OddEvenFill);
}