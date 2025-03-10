#include "Planet.h"
#include <cstring>
#include <iostream>

// Конструктор по умолчанию
Planet::Planet() : name(nullptr), diameter(0), life(false), satellites(0) {}

// Параметризованный конструктор
Planet::Planet(const char* name, int diameter, bool life, int satellites) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->diameter = diameter;
    this->life = life;
    this->satellites = satellites;
}

// Конструктор копирования
Planet::Planet(const Planet& other) {
    if (other.name) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    } else {
        this->name = nullptr;
    }
    this->diameter = other.diameter;
    this->life = other.life;
    this->satellites = other.satellites;
}

// Деструктор
Planet::~Planet() {
    delete[] name;
}

// Оператор присваивания
Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {
        delete[] name;
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
        diameter = other.diameter;
        life = other.life;
        satellites = other.satellites;
    }
    return *this;
}

// Геттеры
const char* Planet::getName() const {
    return name;
}

int Planet::getDiameter() const {
    return diameter;
}

bool Planet::hasLife() const {
    return life;
}

int Planet::getSatellites() const {
    return satellites;
}

// Сеттеры
void Planet::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Planet::setDiameter(int diameter) {
    this->diameter = diameter;
}

void Planet::setLife(bool life) {
    this->life = life;
}

void Planet::setSatellites(int satellites) {
    this->satellites = satellites;
}

// Операторы ввода и вывода
std::ostream& operator<<(std::ostream& out, const Planet& planet) {
    out << planet.name << " " << planet.diameter << " " << planet.life << " " << planet.satellites;
    return out;
}

std::istream& operator>>(std::istream& in, Planet& planet) {
    char buffer[256];
    in >> buffer >> planet.diameter >> planet.life >> planet.satellites;
    planet.setName(buffer);
    return in;
}

// Операторы сравнения
bool Planet::operator<(const Planet& other) const {
    return diameter < other.diameter;
}

bool Planet::operator==(const Planet& other) const {
    return strcmp(name, other.name) == 0;
}

// Работа с базой данных
void Planet::readDatabase(const char* filename, Planet*& planets, int& count) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        count = 0;
        planets = nullptr;
        return;
    }
    file >> count;
    if (count > 0) {
        planets = new Planet[count];
        for (int i = 0; i < count; ++i) {
            file >> planets[i];
        }
    }
    file.close();
}

void Planet::writeDatabase(const char* filename, Planet* planets, int count) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }
    file << count << std::endl;
    for (int i = 0; i < count; ++i) {
        file << planets[i] << std::endl;
    }
    file.close();
}

void Planet::sortDatabase(Planet* planets, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (planets[j] < planets[j + 1]) {
                std::swap(planets[j], planets[j + 1]);
            }
        }
    }
}

void Planet::addPlanet(Planet*& planets, int& count, const Planet& planet) {
    Planet* newPlanets = new Planet[count + 1];
    for (int i = 0; i < count; ++i) {
        newPlanets[i] = planets[i];
    }
    newPlanets[count] = planet;
    delete[] planets;
    planets = newPlanets;
    ++count;
}

void Planet::removePlanet(Planet*& planets, int& count, int index) {
    if (index < 0 || index >= count) return;
    Planet* newPlanets = new Planet[count - 1];
    for (int i = 0; i < index; ++i) {
        newPlanets[i] = planets[i];
    }
    for (int i = index; i < count - 1; ++i) {
        newPlanets[i] = planets[i + 1];
    }
    delete[] planets;
    planets = newPlanets;
    --count;
}

void Planet::editPlanet(Planet* planets, int count, int index, const Planet& newPlanet) {
    if (index < 0 || index >= count) return;
    planets[index] = newPlanet;
}

void Planet::printDatabase(Planet* planets, int count) {
    if (planets == nullptr || count == 0) {
        std::cout << "База данных пуста." << std::endl;
        return;
    }
    std::cout << "База данных планет:" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << planets[i] << std::endl;
    }
}
