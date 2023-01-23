#ifndef COASTALOASIS_SUITE_H
#define COASTALOASIS_SUITE_H
#include "Room.h"
class Suite: public Room {

private:
        bool _hasBalcony;
        bool _hasSpa;
public:
    ///constructor
    Suite();
    Suite(unsigned roomNumber, unsigned price);
    Suite(bool hasBalcony, bool hasSpa,MyEnums::BedType bedSize,std::string description, unsigned roomNumber, unsigned price);
    Suite(bool hasBalcony, bool hasSpa,MyEnums::BedType bedSize,const WeeklySchedule& reservations, std::string description, unsigned roomNumber, unsigned price);
    ~Suite();

    ///Getters & setters
    const bool& getHasBalcony(){return this->_hasBalcony;}
    const bool& getHasSpa(){return this->_hasSpa;}

    void setHasBalcony(const bool& hasBalcony){this->_hasBalcony = hasBalcony;}
    void setHasSpa(const bool& hasSpa){this->_hasSpa = hasSpa;}
    ///operators


};
#endif
