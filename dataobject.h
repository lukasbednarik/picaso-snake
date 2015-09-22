#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>
#include <QPointF>
#include <QVector>


class DataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(QVector<QPointF> points READ points WRITE setPoints NOTIFY pointsChanged)
	Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)
	Q_PROPERTY(qreal y READ y WRITE setY NOTIFY yChanged)

public:
	DataObject(QObject * parent = 0);
	DataObject(const QVector<QPointF> & points, qreal x, qreal y, const QString & color, QObject * parent = 0);

    QString color() const;
	void setColor(const QString &color);
	QVector<QPointF> points() const;
	void setPoints(const QVector<QPointF> & points);
	qreal x() const;
	void setX(qreal x);
	qreal y() const;
	void setY(qreal y);

signals:
    void colorChanged();
	void pointsChanged();
	void xChanged();
	void yChanged();

private:
	QVector<QPointF> _points;
	QString _color;
	qreal _x;
	qreal _y;
};


#endif // DATAOBJECT_H
