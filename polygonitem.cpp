#include "polygonitem.h"
#include <QPen>


namespace
{
QPointF calculateCenter(const QVector<QPointF> & points)
{
	QPointF center(0, 0);
	for (const auto & p : points) {
		center += p;
	}
	center /= points.size();
	return center;

}
}


PolygonItem::PolygonItem(QQuickItem *parent) :
	QQuickPaintedItem(parent),
	_color(QColor(255, 255, 255))
{
	setAntialiasing(true);
	connect(this, SIGNAL(widthChanged()), SLOT(onAppearanceChanged()));
	connect(this, SIGNAL(heightChanged()), SLOT(onAppearanceChanged()));
	connect(this, SIGNAL(colorChanged()), SLOT(onAppearanceChanged()));
}


QColor PolygonItem::color() const
{
	return _color;
}


void PolygonItem::setColor(QColor color)
{
	if (_color != color) {
		_color = color;
		emit colorChanged();
	}
}


QVector<QPointF> PolygonItem::points() const
{
	return _points;
}


void PolygonItem::setPoints(const QVector<QPointF> & points)
{
	if (_points != points) {
		_points = points;
		_center = calculateCenter(points);
		emit pointsChanged();
	}
}


void PolygonItem::paint(QPainter *painter)
{
	const qreal width = boundingRect().width();
	const qreal height = boundingRect().height();

	// Paint polygon
	/*
	QVector<QPointF> _trPoints;
	for (const auto & p : _points) {
		_trPoints.push_back(QPointF(p.x() * width, p.y() * height));
	}

	painter->setPen(QPen(QBrush(Qt::black), 2));
	painter->setBrush(_color);
	painter->drawPolygon(_trPoints.constData(), _trPoints.size());
	*/

	// Paint center
	painter->setBrush(Qt::gray);
	painter->setPen(Qt::NoPen);
	qreal size = 10;
	QPointF center(_center.x() * width, _center.y() * height);
	painter->drawEllipse(center, width / size, height / size);
}


void PolygonItem::onAppearanceChanged()
{
	int new_width = width();
	int new_height = height();
	update(QRect(0, 0, new_width, new_height));
}
