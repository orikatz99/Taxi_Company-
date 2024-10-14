#ifndef PAYMENT_H
#define PAYMENT_H


enum PaymentOption { Credit, Cash, NofOpt };

const char* OptStr[NofOpt] = { "Credit", "Cash" };

class Payment {

private:
    PaymentOption option;
    int price;

public:
    // Constructors
    Payment(PaymentOption opt, int p);

    // Getters
    PaymentOption getOption() const;
    int getPrice() const;

    // Setters
    bool setOption(PaymentOption opt);
    bool setPrice(int price);
};

#endif // PAYMENT_H
