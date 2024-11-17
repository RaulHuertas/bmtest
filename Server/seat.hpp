#ifndef SEAT_HPP
#define SEAT_HPP

namespace beamtrail {


class Seat
{
private:
    bool m_occupied = false;

public:

    Seat();

    bool occupied(){
        return m_occupied;
    }

    const bool& occupied()const{
        return m_occupied;
    }

    void setOccupied(bool newValue=true){
        if(m_occupied!=newValue){
            m_occupied = newValue;
        }
    }

};

};

#endif // SEAT_HPP
