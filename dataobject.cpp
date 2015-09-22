#include <QDebug>
#include "dataobject.h"

DataObject::DataObject(QObject * parent) :
	QObject(parent)
{
}


DataObject::DataObject(const QVector<QPointF> & points, qreal x, qreal y, const QString & color, QObject * parent) :
	QObject(parent),
	_points(points),
	_color(color),
	_x(x),
	_y(y)
{
}


QString DataObject::color() const
{
	return _color;
}


void DataObject::setColor(const QString &color)
{
	if (color != _color) {
		_color = color;
        emit colorChanged();
    }
}


QVector<QPointF> DataObject::points() const
{
	return _points;
}


void DataObject::setPoints(const QVector<QPointF> & points)
{
	if (_points != points) {
		_points = points;
		emit pointsChanged();
	}
}


qreal DataObject::x() const
{
	return _x;
}


void DataObject::setX(qreal x)
{
	if (_x != x) {
		_x = x;
		emit xChanged();
	}
}


qreal DataObject::y() const
{
	return _y;
}


void DataObject::setY(qreal y)
{
	if (_y != y) {
		_y = y;
		emit yChanged();
	}
}

