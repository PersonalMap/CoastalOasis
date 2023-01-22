#ifndef COASTALOASIS_PAYMENT_H
#define COASTALOASIS_PAYMENT_H
#include "HotelEnums.h"
class Payment {

private:

    MyEnums::PaymentMethod _paymentMethod;
    MyEnums::BookingStatus _bookingStatus;
    MyEnums::CancellationPolicy _cancellationPolicy;

public:

    ///constructors
    Payment();
    Payment(MyEnums::PaymentMethod payment, MyEnums::BookingStatus bookingStatus, MyEnums::CancellationPolicy);
    ~Payment();

    //getters & setters
    const MyEnums::PaymentMethod& getPaymentMethod()const{return this->_paymentMethod;}
    const MyEnums::BookingStatus& getBookingStatus()const{return this->_bookingStatus;}
    const MyEnums::CancellationPolicy& getCancellationPolicy()const{return this->_cancellationPolicy;}

    void setPaymentMethod(const MyEnums::PaymentMethod& paymentMethod){this->_paymentMethod = paymentMethod;}
    void setBookingStatus(const MyEnums::BookingStatus& bookingStatus){this->_bookingStatus = bookingStatus;}
    void setCAncellationPolicy(const MyEnums::CancellationPolicy& cancellationPolicy){this->_cancellationPolicy = cancellationPolicy;}
};
#endif
