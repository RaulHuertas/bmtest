#ifndef THEATER_H
#define THEATER_H

#include <vector>
#include "seat.hpp"
#include "movie.hpp"

namespace beamtrail {

class Theater
{

private:
    std::vector<beamtrail::Seat> seats;
    std::vector<beamtrail::Movie> movies;
public:
    Theater(int seatsNumber = 20);

    void setMovies(const std::vector<QString>& movieNames);

    int nTotalSeats()const;
    int nAvailableSeats()const;
    int nOccupiedSeats()const;

    std::vector<int> availableSeats()const;
    void occupy(std::vector<int> seatNumbers);

};

};

#endif // THEATER_H
