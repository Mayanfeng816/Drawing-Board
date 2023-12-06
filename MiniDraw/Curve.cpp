#include"Curve.h"
Curve::Curve(void)
{
}

Curve::Curve(int start_point_x, int start_point_y, int end_point_x, int end_point_y)
{
	start_point_x_ = start_point_x;
	start_point_y_ = start_point_y;
	end_point_x_ = end_point_x;
	end_point_y_ = end_point_y;
}

Curve::~Curve(void)
{
}

void Curve::setCon(int con1x, int con1y, int con2x, int con2y) {
	con_1_x = con1x;
	con_1_y = con1y;
	con_2_x = con2x;
	con_2_y = con2y;
}

void Curve::Draw(QPainter& paint)
{
	paint.setRenderHint(QPainter::Antialiasing, true);
	paint.setPen(Qt::blue);//¸¨ÖúÏß
	paint.drawLine(start_point_x_, start_point_y_, con_1_x, con_1_y);
	paint.drawLine(end_point_x_, end_point_y_, con_2_x, con_2_y);
	paint.setPen(Qt::green);//¸¨ÖúÏß
	paint.drawLine(con_1_x, con_1_y, con_2_x, con_2_y);
	paint.setPen(Qt::red);//ÇúÏß
	path.moveTo(start_point_x_, start_point_y_);
	path.cubicTo(con_1_x, con_1_y, con_2_x, con_2_y, end_point_x_, end_point_y_);
	paint.drawPath(path);
}
/*
Curve::Curve(void)
{
}

Curve::Curve(vector<QPoint> bpoints)
{
	mybpoint = bpoints;
}

Curve::~Curve(void)
{
	mybpoint.clear();
}

void Curve::update(const QPoint _end_point)
{
	end_point.setX(_end_point.x());
	end_point.setY(end_point.y());
}

void Curve::Draw(QPainter& paint)
{
	paint.setRenderHint(QPainter::Antialiasing, true);
	paint.setPen(Qt::blue);
	for (int i = 0; i < mybpoint.size()-1; i++) {
		paint.drawLine(mybpoint[i], mybpoint[i+1]);
	}
	paint.setPen(Qt::green);
	for (int i = 1; i < mybpoint.size() - 2; i++) {
		paint.drawLine(mybpoint[i], mybpoint[i+1]);
	}
	paint.setPen(Qt::red);
	mypath.moveTo(mybpoint.at(0));
	for (int i = 1; i < mybpoint.size(); i++) {
		mypath.lineTo(mybpoint[i]);
	}
	paint.drawPath(mypath);
	
}
*/