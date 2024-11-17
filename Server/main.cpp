#include <QCoreApplication>
#include <QSettings>
#include "bookingservice.hpp"
#include "httplistener.h"
using namespace stefanfrings;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QString configFileName = "./webapp.ini";



    QSettings* listenerSettings=
    new QSettings(configFileName,QSettings::IniFormat,&app);
    listenerSettings->beginGroup("listener");

    new stefanfrings::HttpListener(
        listenerSettings,
        new BookingService(&app),
        &app
    );

    return app.exec();
}
