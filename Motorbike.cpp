#include "Motorbike.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    std::time_t now = std::time(nullptr);
    int duration = static_cast<int>(std::difftime(now, timeOfEntry));
    duration *= 0.85; // apply 15% reduction
    return duration;
}
