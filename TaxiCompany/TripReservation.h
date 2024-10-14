#ifndef TRIPRESERVATION_H
#define TRIPRESERVATION_H

#include "Ride.h"
#include "Date.h"

class TripReservation : public Ride {

protected:
    Date date;

public:
    // Constructors
    TripReservation(const Ride& ride , const Date& date);

    // Getters
    Date getDate() const;

    // Setters
    bool setDate(const Date& date);
    int getRidePrice(Ride& ride);

    void printTripReservation() const;

};

#endif // TRIPRESERVATION_H
