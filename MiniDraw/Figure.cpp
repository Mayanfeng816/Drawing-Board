/*#include "Figure.h"

Figure::Figure()
{
}

Figure::~Figure()
{
}

void Figure::draw(QPainter& paint)
{
}



void Figure::setEnd(int end_point_x, int end_point_y)
{
	end_point_x_ = end_point_x;
	end_point_y_ = end_point_y;
}
*/



#include "Figure.h"

Figure::Figure()
{
	
}

Figure::~Figure()
{
}


void Figure::setStart(QPoint start)
{

	start_point_ = start;
}

void Figure::setEnd(QPoint end)
{
	end_point_ = end;
}