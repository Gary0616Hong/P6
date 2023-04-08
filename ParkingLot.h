#pragma once

#include <iostream>
#include <ctime>
#include "Vehicle.h"

class ParkingLot {
public:
    ParkingLot(int maxCapacity);
    ~ParkingLot();
    void parkVehicle(Vehicle* vehicle);
    void unparkVehicle(int id);
    int countOverstayingVehicles(int maxParkingDuration);
    int getCount();

private:
    int maxCapacity;
    int count;
    Vehicle** vehicles;
};
