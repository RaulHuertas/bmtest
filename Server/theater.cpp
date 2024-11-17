#include "theater.hpp"

using namespace beamtrail;

Theater::Theater() {

}

void Theater::setNumberOfSeats(int n){
    return seats.resize(n);
}

int Theater::nTotalSeats()const{
    return (int)seats.size();
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

bool Theater::occupy(std::vector<int> seatNumbers){
    //First check that all seats are actually available
    for(auto& requestedIndex : seatNumbers){
        if(requestedIndex<0){
            return false;//invalid index
        }
        if(requestedIndex>seats.size()){
            return false;//wrong index
        }

        if (seats[requestedIndex].occupied()){
            return false;//seat already occupied
        }
    }
    //Do the actual operation
    for(auto& number : seatNumbers){
        if(seats.size()<number){
            continue;
        }
        seats[number].setOccupied();
    }
    return true;
}



