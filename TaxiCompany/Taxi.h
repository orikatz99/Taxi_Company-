#ifndef TAXI_H
#define TAXI_H

const int VEHICLE_NUMBER_SIZE = 8;

class Taxi {// abstract 

protected:
    char vehicleNumber[VEHICLE_NUMBER_SIZE + 1];
    char* color;

public:

    // Constructors
    Taxi(const char* vehicleNumber, const char* color);
    Taxi(const Taxi& other);        // Copy Constructor
    Taxi(Taxi&& other);            // Move Constructor
    virtual ~Taxi();                // Destructor

    const void operator=(const Taxi& other);

    // Getters
    const char* getVehicleNumber() const;
    const char* getColor() const;

    // Setters
    bool setVehicleNumber(const char* vehicleNumber);
    bool setColor(const char* color);

    virtual void printTaxi() const = 0;
    virtual Taxi* clone() const = 0;
    virtual Taxi* findTaxiByTaxiNumber(char* vehicleNumber, Taxi* taxiArr, int count) const = 0;

};

#endif // TAXI_H
