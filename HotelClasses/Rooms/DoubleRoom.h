#ifndef COASTALOASIS_DOUBLEROOM_H
#define COASTALOASIS_DOUBLEROOM_H
#include "Room.h"
class DoubleRoom: public Room{
private:
    unsigned int _Beds;
    unsigned int _Rooms;

public:
    ///Constructor
    DoubleRoom(unsigned roomNumber, unsigned price);
    DoubleRoom(unsigned int beds, unsigned int rooms,MyEnums::BedType bedSize,std::string description, unsigned roomNumber, unsigned price);
    DoubleRoom(unsigned int beds, unsigned int rooms,MyEnums::BedType bedSize,const WeeklySchedule& reservations, std::string description, unsigned roomNumber, unsigned price);
    ~DoubleRoom();

    ///Getters & Setters
    const unsigned int& getBeds()const{return this->_Beds;}
    const unsigned int& getRooms()const{return this->_Rooms;}

    void setBeds(const unsigned int& beds){this->_Beds = beds;}
    void setRooms(const unsigned int& rooms){this->_Rooms = rooms;}
};
#endif
