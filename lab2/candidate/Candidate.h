#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <fstream>

class Candidate {
private:
    char* name;   // Имя кандидата
    int age;      // Возраст кандидата
    char* party;  // Партия кандидата
    int votes;    // Количество голосов

public:
    // Конструкторы и деструктор
    Candidate();
    Candidate(const char* name, int age, const char* party, int votes);
    Candidate(const Candidate& other); // Конструктор копирования
    ~Candidate();

    // Оператор присваивания
    Candidate& operator=(const Candidate& other);

    // Методы доступа к полям (геттеры)
    const char* getName() const;
    int getAge() const;
    const char* getParty() const;
    int getVotes() const;

    // Методы изменения полей (сеттеры)
    void setName(const char* name);
    void setAge(int age);
    void setParty(const char* party);
    void setVotes(int votes);

    // Операторы
    friend std::ostream& operator<<(std::ostream& out, const Candidate& candidate);
    friend std::istream& operator>>(std::istream& in, Candidate& candidate);
    bool operator<(const Candidate& other) const;
    bool operator==(const Candidate& other) const;

    // Статические методы для работы с базой данных
    static void readDatabase(const char* filename, Candidate*& candidates, int& count);
    static void writeDatabase(const char* filename, Candidate* candidates, int count);
    static void sortDatabase(Candidate* candidates, int count);
    static void addCandidate(Candidate*& candidates, int& count, const Candidate& candidate);
    static void removeCandidate(Candidate*& candidates, int& count, int index);
    static void editCandidate(Candidate* candidates, int count, int index, const Candidate& newCandidate);
    static void printDatabase(Candidate* candidates, int count);
};

#endif // CANDIDATE_H
