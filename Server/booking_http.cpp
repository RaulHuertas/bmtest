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

}

void BookingService::reserverSeats(
    stefanfrings::HttpRequest& request,
    stefanfrings::HttpResponse& response
    ){

}
