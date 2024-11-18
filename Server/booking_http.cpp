#include "bookingservice.hpp"
#include <QMutexLocker>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

using namespace beamtrail;

void BookingService::getMovies(
    stefanfrings::HttpRequest& request,
    stefanfrings::HttpResponse& response
){
    auto list = getMovies();
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray array;
    for(auto& movie : list){
        array.push_back(movie);
    }
    obj["movies"] = array;
    doc.setObject(obj);
    response.write(doc.toJson(),true);
}

void BookingService::getAvailableTheatersMovie(
    stefanfrings::HttpRequest& request,
    stefanfrings::HttpResponse& response
){
    auto movieIndex = request.getParameter("movieIndex").toInt();
    auto list = getAvailableTheatersMovie(movieIndex);
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray array;
    for(auto& movie : list){
        array.push_back(movie);
    }
    obj["theaters"] = array;
    doc.setObject(obj);
    response.write(doc.toJson(),true);
}

void BookingService::getAvailableSeatsForMovie(
    stefanfrings::HttpRequest& request,
    stefanfrings::HttpResponse& response
){
    auto movieIndex = request.getParameter("movieIndex").toInt();
    auto theaterIndex = request.getParameter("theaterIndex").toInt();
    auto list = getAvailableSeatsForMovie(movieIndex, theaterIndex);
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray array;
    for(auto& movie : list){
        array.push_back(movie);
    }
    obj["seats"] = array;
    doc.setObject(obj);
    response.write(doc.toJson(),true);
}

void BookingService::bookSeats(
    stefanfrings::HttpRequest& request,
    stefanfrings::HttpResponse& response
){
    bool opResult = false;
    int paramIndex = 1;
    std::vector<int> indexes;
    indexes.reserve(10);
    while(true){
        QString seatIndexName = "seat"+QString::number(paramIndex);
        QByteArray seatParam = request.getParameter(seatIndexName.toUtf8());
        if(seatParam.isEmpty() || seatParam.length()==0){
            break;
        }
        indexes.push_back(seatParam.toInt());
        paramIndex++;
    }
    if(indexes.size()==0)    {
        response.setStatus(500,"Internal server error");
        response.write("Empty seats list",true);
        return;
    }

    auto movieIndex = request.getParameter("movieIndex").toInt();
    auto theaterIndex = request.getParameter("theaterIndex").toInt();
    opResult = bookSeats(movieIndex, theaterIndex, indexes);

    if(!opResult)    {
        response.setStatus(500,"Internal server error");
        response.write("Not all seats are available",true);
    }

}
