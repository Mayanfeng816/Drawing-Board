#include "ViewWidgets.h"

ViewWidgets::ViewWidgets(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	pen = new QPen;
	draw_status_ = false;                //初始状态 不绘制
}

ViewWidgets::~ViewWidgets()               
{
	for (size_t i = 0; i < figure_array_.size(); i++)
	{
		if (figure_array_[i])
		{
			delete figure_array_[i];
			figure_array_[i] = NULL;
		}
	}

}

void ViewWidgets::mousePressEvent(QMouseEvent* event)
{
	if (Qt::LeftButton == event->button())             //鼠标左击
	{
		
		draw_status_ = true;  //绘制状态为——绘制
		/*
		if (figure_type_ == kCurve) {
			while (1) {
				bpoints.push_back(event->pos());
				if (Qt::RightButton == event->button())
					break;
			}
		}
		else
			start_point_ = end_point_ = event->pos();
		*/

		if (figure_type_ == kCurve) {
			if (num == 4)
				num = 0;
			if (num != 4) {
				num++;
				if(num==1)
					start_point_ = event->pos();  
				if (num == 2)
					con_point1_ = event->pos();
				if (num == 3)
					con_point2_ = event->pos();
				if (num == 4)
					end_point_ = event->pos();
			}
		}
		else
			start_point_ = end_point_ = event->pos();

	}

}

void ViewWidgets::mouseMoveEvent(QMouseEvent* event)    
{
	if (draw_status_&& figure_type_ != kCurve)                                 
	{
		
		end_point_ = event->pos();                     //终止点=鼠标当前位置

	}
}

void ViewWidgets::mouseReleaseEvent(QMouseEvent* event) 
{
	Figure* current_figure_ = NULL;              //声明父类指针
	switch (figure_type_)
	{
	case kDefault:
		//end_point_ = event->pos();
		figure_array_.push_back(current_figure_);
		draw_status_ = false;
		break;
	
	case kCurve:
		break;
	/*
	case kCurve:
		if (Qt::RightButton == event->button())
		{
			current_figure_ = new Curve(bpoints);
			figure_array_.push_back(current_figure_);
			bpoints.clear();
		}
		break;*/
	case kLine:
		current_figure_ = new Line(start_point_.rx(), start_point_.ry(), end_point_.rx(), end_point_.ry(), pen->color(), pen->width(),pen->style());
		figure_array_.push_back(current_figure_);       
		draw_status_ = false;
		break;
	case kEllipse:
		current_figure_ = new Ellipse(start_point_.rx(), start_point_.ry(), end_point_.rx(), end_point_.ry(), pen->color(), pen->width(), pen->style());
		figure_array_.push_back(current_figure_);
		draw_status_ = false;
		break;
	case kRectangle:
		current_figure_ = new Rectangle(start_point_.rx(), start_point_.ry(), end_point_.rx(), end_point_.ry(), pen->color(), pen->width(), pen->style());
		figure_array_.push_back(current_figure_);
		draw_status_ = false;
		break;
	case kPolygon:
		points.push_back(end_point_);
		if (Qt::RightButton == event->button())
		{
			current_figure_ = new Polygon(points, pen->color(), pen->width(), pen->style());
			figure_array_.push_back(current_figure_);
			points.clear();
		}
		break;
	default:
		break;
	}
	current_figure_ = NULL;
}

void ViewWidgets::paintEvent(QPaintEvent*)                
{
	QPainter painter(this);                              

	for (size_t i = 0; i < figure_array_.size(); i++)      //重画
	{
		if (figure_array_[i] != NULL)
		{
			figure_array_[i]->Draw(painter);
		}

	}

	if (draw_status_)
	{
		painter.setPen(*pen);//在绘制没松手时保持自定义的内容
		switch (figure_type_)
		{
		case kDefault:
			break;
		case kCurve:/* {
			if (bpoints.size() == 0)
			{
				break;
			}
			painter.setRenderHint(QPainter::Antialiasing, true);
			painter.setPen(Qt::blue);
			QPoint sta = bpoints[0];
			for (int i = 1; i < bpoints.size(); i++) {
				painter.drawLine(sta, bpoints[i]);
			}
			painter.setPen(Qt::green);
			for (int i = 1; i < bpoints.size() - 2; i++) {
				painter.drawLine(bpoints[i], bpoints[i + 1]);
			}
			painter.setPen(Qt::red);
			path.moveTo(sta);
			for (int i = 1; i < bpoints.size(); i++) {
				path.lineTo(bpoints[i]);
			}
			painter.drawPath(path); }
			break;*/
			
			if (num == 4) {
				
				painter.setRenderHint(QPainter::Antialiasing, true);
				painter.setPen(Qt::blue);
				painter.drawLine(start_point_, con_point1_);
				painter.drawLine(end_point_, con_point2_);
				painter.setPen(Qt::green);
				painter.drawLine(con_point1_, con_point2_);
				painter.setPen(Qt::red);
				path.moveTo(start_point_);
				path.cubicTo(con_point1_, con_point2_, end_point_);
				painter.drawPath(path);
			}
			break;
		
		case kLine:             //绘制
			painter.drawLine(start_point_, end_point_);
			break;
		case kEllipse:            
			painter.drawEllipse(start_point_.rx(), start_point_.ry(), end_point_.rx() - start_point_.rx(), end_point_.ry() - start_point_.ry());
			break;
		case kRectangle:           
			painter.drawRect(start_point_.rx(), start_point_.ry(), end_point_.rx() - start_point_.rx(), end_point_.ry() - start_point_.ry());
			break;
		case kPolygon:             
			if (points.size() == 0)
			{
				break;
			}
			QPoint pre = points[0];
			for (int i = 1; i < points.size(); i++)
			{
				painter.drawLine(pre, points[i]);
				pre = points[i];
			}
			break;
		}
	}

	update();                                    //更新
}

void ViewWidgets::set_figure_type_to_curve()
{
	figure_type_ = kCurve;
}

void ViewWidgets::set_figure_type_to_line()
{
	figure_type_ = kLine;
}

void ViewWidgets::set_figure_type_to_ellipse()
{
	figure_type_ = kEllipse;
}

void ViewWidgets::set_figure_type_to_rectangle()
{
	figure_type_ = kRectangle;
}

void ViewWidgets::set_figure_type_to_polygon()
{
	figure_type_ = kPolygon;
}


void ViewWidgets::Undo() {
	if (figure_array_.size() > 0)
	{
		delete figure_array_.back();
		figure_array_.pop_back();
	}
}

void ViewWidgets::Clear() {

	if (figure_array_.size() > 0)
	{
		figure_array_.clear();
	}
}

void ViewWidgets::set_color() {
	color = QColorDialog::getColor();
	pen->setColor(color);
}

void ViewWidgets::set_width(int width) {
	pen->setWidth(width);
}

void ViewWidgets::set_style(int style) {
	pen->setStyle((enum Qt::PenStyle)style);
}


