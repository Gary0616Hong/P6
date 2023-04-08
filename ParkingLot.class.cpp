#include "ParkingLot.h"

// Constructor
ParkingLot::ParkingLot(int maxCapacity) : maxCapacity(maxCapacity), count(0) {
    // Allocate memory for the dynamic array of pointers to Vehicle objects
    vehicles = new Vehicle*[maxCapacity];
}

// Destructor
ParkingLot::~ParkingLot() {
    // Deallocate memory for the dynamic array of pointers to Vehicle objects
    for (int i = 0; i < count; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;
}

// Method to park a vehicle in the lot
void ParkingLot::parkVehicle(Vehicle* vehicle) {
    // Check if there is space in the parking lot
    if (count == maxCapacity) {
        std::cout << "The lot is full\n";
    } else {
        // Add the vehicle to the vehicles array and increment the count
        vehicles[count++] = vehicle;
    }
}

// Method to unpark a vehicle from the lot
void ParkingLot::unparkVehicle(int id) {
    // Search for the vehicle with the given ID in the vehicles array
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (vehicles[i]->getId() == id) {
            index = i;
            break;
        }
    }
    // If the vehicle with the given ID is found, remove it from the lot and decrement the count
    if (index != -1) {
        delete vehicles[index];
        for (int i = index; i < count - 1; i++) {
            vehicles[i] = vehicles[i + 1];
        }
        count--;
    } else {
        std::cout << "Vehicle not in the lot\n";
    }
}

// Method to count the number of vehicles that have overstayed in the lot
int ParkingLot::countOverstayingVehicles(int maxParkingDuration) {
    int countOverstaying = 0;
    time_t now = time(nullptr);
    for (int i = 0; i < count; i++) {
        int duration = difftime(now, vehicles[i]->getEntryTime());
        if (duration > maxParkingDuration) {
            countOverstaying++;
        }
    }
    return countOverstaying;
}

// Method to get the current number of vehicles in the lot
int ParkingLot::getCount() {
    return count;
}
