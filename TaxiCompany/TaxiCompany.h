#ifndef TAXI_COMPANY_H
#define TAXI_COMPANY_H

#include "Address.h"
#include "Taxi.h"
#include "TripReservation.h"
#include "CustomerDriver.h"

class TaxiCompany {

private:
    char* name;
    Address address;
    int driversCount;
    Driver** driversArr;
    int taxiCount;
    Taxi* taxiArr;
    int customerCount;
    Customer* customerArr;
    int ridesCount;
    Ride* ridesArr;
    int tripReservationCount;
    TripReservation* tripReservationArr;
    int customerDriverCount;
    CustomerDriver* customerDriversArr;

public:

    // Constructors
    TaxiCompany(const char* name, Address& address, int driversCount, Driver** driversArr, int taxiCount, Taxi* taxiArr, int customerCount, Customer* customerArr,int ridesCount, Ride* ridesArr, int tripReservationCount, TripReservation* tripReservationArr, int customerDriverCount, CustomerDriver* customerDriversArr);
    TaxiCompany(const TaxiCompany& other);        // Copy Constructor
    TaxiCompany(TaxiCompany&& other);             // Move Constructor
    ~TaxiCompany();                             // Destructor

    void operator=(const TaxiCompany& other);

    // Getters
    const char* getName() const;
    Address getAddress() const;
    int getDriversCount() const;
    Driver** getDriversArr() const;
    int getTaxiCount() const;
    Taxi* getTaxiArr() const;
    int getCustomerCount() const;
    Customer* getCustomerArr() const;
    int getTripReservationCount() const;
    TripReservation* getTripReservationArr() const;
    int getDeliverysCount() const;
    CustomerDriver* getCustomerDriversArr() const;

    // Setters
    bool setName(const char* name);
    bool setAddress(const Address& address);
    bool setDriversCount(int driversCount);
    bool setDriversArr(const Driver** driversArr);
    bool setTaxiCount(int taxiCount);
    bool setTaxiArr(const Taxi* taxi);
    bool setCustomerCount(int customerCount);
    bool setCustomerArr(const Customer* customerArr);
    bool setTripReservationCount(int TripReservationCount);
    bool setTripReservationAr(const TripReservation* TripReservationArr);
    bool setDeliverysCount(int deliverysCount);
    bool setCustomerDriversArr(const CustomerDriver* customerDriversArr);

    void addTaxi(Taxi& taxi);
    void addDriver(Driver& newDriver);
    void addCustomer(Customer& newCustomer);
    void addRide(Ride& ride);
    void addTripReservation(TripReservation& tripReservation);
    void addCustomerDriver(Customer& newCustomerDriver);
    void calculateIncome();
    void printTaxiCompany();
    void printAllTripReservation(); 
    void printAllRides(); 
    void printAllCustomerDrivers();
    void printAllCustomers();
    void printAllDrivers();

    Customer* findCustomerByName(const char* num);
    Driver* findDriverByName(const char* num);
    bool CheckTaxi(Driver& newDriver, int numberOfPassengers);
};

#endif // TAXI_COMPANY_H