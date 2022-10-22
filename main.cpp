#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qdbfile.h"
#include "contentmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QDBFile *db_ =  new QDBFile("chinook");
    ContentModel *model = new ContentModel();
    model->load_data(db_->get_current_table()->get_all_data());
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("riotModel",model);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
