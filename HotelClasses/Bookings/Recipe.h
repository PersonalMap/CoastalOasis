#ifndef COASTALOASIS_RECIPE_H
#define COASTALOASIS_RECIPE_H
#include <string>
#include "user.h"
#include "HTime.h"
#include "Payment.h"
#include "Room.h"
class Booking; //forward declaration avoid a circular include
class Recipe {

private:

    Booking* _booking;
    Payment* _payment;

public:
    Recipe();
    Recipe(Booking* booking, Payment* payment);
    ~Recipe();

};
#endif
