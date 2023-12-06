#pragma once
#ifndef _FIGURE_H
#define _FIGURE_H
#include <qpainter.h>
#include<qpainterpath.h>
#include<qpoint.h>
#include<vector>

using namespace std;

class Figure
{
public:
	QColor mycolor;
	int mywidth;
	Qt::PenStyle mystyle;
	virtual void Draw(QPainter& paint) = 0;
	virtual ~Figure() {}                    
};                                       
										
#endif