#include "theater.hpp"

using namespace beamtrail;

Theater::Theater(int seatsNumber) {
    this->seats.resize(seatsNumber);

}

void Theater::setMovies(
    const std::vector<QString>& movieNames
){
    this->movies.resize(movieNames.size());
    for(int j=0; j<movieNames.size();j++){
        movies[j].setName( movieNames[j] );
    }
}

int Theater::nTotalSeats()const{
    return seats.size();
}

int Theater::nAvailableSeats()const{
    int result = nTotalSeats();
    for(auto& seat : seats){
        if (seat.occupied()){
            result--;
        }
    }
    return result;
}

int Theater::nOccupiedSeats()const{
    int result = nTotalSeats();
    result-=nAvailableSeats();
    return result;
}

std::vector<int> Theater::availableSeats() const{
    std::vector<int> result;
    result.reserve(seats.size());
    int index = 0;
    for (auto& seat: seats){
        if(!seat.occupied()){
            result.push_back(index);
        }
        index++;
    }
    return result;
}

void Theater::occupy(std::vector<int> seatNumbers){
    for(auto& number : seatNumbers){
        if(seats.size()<number){
            continue;
        }
        seats[number].setOccupied();
    }
}



