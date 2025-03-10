#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <fstream>

class Planet {
private:
    char* name;         // Название планеты
    int diameter;       // Диаметр планеты
    bool life;          // Наличие жизни
    int satellites;     // Количество спутников

public:
    // Конструкторы и деструктор
    Planet();
    Planet(const char* name, int diameter, bool life, int satellites);
    Planet(const Planet& other); // Конструктор копирования
    ~Planet();

    // Оператор присваивания
    Planet& operator=(const Planet& other);

    // Методы доступа к полям (геттеры)
    const char* getName() const;
    int getDiameter() const;
    bool hasLife() const;
    int getSatellites() const;

    // Методы изменения полей (сеттеры)
    void setName(const char* name);
    void setDiameter(int diameter);
    void setLife(bool life);
    void setSatellites(int satellites);

    // Операторы
    friend std::ostream& operator<<(std::ostream& out, const Planet& planet);
    friend std::istream& operator>>(std::istream& in, Planet& planet);
    bool operator<(const Planet& other) const;
    bool operator==(const Planet& other) const;

    // Статические методы для работы с базой данных
    static void readDatabase(const char* filename, Planet*& planets, int& count);
    static void writeDatabase(const char* filename, Planet* planets, int count);
    static void sortDatabase(Planet* planets, int count);
    static void addPlanet(Planet*& planets, int& count, const Planet& planet);
    static void removePlanet(Planet*& planets, int& count, int index);
    static void editPlanet(Planet* planets, int count, int index, const Planet& newPlanet);
    static void printDatabase(Planet* planets, int count);
};

#endif // PLANET_H
