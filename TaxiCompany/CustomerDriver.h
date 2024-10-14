#ifndef CUSTOMERDRIVER_H
#define CUSTOMERDRIVER_H

#include "Customer.h"
#include "Driver.h"

class CustomerDriver : public Customer, public Driver {

public:
    // Constructors
    CustomerDriver(const char* name, const char* id, const Customer& customer, const Driver& driver);//Since the name and ID attributes are common to both, we will put them separately and handle it in the constructor implementation

    // Getters
    const char* getName() const;
    const char* getId() const;
    const char* getLicenseNumber() const;
    int         getRideCount() const;
    Ride** getRide() const;
    Taxi& getTaxi() const;
    const char* getPhoneNumber() const;

    // Setters
    bool setName(const char* name);
    bool setId(const char* id);
    bool setLicenseNumber(const char* licenseNumber);
    bool setRideCount(int rideCount);
    bool setRide(const Ride** ride);
    bool setTaxi(const Taxi& taxi);
    bool setPhoneNumber(const char* phoneNumber);

    void printCustomerDriver() const;

};

#endif // CUSTOMERDRIVER_H
