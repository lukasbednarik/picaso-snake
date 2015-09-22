#ifndef POLYGONITEM_H
#define POLYGONITEM_H

#include <QtQuick/QQuickItem>
#include <QQuickPaintedItem>
#include <QPainter>


class PolygonItem : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(QVector<QPointF> points READ points WRITE setPoints NOTIFY pointsChanged)

public:
	explicit PolygonItem(QQuickItem *parent = 0);
	void paint(QPainter *painter);

	QColor color() const;
	void setColor(QColor color);
	QVector<QPointF> points() const;
	void setPoints(const QVector<QPointF> & points);

signals:
	void colorChanged();
	void pointsChanged();  // Points changed is emitted also on center changed

private:
	QColor _color;
	QVector<QPointF> _points;
	QPointF _center;

private slots:
	void onAppearanceChanged();
};

#endif // POLYGONITEM_H
