#ifndef ADDRESS_H
#define ADDRESS_H

#include <cstring> 

class Address {

private:
    int num;
    char* street;
    char* city;


public:
    // Constructors
    Address();
    Address(int n, const char* s, const char* c);
    Address(const Address& other);        // Copy Constructor
    Address(Address&& other);            // Move Constructor
    ~Address();                         // Destructor

    void operator=(const Address& other);

    // Getters
    int getNum() const;
    const char* getStreet() const;
    const char* getCity() const;

    // Setters
    bool setNum(int num);
    bool setStreet(const char* street);
    bool setCity(const char* city);

    void printAddress() const;
};

#endif // ADDRESS_H

