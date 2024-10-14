#include <iostream>
#include <string>
#include "TaxiCompany.h"
#include "Minibus.h"
#include "PrivateTaxi.h"
#include "Address.h"


using namespace std;


enum eMenuOptions
{
    eAddDriver, eAddTaxi, eAddCustomer, eAddTripReservation, eAddRide, ePrintCompany, ePrintRides,
    ePrintTripReservation, ePrintCustomers, ePrintDrivers, ePrintCustomerDrivers, eCalculateIncome, eNofOptions
};

const std::string str[eNofOptions] = { "Add Driver", "Add Customer", "Add Trip Reservation", "Add ride", 
                                      "Print Taxi Company", "Print all Rides", "Print all Trip Reservations", 
                                      "Print all Cusromers ","Print all Drivers ", "Print all Cusromer Drivers ", "Calculate income",
                                      };

#define EXIT -1

int menu();
TaxiCompany* initCompany();
void addDriver(TaxiCompany& comp);
Taxi& addTaxi(TaxiCompany& comp);
void addCustomer(TaxiCompany& comp);
Ride& addRide(TaxiCompany& comp, Customer& customer);
Driver* addDriverForRide(TaxiCompany& comp, int numberOfPassengers);
void addTripReservation(TaxiCompany& comp);
Address& addAddress();

int main()
{
    TaxiCompany* comp = initCompany();
    int option;
    bool stop = false;

    do
    {
        option = menu();
        switch (option)
        {
        case eAddDriver:
            addDriver(*comp);
            break;

        case eAddCustomer:
            addCustomer(*comp);
            break;

        case eAddTripReservation:
            addTripReservation(*comp);
            break;

        case eAddRide:
        {
            Customer* cust = nullptr;
            char* customer = new char[20];
            cout << "Enter the customer name: " << endl;
            cin.getline(customer, 20);
            bool exist = false;
            for (int i = 0; i < comp->getCustomerCount() && !exist; i++)
            {
                if (strcmp(comp->getCustomerArr()[i].getName(), customer) == 0)
                {
                    cust = comp->findCustomerByName(customer);
                    exist = true;
                }
            }
            if (!exist)
                cout << "You are not in the customer list, before booking a ride you will need to register as a customer" << endl;
            else
                comp->addRide(addRide(*comp, *cust));
            delete[]customer;
            break;
        }

        case ePrintCompany:
            comp->printTaxiCompany();
            break;

        case ePrintRides:
            comp->printAllRides();
            break;

        case ePrintTripReservation:
            comp->printAllTripReservation();
            break;

        case ePrintCustomers:
            comp->printAllCustomers();
            break; 
        
        case ePrintDrivers:
                comp->printAllDrivers();
                break;

        case ePrintCustomerDrivers:
            comp->printAllCustomerDrivers();
            break;

        case eCalculateIncome:
            comp->calculateIncome();
            break;


        case EXIT:
            std::cout << "Bye bye" << std::endl;
            stop = true;
            break;

        default:
            std::cout << "Wrong option" << std::endl;
            break;
        }
    } while (!stop);

    return 0;
}

int menu()
{
    int option;
    std::cout << "\n\n";
    std::cout << "Please choose one of the following options" << std::endl;
    for (int i = 0; i < eNofOptions; i++)
        std::cout << i << " - " << str[i] << std::endl;
    std::cout << EXIT << " - Quit" << std::endl;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean buffer
    return option;
}

TaxiCompany* initCompany()
{
    char* companyName = new char[50];
    cout << "Enter the company name: " << endl;
    cin.getline(companyName, 50);

    int num;
    char* city = new char[20];
    char* street = new char[20];

    cout << "Please enter the company address" << endl;
    cout << "Enter the name of the city" << endl;
    cin.getline(city, 20);
    cout << "Enter the street name" << endl;
    cin.getline(street, 20);
    cout << "Enter a house number" << endl;
    cin >> num;

    Address newAddress(num, street, city);

    TaxiCompany* comp = new TaxiCompany(companyName, newAddress,0 , nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0, nullptr);

    delete[]companyName;
    delete[]street;
    delete[]city;

    return comp;
}

