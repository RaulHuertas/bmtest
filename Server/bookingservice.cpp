#include "bookingservice.hpp"



BookingService::BookingService(QObject *parent)
    : stefanfrings::HttpRequestHandler{parent}
{

    //Movie names
    setMovies(
        {
            "The Mummy",
            "Bolt",
            "Infinity War",
            "Tornado",
            "Top Gun",
            "Deadpool and Wolverine"
        }
    );
}

BookingService::~BookingService(){

}


void BookingService::setMovies(
    const std::vector<QString>& movieNames
){
    this->movies.resize(movieNames.size());
    for(int j=0; j<movieNames.size();j++){
        movies[j].setName( movieNames[j] );
    }
}

void BookingService::setTheaters(
    int movieIndex,
    const std::vector<QString>& theaterNames
){
    if(movies.size()<movieIndex){
        return;
    }
    movies[movieIndex].theaters.resize(theaterNames.size());
    int t = 0;
    for(auto& newTheater : theaterNames){
        movies[movieIndex].theaters[t].name = newTheater;
        t++;
    }
}


void BookingService::service(
    stefanfrings::HttpRequest& request,
    stefanfrings::HttpResponse& response
){

}



