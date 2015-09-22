#ifndef GRID_H
#define GRID_H

#include <QObject>
#include <QList>


class Grid : public QObject
{
	Q_OBJECT
public:
	explicit Grid(QObject * parent = 0);

	QList<QObject *> GetDataList();

private:
	QList<QObject *> _dataList;
};


#endif // GRID_H