void addDriver(TaxiCompany& comp)
{
    char* driverName = new char[20];
    cout << "Enter the driver name: " << endl;
    cin.getline(driverName, 20);

    char id[ID_LEN + 1];
    cout << "Enter the ID number: " << endl;
    cin.getline(id, ID_LEN + 1);

    char licenseNumber[LICENSE_NUMBER_SIZE + 1];
    cout << "Enter the license number: " << endl;
    cin.getline(licenseNumber, LICENSE_NUMBER_SIZE + 1);

    //At first the driver has no trips, only after he is early in the company can you add trips
    
    Taxi& taxi = addTaxi(comp);
    Driver newDriver(driverName, id, licenseNumber,nullptr, 0, taxi);
    comp.addDriver(newDriver);

    char answer;
    // check if the new driver is an customer in the company
    for (int i = 0; i <comp.getCustomerCount(); i++)
    {
        if (strcmp(comp.getCustomerArr()[i].getName(), newDriver.getName()) == 0)
        {
            do
            {
                cout << "There is a customer in our company with the same name, is it the same person? (y- for yes, n- for no)" << endl;
                cin >> answer;
                cin.ignore();

                if (answer == 'y')
                {
                    Customer* cust = comp.findCustomerByName(newDriver.getName());
                    CustomerDriver* custDriv = new CustomerDriver(newDriver.getName(), newDriver.getId() ,*cust, newDriver);
                    comp.addCustomerDriver(*custDriv);
                    delete custDriv;
                }
                else if (answer != 'n')
                {
                    cout << "Invalid input entered" << endl;
                }

            } while (answer != 'y' && answer != 'n');
        }
    }
    // Clean up dynamically allocated memory
    delete[] driverName;
  
}

