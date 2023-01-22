#include "Recipe.h"
#include "Booking.h"

///constructors
Recipe::Recipe()=default;
Recipe::Recipe(Booking* booking, Payment* payment): _booking(booking), _payment(payment)
{
 payment->setBookingStatus(MyEnums::BookingStatus::Confirmed);
};
Recipe::~Recipe() = default;