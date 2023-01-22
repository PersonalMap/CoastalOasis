#include "Payment.h"
///Constructors
Payment::Payment()=default;
Payment::Payment(MyEnums::PaymentMethod payment, MyEnums::BookingStatus bookingStatus, MyEnums::CancellationPolicy cancellationPolicy):
        _paymentMethod(payment), _bookingStatus(bookingStatus), _cancellationPolicy(cancellationPolicy){};
Payment::~Payment() = default;