#include <iostream>
#include "ParkingLot.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot parkingLot(10);

    // Park 5 Car objects, 3 Bus objects, and 2 Motorbike objects in the parking lot
    for (int i = 0; i < 5; i++) {
        Car* car = new Car(i);
        parkingLot.parkVehicle(car);
    }

    for (int i = 0; i < 3; i++) {
        Bus* bus = new Bus(i);
        parkingLot.parkVehicle(bus);
    }

    for (int i = 0; i < 2; i++) {
        Motorbike* motorbike = new Motorbike(i);
        parkingLot.parkVehicle(motorbike);
    }

    // Count the number of vehicles that have overstayed in the parking lot for more than 15 seconds
    int count = parkingLot.countOverstayingVehicles(15);
    std::cout << "Number of overstaying vehicles: " << count << std::endl;

    return 0;
}
