#include <QGuiApplication>
#include <QtQml>
#include <QtQuick>
#include "polygonitem.h"
#include "grid.h"


int main(int argc, char ** argv)
{
	QGuiApplication app(argc, argv);

	// TODO Application name asi nefunguji...
	app.setApplicationName("Picaso Snake");  // for QSettings
	app.setApplicationDisplayName("Picaso Snake");  // User visible name

	qRegisterMetaType<QPointF>("QPointF");
	qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
	qmlRegisterType<PolygonItem>("SnakeGeometry", 1, 0, "PolygonItem");

	qsrand(static_cast<uint>(QTime::currentTime().msec()));
	Grid grid;

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
	QQmlContext * ctxt = view.rootContext();
	ctxt->setContextProperty("myModel", QVariant::fromValue(grid.GetDataList()));
	QObject::connect(ctxt->engine(), SIGNAL(quit()), &app, SLOT(quit()));
	//ctxt->setContextProperty("MyTimer", new AdvancedRectangle());

	view.setSource(QUrl("qrc:/main.qml"));  // Without the slash it doesn't search the actual folder
	view.show();

    return app.exec();
}

