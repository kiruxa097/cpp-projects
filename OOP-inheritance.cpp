#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Базовый класс
class Vehicle {
protected:  // Защищенные элементы
    string model;
    int speed;
    int maxSpeed;
public:  // Доступные элементы
    void showInfo() {
        cout << "model: " << model << endl;
        cout << "speed: " << speed << endl;
        cout << "maxSpeed: " << maxSpeed << endl;
    }
    void accelerate(int value) {
        speed = min(speed + value, maxSpeed);
    }
    void brake(int value) {
        speed = max(speed - value, 0);
    }
};

// Производный класс
class Car: public Vehicle {
public:
    // Конструктор
    Car(string modelName) {
        model = modelName;
        speed = 0;
        maxSpeed = 200;
    }

    void turboBoost() {
        speed = min(speed + 50, maxSpeed);
    }
};

// Производный класс
class Truck: public Vehicle {
protected:  // Защищенные элементы
    int cargo;
    int maxCargo;
public:
    Truck(string modelName, int Maxcargo) {
        model = modelName;
        speed = 0;
        maxSpeed = 140;
        maxCargo = Maxcargo;
        cargo = 0;
    }
    void load(int kg) {
        if (cargo + kg <= maxCargo) cargo += kg;
        else cout << "overloading" << endl;
    }
    void unload(int kg) {
        cargo = max(cargo - kg, 0);
    }
    // Переопределили функцию из базового класса
    void showInfo() {
        Vehicle::showInfo();
        cout << "cargo: " << cargo << endl;
        cout << "maxCargo: " << maxCargo << endl;
    }
};

int main() {
    // Данные введены для иллюстрации работы классов
    Car bmw("BMW M3 g80");
    bmw.accelerate(60);
    bmw.turboBoost();
    bmw.showInfo();

    Truck volvo("Volvo FH", 20000);
    volvo.load(5000);
    volvo.accelerate(40);
    volvo.showInfo();
}