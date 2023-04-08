#include "Bus.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    std::time_t now = std::time(nullptr);
    int duration = static_cast<int>(std::difftime(now, timeOfEntry));
    duration *= 0.75; // apply 25% reduction
    return duration;
}
