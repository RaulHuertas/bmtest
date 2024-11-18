#include "bookingservice.hpp"
#include <QMutexLocker>
#include <QDebug>


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
    setTheaters(0, {"Main Hall", "Green Harbor", "Main Av.", "Pacific Av."});
    setTheaters(1, {"Main Hall", "Green Harbor", "Down Town", "Main Av.", "Pacific Av."});
    setTheaters(2, { "Green Harbor", "Down Town", "Main Av.", "Pacific Av."});
    setTheaters(3, {"Main Hall", "Green Harbor", "Down Town", "Main Av.", "Pacific Av."});
    setTheaters(4, {"Main Hall", "Green Harbor", "Down Town", "Main Av.", "Pacific Av."});
    setTheaters(5, {"Main Hall", "Green Harbor", "Pacific Av."});

    return;
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
        movies[movieIndex].theaters[t].setNumberOfSeats(20);
        t++;
    }
}

std::vector<QString> BookingService::getMovies(){
    //No need to long. List of movies doesn't change
    std::vector<QString> result;
    result.resize(movies.size());
    for(int m = 0; m<movies.size();m++){
        result[m] = movies[m].name();
    }
    return result;
}

std::vector<QString> BookingService::getAvailableTheatersMovie(int movieID){
    //No need to long. List of movies doesn't change
    std::vector<QString> result;
    if(movieID<0){
        return result;
    }
    if(movieID>=movies.size()){
        return result;
    }

    result.resize(movies[movieID].theaters.size());

    for(int t = 0; t<movies[movieID].theaters.size();t++){
        result[t] = movies[movieID].theaters[t].name;
    }
    return result;
}

std::vector<int> BookingService::getAvailableSeatsForMovie(int movieID, int theaterID){
    QMutexLocker locker(&mux);//this is constantly changing
    std::vector<int> result;
    if(movieID<0){
        return result;
    }
    if(movieID>=movies.size()){
        return result;
    }
    if(theaterID<0){
        return result;
    }
    if(theaterID>=movies[movieID].theaters.size()){
        return result;
    }

    for(int s = 0; s<movies[movieID].theaters[theaterID].nTotalSeats();s++){
        if(!movies[movieID].theaters[theaterID].seats[s].occupied()){
            result.push_back(s);
        }
    }
    return result;
}

bool BookingService::bookSeats(
    int movieID,
    int theaterID,
    std::vector<int> requestedSeats
){
    QMutexLocker locker(&mux);//this is bookSeats changing
    std::vector<int> result;
    if(movieID<0){
        return false;
    }
    if(movieID>=movies.size()){
        return false;
    }
    if(theaterID<0){
        return false;
    }
    if(theaterID>=movies[movieID].theaters.size()){
        return false;
    }

    bool var = movies[movieID].theaters[theaterID].occupy(requestedSeats);

    return var;
}


void BookingService::service(
    stefanfrings::HttpRequest& request,
    stefanfrings::HttpResponse& response
){
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());
    if ( path=="/getMovies") {
        getMovies(request, response);
    }else if (path=="/getAvailableTheatersMovie") {
        getAvailableTheatersMovie(request, response);
    }else if (path=="/getAvailableSeatsForMovie") {
        getAvailableSeatsForMovie(request, response);
    }else if (path=="/stefanfrings") {
        reserverSeats(request, response);
    }else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.",true);
    }

    qDebug("RequestMapper: finished request");

}



