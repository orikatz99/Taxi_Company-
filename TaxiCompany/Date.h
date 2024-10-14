#ifndef DATE_H
#define DATE_H


class Date {

private:
    int day;
    int month;
    int year;


public:
    Date(int d, int m, int y);        // Constructor

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);

    void printDate() const;
};

#endif // DATE_H
