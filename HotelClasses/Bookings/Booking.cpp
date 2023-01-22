#include "Booking.h"
/// constructor

Booking::Booking(Room room, std::pair<HTime, HTime> duration,User user):
        _room(room), _checkIn(duration.first), _user(user)
        , _price(), _bookingId(), _nights(), _payment(), _recipe()
{
    this->_nights = Utilities::getNumberOfDays(this->_checkIn, this->_checkOut);
    this->_price = room.getPrice() * this->_nights;
    this->_bookingId = Utilities::generateUniqeNmbr();

    this->_payment = Payment(MyEnums::PaymentMethod::Swish, MyEnums::BookingStatus::Loading, MyEnums::CancellationPolicy::Week);
    this->_recipe = Recipe(this,&this->_payment);
}
Booking::~Booking()
{

}

