#include "Candidate.h"
#include <cstring>
#include <iostream>

Candidate::Candidate() : name(nullptr), age(0), party(nullptr), votes(0) {}

Candidate::Candidate(const char* name, int age, const char* party, int votes) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
    this->party = new char[strlen(party) + 1];
    strcpy(this->party, party);
    this->votes = votes;
}

Candidate::Candidate(const Candidate& other) {
    if (other.name) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    } else {
        this->name = nullptr;
    }

    this->age = other.age;

    if (other.party) {
        this->party = new char[strlen(other.party) + 1];
        strcpy(this->party, other.party);
    } else {
        this->party = nullptr;
    }

    this->votes = other.votes;
}

Candidate::~Candidate() {
    delete[] name;
    delete[] party;
}

Candidate& Candidate::operator=(const Candidate& other) {
    if (this != &other) {
        delete[] name;
        delete[] party;

        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }

        age = other.age;

        if (other.party) {
            party = new char[strlen(other.party) + 1];
            strcpy(party, other.party);
        } else {
            party = nullptr;
        }

        votes = other.votes;
    }
    return *this;
}

const char* Candidate::getName() const {
    return name;
}

int Candidate::getAge() const {
    return age;
}

const char* Candidate::getParty() const {
    return party;
}

int Candidate::getVotes() const {
    return votes;
}

void Candidate::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Candidate::setAge(int age) {
    this->age = age;
}

void Candidate::setParty(const char* party) {
    delete[] this->party;
    this->party = new char[strlen(party) + 1];
    strcpy(this->party, party);
}

void Candidate::setVotes(int votes) {
    this->votes = votes;
}

std::ostream& operator<<(std::ostream& out, const Candidate& candidate) {
    out << candidate.name << " " << candidate.age << " " << candidate.party << " " << candidate.votes;
    return out;
}

std::istream& operator>>(std::istream& in, Candidate& candidate) {
    char nameBuffer[256];
    char partyBuffer[256];
    in >> nameBuffer >> candidate.age >> partyBuffer >> candidate.votes;
    candidate.setName(nameBuffer);
    candidate.setParty(partyBuffer);
    return in;
}

bool Candidate::operator<(const Candidate& other) const {
    return votes < other.votes;
}

bool Candidate::operator==(const Candidate& other) const {
    return strcmp(name, other.name) == 0;
}

void Candidate::readDatabase(const char* filename, Candidate*& candidates, int& count) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        count = 0;
        candidates = nullptr;
        return;
    }
    file >> count;
    if (count > 0) {
        candidates = new Candidate[count];
        for (int i = 0; i < count; ++i) {
            file >> candidates[i];
        }
    }
    file.close();
}

void Candidate::writeDatabase(const char* filename, Candidate* candidates, int count) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }
    file << count << std::endl;
    for (int i = 0; i < count; ++i) {
        file << candidates[i] << std::endl;
    }
    file.close();
}

void Candidate::sortDatabase(Candidate* candidates, int count) {
    if (candidates == nullptr || count == 0) {
        std::cerr << "Ошибка: Невозможно отсортировать пустой массив кандидатов." << std::endl;
        return;
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (candidates[j] < candidates[j + 1]) {
                std::swap(candidates[j], candidates[j + 1]);
            }
        }
    }
    std::cout << "База данных отсортирована по голосам.\n";
}

void Candidate::addCandidate(Candidate*& candidates, int& count, const Candidate& candidate) {
    Candidate* newCandidates = new Candidate[count + 1];
    for (int i = 0; i < count; ++i) {
        newCandidates[i] = candidates[i];
    }
    newCandidates[count] = candidate;
    delete[] candidates;
    candidates = newCandidates;
    ++count;
}

void Candidate::removeCandidate(Candidate*& candidates, int& count, int index) {
    if (index < 0 || index >= count) return;
    Candidate* newCandidates = new Candidate[count - 1];
    for (int i = 0; i < index; ++i) {
        newCandidates[i] = candidates[i];
    }
    for (int i = index; i < count - 1; ++i) {
        newCandidates[i] = candidates[i + 1];
    }
    delete[] candidates;
    candidates = newCandidates;
    --count;
}

void Candidate::editCandidate(Candidate* candidates, int count, int index, const Candidate& newCandidate) {
    if (index < 0 || index >= count) return;
    candidates[index] = newCandidate;
}

void Candidate::printDatabase(Candidate* candidates, int count) {
    if (candidates == nullptr || count == 0) {
        std::cout << "База данных пуста." << std::endl;
        return;
    }
    std::cout << "База данных кандидатов:" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << (i + 1) << ". " << candidates[i] << std::endl;
    }
}
