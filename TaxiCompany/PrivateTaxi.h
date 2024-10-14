#ifndef PRIVATE_TAXI_H
#define PRIVATE_TAXI_H
#include "Taxi.h"

const int MaxPassengerPrivate = 4;

class PrivateTaxi : public Taxi {

public:

    // Constructors
    PrivateTaxi(const char* vehicleNumber, const char* color);

    // Getters
    const char* getVehicleNumber() const;
    const char* getColor() const;

    // Setters
    bool setVehicleNumber(const char* vehicleNumber);
    bool setColor(const char* color);

    virtual Taxi* findTaxiByTaxiNumber(char* vehicleNumber, Taxi* taxiArr, int count) const override;

    // Override clone method
    virtual PrivateTaxi* clone() const override;

    void printTaxi() const override;
};

#endif // PRIVATE_TAXI_H