Taxi& addTaxi(TaxiCompany& comp)
{
    char vehicleNumber[VEHICLE_NUMBER_SIZE + 1];
    cout << "Enter the vehicle number: " << endl;
    cin.getline(vehicleNumber, VEHICLE_NUMBER_SIZE + 1);

    char* color = new char[10];
    cout << "Enter the color of the car: " << endl;
    cin.getline(color, 10);

    int choice;
    bool stop = true;

    do {
        cout << "\nWhat kind of taxi do you want? Minibus or private taxi?: ";
        cout << "\nChoose 1 for minibus, 2 for private taxi: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Minibus
        {
            Taxi* newTaxi = new Minibus(vehicleNumber, color);
            comp.addTaxi(*newTaxi);
            cout << "\nA maximum of " << MaxPassengerMinibus << "passengers can be transported in this vehicle ";
            return *newTaxi;
        }
        case 2: // Private taxi
        {
            Taxi* newTaxi = new Minibus(vehicleNumber, color);
            comp.addTaxi(*newTaxi);
            cout << "\nA maximum of " << MaxPassengerPrivate << "passengers can be transported in this vehicle ";
            return *newTaxi;
        }

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (stop);

    // In case something goes wrong, add a return statement here (though this should never be reached)
    // Assuming the default return would be a reference to an already existing Taxi object.
    return *(new Minibus("DefaultNumber", "DefaultColor"));
}

void addCustomer(TaxiCompany& comp)
{
    char* customerName = new char[20];
    cout << "Enter the customer name: " << endl;
    cin.getline(customerName, 20);

    char id[ID_LEN + 1];
    cout << "Enter the ID number: " << endl;
    cin.getline(id, ID_LEN + 1);

    char phoneNumber[PHONE_NUMBER_SIZE + 1];
    cout << "Enter the phone number: " << endl;
    cin.getline(phoneNumber, PHONE_NUMBER_SIZE + 1);

    Customer newCustomer(customerName, id, phoneNumber);
    comp.addCustomer(newCustomer);

    char answer;
    // check if the new customer is an driver in the company
    for (int i = 0; i < comp.getDriversCount(); i++)
    {
        if (strcmp(comp.getDriversArr()[i]->getName(), newCustomer.getName()) == 0)
        {
            do
            {
                cout << "There is a driver in our company with the same name, is it the same person? (y- for yes, n- for no)" << endl;
                cin >> answer;
                cin.ignore();

                if (answer == 'y')
                {
                    Driver* driv = comp.findDriverByName(newCustomer.getName());
                    CustomerDriver* custDriv = new CustomerDriver(newCustomer.getName(), newCustomer.getId(), newCustomer, *driv);
                    comp.addCustomerDriver(*custDriv);
                    delete custDriv;
                }
                else if (answer != 'n')
                {
                    cout << "Invalid input entered" << endl;
                }

            } while (answer != 'y' && answer != 'n');
        }
    }
    // Clean up dynamically allocated memory
    delete[] customerName;
}

Ride& addRide(TaxiCompany& comp, Customer& customer)
{
    bool valid;
    int rideID, numberOfPassengers, rideTime;
    do {
        valid = true;
        cout << "Enter the trip number: " << endl;
        cin >> rideID;
        if (rideID <= 0)
        {
            valid = false;
            cout << "Invalid input" << endl;
        }
    } while (!valid);

    do {
        valid = true;
        cout << "How many passengers are you? The maximum per trip is 15 passengers: " << endl;
        cin >> numberOfPassengers;
        if (numberOfPassengers <= 0 || numberOfPassengers>15)
        {
            valid = false;
            cout << "Invalid input" << endl;
        }
    } while (!valid);

    do {
        valid = true;
        cout << "How long will the trip last? (minimum order is 5 minutes drive): " << endl;
        cin >> rideTime;
        if (rideTime < 5)
        {
            valid = false;
            cout << "Invalid input" << endl;
        }
    } while (!valid);

    cout << "What is the pickup address for the ride?" << endl;
    Address& origin = addAddress();
    cout << "What is the destination address for the trip?" << endl;
    Address& dest = addAddress();
  
    Driver* driv = addDriverForRide(comp, numberOfPassengers);
   
    Ride* newRide = new Ride(rideID, numberOfPassengers, rideTime,origin, dest, {Credit, 0},customer, *driv);

    newRide->getRidePrice();
    int choice;
    do {
        std::cout << "Please choose a payment option:\n";
        for (int i = 0; i < NofOpt; ++i) 
            std::cout << i + 1 << ": " << OptStr[i] << "\n";
        std::cout << "Enter your choice (1-" << NofOpt << "): ";
        std::cin >> choice;
    } while (choice < 1 || choice > NofOpt);
    PaymentOption selectedOption = NofOpt;
    if (choice == 1) 
        selectedOption = Credit;
    else if (choice == 2) 
        selectedOption = Cash;
    newRide->getPayment().setOption(selectedOption);

    return *newRide;
}

Driver* addDriverForRide(TaxiCompany& comp, int numberOfPassengers)
{
    Driver* driv = nullptr;
    bool exist , valid;
    comp.printAllDrivers();
    do {
        valid = true;
        char* drivername = new char[20];
        cout << "Which driver you want to take you, pay attention to the size of the taxi (Write his name): " << endl;
        cin.getline(drivername, 20);
        exist = false;
        for (int i = 0; i < comp.getDriversCount() && !exist; i++)
        {
            if (strcmp(comp.getDriversArr()[i]->getName(), drivername) == 0)
            {
                driv = comp.findDriverByName(drivername);
                exist = true;
                if (!comp.CheckTaxi(*driv, numberOfPassengers))
                {
                    valid = false;
                    cout << "Invalid The size of the taxi is not enough for the number of passengers, you will be forced to choose another driver" << endl;
                }
            }
        }
        if (!exist)
            cout << "We don't have a driver with that name" << endl;

    } while (!valid || !exist);

    return driv;
}

void addTripReservation(TaxiCompany& comp)
{
    Customer* cust = nullptr;
    char* customer = new char[20];
    cout << "Enter the customer name: " << endl;
    cin.getline(customer, 20);
    bool exist = false;
    for (int i = 0; i < comp.getCustomerCount() && !exist; i++)
    {
        if (strcmp(comp.getCustomerArr()[i].getName(), customer) == 0)
        {
            cust = comp.findCustomerByName(customer);
            exist = true;
        }
    }
    if (!exist)
    {
        cout << "You are not in the customer list, before booking a ride you will need to register as a customer" << endl;
        delete[]customer;
        return;
    }   
    Ride ride = addRide(comp,*cust);
    int day, month, year;
    Date date(0,0,0);
    bool correct;
    do{
        correct = true;
        cout << "When does the member have to return the books?" << endl;
        cout << "Enter a day (an Number): ";
        cin >> day;
        cout << "Enter a month (an Number): ";
        cin >> month;
        cout << "Enter a year: ";
        cin >> year;
        if (!date.setYear(year) || !date.setMonth(month) || !date.setDay(day))
        {
            cout << "The date is incorrect " << endl;
            correct = false;
        }
    } while (!correct);

    TripReservation* tripRes = new TripReservation(ride, date);
    comp.addTripReservation(*tripRes);
    delete[]customer;
}

Address& addAddress()
{
    char* city = new char[20];
    cout << "Write the name of the city: " << endl;
    cin.getline(city, 20);

    char* street = new char[20];
    cout << "Write the name of the street: " << endl;
    cin.getline(street, 20);

    int num;
    cout << "what is the house number: " << endl;
    cin >> num;

    Address* address=new Address(num, street, city);
    return *address;
}

