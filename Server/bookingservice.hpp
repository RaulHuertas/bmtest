#ifndef BOOKINGSERVICE_HPP
#define BOOKINGSERVICE_HPP

#include <QObject>
#include <httprequesthandler.h>
#include "movie.hpp"
#include <QMutex>
class BookingService : public stefanfrings::HttpRequestHandler
{
    Q_OBJECT

public:

    explicit BookingService(QObject* parent=nullptr);

    ~BookingService();

    void service(
        stefanfrings::HttpRequest& request,
        stefanfrings::HttpResponse& response
    );

    void setMovies(const std::vector<QString>& movieNames);

    //Methods available in the API
    std::vector<QString> getMovies();
    std::vector<QString> getAvailableTheatersMovie(int movieID);//ID is actuallly just the index
    std::vector<int> getAvailableSeatsForMovie(int movieID, int theaterID);//ID is actuallly just the index
    bool bookSeats(int movieID, int theaterID, std::vector<int> requestedSeats);

    //HTTP implementation
    void getMovies(
        stefanfrings::HttpRequest& request,
        stefanfrings::HttpResponse& response
    );
    void getAvailableTheatersMovie(
        stefanfrings::HttpRequest& request,
        stefanfrings::HttpResponse& response
    );
    void getAvailableSeatsForMovie(
        stefanfrings::HttpRequest& request,
        stefanfrings::HttpResponse& response
    );
    void reserverSeats(
        stefanfrings::HttpRequest& request,
        stefanfrings::HttpResponse& response
    );

    void setTheaters(
        int movieIndex,
        const std::vector<QString>& theaterNames
    );

private:
    std::vector<beamtrail::Movie> movies;
    QMutex mux;

};

#endif // BOOKINGSERVICE_HPP
