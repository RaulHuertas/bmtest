#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <QString>

namespace beamtrail {

class Movie
{
private:
    QString m_name;

public:
    Movie(const QString& name);
    Movie();

    inline QString name(){
        return m_name;
    }

    inline const QString& name()const{
        return m_name;
    }

    void setName(const QString& newName);
};

};

#endif // MOVIE_HPP
