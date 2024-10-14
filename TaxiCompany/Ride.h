#ifndef RIDE_H
#define RIDE_H

#include "Address.h"
#include "Payment.h"
#include "Customer.h"
#include "Driver.h"   

class Ride {

protected:
    int rideID;
    int numberOfPassengers;
    int rideTime;
    Address originAddress;
    Address destAddress;
    Payment payment;
    Customer& customer;
    Driver& driver;

public:
    // Constructors
    Ride(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay, Customer& cust, Driver& drv);

    // Getters
    int getRideID() const;
    int getNumberOfPassengers() const;
    int getRideTime() const;
    Address getOriginAddress() const;
    Address getDestAddress() const;
    Payment getPayment() const;
    Customer& getCustomer() const;
    Driver& getDriver() const;

    // Setters
    bool setRideID(int id);
    bool setNumberOfPassengers(int passengers);
    bool setRideTime(int time);
    bool setOriginAddress(const Address& origin);
    bool setDestAddress(const Address& dest);
    bool setPayment(const Payment& pay);

    void getRidePrice();//will be calculated according to the duration of the trip and the number of passengers

    void printRide() const;

};

#endif // RIDE_H