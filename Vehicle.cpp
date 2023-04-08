#include "vehicle.h"

Vehicle::Vehicle(int id) : timeOfEntry(std::time(nullptr)), ID(id) {}

int Vehicle::getID() const {
    return ID;
}

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    int parkingDuration = std::difftime(std::time(nullptr), timeOfEntry);
    return static_cast<int>(parkingDuration * 0.9);
}

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    int parkingDuration = std::difftime(std::time(nullptr), timeOfEntry);
    return static_cast<int>(parkingDuration * 0.75);
}

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    int parkingDuration = std::difftime(std::time(nullptr), timeOfEntry);
    return static_cast<int>(parkingDuration * 0.85);
}
