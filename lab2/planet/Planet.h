#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <fstream>

class Planet {
private:
    char* name;
    int diameter;
    bool life;
    int satellites;

public:
    Planet();
    Planet(const char* name, int diameter, bool life, int satellites);
    Planet(const Planet& other);
    ~Planet();

    Planet& operator=(const Planet& other);

    const char* getName() const;
    int getDiameter() const;
    bool hasLife() const;
    int getSatellites() const;

    void setName(const char* name);
    void setDiameter(int diameter);
    void setLife(bool life);
    void setSatellites(int satellites);

    friend std::ostream& operator<<(std::ostream& out, const Planet& planet);
    friend std::istream& operator>>(std::istream& in, Planet& planet);
    bool operator<(const Planet& other) const;
    bool operator==(const Planet& other) const;

    static void readDatabase(const char* filename, Planet*& planets, int& count);
    static void writeDatabase(const char* filename, Planet* planets, int count);
    static void sortDatabase(Planet* planets, int count);
    static void addPlanet(Planet*& planets, int& count, const Planet& planet);
    static void removePlanet(Planet*& planets, int& count, int index);
    static void editPlanet(Planet* planets, int count, int index, const Planet& newPlanet);
    static void printDatabase(Planet* planets, int count);
};

#endif // PLANET_H
