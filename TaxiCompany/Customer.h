#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

const int PHONE_NUMBER_SIZE = 10;

class Customer : public Person {

private:
    char phoneNumber[PHONE_NUMBER_SIZE + 1];

public:
    // Constructors
    Customer(const char* name, const char* id, const char* phoneNumber);

    // Getters
    const char* getName() const;
    const char* getId() const;
    const char* getPhoneNumber() const;


    // Setters
    bool setName(const char* name);
    bool setId(const char* id);
    bool setPhoneNumber(const char* phoneNumber);

    void printCustomer() const;
};

#endif // CUSTOMER_H
