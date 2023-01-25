#ifndef COASTALOASIS_BOOKING_H
#define COASTALOASIS_BOOKING_H
#include "Payment.h"
#include "Recipe.h"
#include "Room.h"
#include "HTime.h"
class Booking {

private:
    User _user;
    Room _room;
    Payment _payment;
    Recipe _recipe;

    HTime _checkIn;
    HTime _checkOut;

    unsigned int _price;
    unsigned int _nights;
    unsigned int _bookingId;

public:

    ///Constructor
    Booking(Room room, std::pair<HTime, HTime> duration,User user);
    ~Booking();
    ///Getter & Setter

    const User& getUser()const{return this->_user;}
    const Room& getRooom()const{return this->_room;}
    const Payment& getPayment()const{return this->_payment;}
    const Recipe& getRecipe()const{return this->_recipe;}
    const HTime& getCheckIn()const{return this->_checkIn;}
    const HTime& getCheckOut()const{return this->_checkOut;}
    const unsigned int getPrice()const{return this->_price;}
    const unsigned int getNights()const{return this->_nights;}
    const unsigned int getBookingId()const{return this->_bookingId;}

    void setUser(const User& user){this->_user = user;}
    void setRoom(const Room& room){this->_room = room;}
    void setPayment(const Payment& payment){this->_payment = payment;}
    void setRecipe(const Recipe& recipe){this->_recipe = recipe;}
    void setCheckIn(const HTime& checkIn){this->_checkIn = checkIn;}
    void setCheckOut(const HTime& checkOut){this->_checkOut = checkOut;}
    void setPrice(const unsigned int price){this->_price = price;}
    void setNights(const unsigned int nights){this->_nights = nights;}
    void setBookingId(const unsigned int bookingId){this->_bookingId = bookingId;}

    ///Operators


};
#endif
