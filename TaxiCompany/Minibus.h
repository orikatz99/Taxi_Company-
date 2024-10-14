#ifndef MINIBUS_H
#define MINIBUS_H

#include "Taxi.h"

const int MaxPassengerMinibus = 15;

class Minibus : public Taxi {

public:

    // Constructors
    Minibus(const char* vehicleNumber, const char* color);

    // Getters
    const char* getVehicleNumber() const;
    const char* getColor() const;

    // Setters
    bool setVehicleNumber(const char* vehicleNumber);
    bool setColor(const char* color);

    virtual Taxi* findTaxiByTaxiNumber(char* vehicleNumber, Taxi* taxiArr, int count) const override;

    // Override clone method
    virtual Minibus* clone() const override;

    void printTaxi() const override;

};

#endif // MINIBUS_H
