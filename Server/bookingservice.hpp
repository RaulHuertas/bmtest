#ifndef BOOKINGSERVICE_HPP
#define BOOKINGSERVICE_HPP

#include <QObject>
#include <httprequesthandler.h>

#include "httprequesthandler.h"


class BookingService : public stefanfrings::HttpRequestHandler
{
    Q_OBJECT

public:


    explicit BookingService(QObject* parent=nullptr);

    ~BookingService();


    void service(HttpRequest& request, HttpResponse& response);

};

#endif // BOOKINGSERVICE_HPP
