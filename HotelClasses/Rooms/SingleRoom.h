#ifndef COASTALOASIS_SINGLEROOM_H
#define COASTALOASIS_SINGLEROOM_H
#include "Room.h"

class SingleRoom: public Room{

private:
    unsigned int _windows;
public:
    ///constructors
    SingleRoom(unsigned roomNumber, unsigned price);
    SingleRoom(unsigned int windows,MyEnums::BedType bedSize, std::string description, unsigned roomNumber, unsigned price);
    SingleRoom(unsigned int windows,MyEnums::BedType bedSize, const WeeklySchedule& reservations,
               std::string description, unsigned roomNumber, unsigned price);
    ~SingleRoom();

    ///getters & setters
    const unsigned int& getWindows(){return _windows;}

    void setWindows(const unsigned int windows){this->_windows = windows;}

};
#endif