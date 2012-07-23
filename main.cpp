#include <QApplication>
#include "qmlapplicationviewer.h"
#include <core.h>
#include <QtDeclarative>
#include <QDeclarativeContext>
#include "lightsabersettings.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    Core core;

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("core", &core);
    qmlRegisterType<LightsaberSettings>("LightsaberSettings",1,0,"Settings");
    qmlRegisterType<Accelerometer>("Accelerometer",1,0,"Accelerometer");


    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/lightsaber/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
