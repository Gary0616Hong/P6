#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    std::time_t now = std::time(nullptr);
    int duration = static_cast<int>(std::difftime(now, timeOfEntry));
    duration *= 0.9; // apply 10% reduction
    return duration;
}