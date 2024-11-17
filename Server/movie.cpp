#include "movie.hpp"

using namespace beamtrail;

Movie::Movie(const QString& name) {
    this->m_name = name;
}

Movie::Movie(){

}

void Movie::setName(const QString& newName){
    m_name = newName;
}






