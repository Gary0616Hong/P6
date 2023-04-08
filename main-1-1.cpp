#include<iostream>

class Vehicle{
protected:
    std::time_t timeOfEntry;
    int ID;
public:
    Vehicle(int ID);
    int getID();
    virtual int getParkingDuration()=0;
};

Vehicle::Vehicle(int ID):ID(ID),timeOfEntry(std::time(nullptr)){
}

int Vehicle::getID(){
    return ID;
}

class Car:public Vehicle{
public:
    Car(int ID):Vehicle(ID){}
    int getParkingDuration(){
        int duration = std::time(nullptr) - timeOfEntry;
        return duration * 0.9;
    }
};

class Bus:public Vehicle{
public:
    Bus(int ID):Vehicle(ID){}
    int getParkingDuration(){
        int duration = std::time(nullptr) - timeOfEntry;
        return duration * 0.75;
    }
};

class Motorbike:public Vehicle{
public:
    Motorbike(int ID):Vehicle(ID){}
    int getParkingDuration(){
        int duration = std::time(nullptr) - timeOfEntry;
        return duration * 0.85;
    }
};