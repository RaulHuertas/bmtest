#ifndef THEATER_H
#define THEATER_H

#include <vector>
#include <QString>
#include "seat.hpp"

namespace beamtrail {

class Theater
{

private:




public:
    std::vector<beamtrail::Seat> seats;
    QString name;
    Theater();

    void setNumberOfSeats(int n);
    int nTotalSeats()const;
    int nAvailableSeats()const;
    int nOccupiedSeats()const;

    std::vector<int> availableSeats()const;
    bool occupy(std::vector<int> seatNumbers);

};

};

#endif // THEATER_H
