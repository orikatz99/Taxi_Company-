#ifndef DELIVERY_H
#define DELIVERY_H

#include "TripReservation.h"

class Delivery : public Ride, public TripReservation {

private:
    char* product;
    double weight;

public:
    // Constructors
    Delivery(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay, Customer& cust, Driver& drv, const Date& date, const char* product, double weight);
    Delivery(const Delivery& other);        // Copy Constructor
    Delivery(Delivery&& other);             // Move Constructor
    ~Delivery();                            // Destructor

    void operator=(const Delivery& other);

    // Getters
    const char* getProduct() const;
    double getWeight() const;

    // Setters
    bool setProduct(const char* product);
    bool setWeight(double weight);

    int getRidePrice(Ride& ride);

};

#endif // DELIVERY_H
