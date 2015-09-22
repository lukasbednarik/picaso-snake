#include "grid.h"
#include "dataobject.h"
#include <QDebug>


namespace
{
/// Return random number in [0, 1]
qreal RandReal()
{
	int grid = 100000;
	return static_cast<qreal>(qrand() % grid) / static_cast<qreal>(grid);  // TODO THIS IMPLEMENTATION IS NOT GOOD
}


QVector<QPointF> RandomPoints(int count)
{
	QVector<QPointF> points;
	for (int i = 0; i < count; ++i) {
		QPointF p(RandReal(), RandReal());
		points.push_back(p);
	}
	return points;
}
}


Grid::Grid(QObject * parent) :
	QObject(parent)
{
	for (int i = 0; i < 10; ++i) {
		_dataList.append(new DataObject(RandomPoints(4), RandReal(), RandReal(), "red"));
	}

}


QList<QObject *> Grid::GetDataList()
{
	return _dataList;
}

