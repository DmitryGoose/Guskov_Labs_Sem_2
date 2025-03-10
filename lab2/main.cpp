#include "Planet.h"
#include "Candidate.h"
#include <iostream>

// Определение функций для меню
int showMainMenu();
void handlePlanetDatabase();
void handleCandidateDatabase();

int main() {
    int choice;

    while (true) {
        choice = showMainMenu();

        switch (choice) {
            case 1:
                handlePlanetDatabase();
                break;
            case 2:
                handleCandidateDatabase();
                break;
            case 0:
                std::cout << "Программа завершена." << std::endl;
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}

int showMainMenu() {
    int choice;

    std::cout << "\n======= ГЛАВНОЕ МЕНЮ =======\n";
    std::cout << "1. Работа с базой данных планет\n";
    std::cout << "2. Работа с базой данных кандидатов\n";
    std::cout << "0. Выход\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    return choice;
}

void handlePlanetDatabase() {
    Planet* planets = nullptr;
    int count = 0;
    const char* filename = "sunsys.txt";

    // Чтение базы данных
    Planet::readDatabase(filename, planets, count);

    int choice;
    bool running = true;

    while (running) {
        std::cout << "\n===== БАЗА ДАННЫХ ПЛАНЕТ =====\n";
        std::cout << "1. Показать все планеты\n";
        std::cout << "2. Добавить планету\n";
        std::cout << "3. Удалить планету\n";
        std::cout << "4. Редактировать планету\n";
        std::cout << "5. Сортировать по диаметру\n";
        std::cout << "6. Сохранить в файл\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                Planet::printDatabase(planets, count);
                break;

            case 2: {
                char name[256];
                int diameter;
                bool life;
                int satellites;

                std::cout << "Введите название планеты: ";
                std::cin >> name;
                std::cout << "Введите диаметр (км): ";
                std::cin >> diameter;
                std::cout << "Есть ли жизнь (0/1): ";
                std::cin >> life;
                std::cout << "Количество спутников: ";
                std::cin >> satellites;

                Planet newPlanet(name, diameter, life, satellites);
                Planet::addPlanet(planets, count, newPlanet);
                std::cout << "Планета добавлена.\n";
                break;
            }

            case 3: {
                if (count == 0) {
                    std::cout << "База данных пуста.\n";
                    break;
                }

                int index;
                Planet::printDatabase(planets, count);
                std::cout << "Введите номер планеты для удаления (1-" << count << "): ";
                std::cin >> index;

                if (index < 1 || index > count) {
                    std::cout << "Неверный номер.\n";
                    break;
                }

                Planet::removePlanet(planets, count, index - 1);
                std::cout << "Планета удалена.\n";
                break;
            }

            case 4: {
                if (count == 0) {
                    std::cout << "База данных пуста.\n";
                    break;
                }

                int index;
                Planet::printDatabase(planets, count);
                std::cout << "Введите номер планеты для редактирования (1-" << count << "): ";
                std::cin >> index;

                if (index < 1 || index > count) {
                    std::cout << "Неверный номер.\n";
                    break;
                }

                char name[256];
                int diameter;
                bool life;
                int satellites;

                std::cout << "Введите новое название планеты: ";
                std::cin >> name;
                std::cout << "Введите новый диаметр (км): ";
                std::cin >> diameter;
                std::cout << "Есть ли жизнь (0/1): ";
                std::cin >> life;
                std::cout << "Количество спутников: ";
                std::cin >> satellites;

                Planet newPlanet(name, diameter, life, satellites);
                Planet::editPlanet(planets, count, index - 1, newPlanet);
                std::cout << "Планета отредактирована.\n";
                break;
            }

            case 5:
                Planet::sortDatabase(planets, count);
                std::cout << "База данных отсортирована по диаметру.\n";
                break;

            case 6:
                Planet::writeDatabase(filename, planets, count);
                std::cout << "База данных сохранена в файл.\n";
                break;

            case 0:
                running = false;
                break;

            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    // Освобождаем память перед выходом
    delete[] planets;
}

void handleCandidateDatabase() {
    Candidate* candidates = nullptr;
    int count = 0;
    const char* filename = "candidates.txt";

    // Чтение базы данных
    Candidate::readDatabase(filename, candidates, count);

    int choice;
    bool running = true;

    while (running) {
        std::cout << "\n===== БАЗА ДАННЫХ КАНДИДАТОВ =====\n";
        std::cout << "1. Показать всех кандидатов\n";
        std::cout << "2. Добавить кандидата\n";
        std::cout << "3. Удалить кандидата\n";
        std::cout << "4. Редактировать кандидата\n";
        std::cout << "5. Сортировать по голосам\n";
        std::cout << "6. Сохранить в файл\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                Candidate::printDatabase(candidates, count);
                break;

            case 2: {
                char name[256];
                int age;
                char party[256];
                int votes;

                std::cout << "Введите имя кандидата: ";
                std::cin >> name;
                std::cout << "Введите возраст: ";
                std::cin >> age;
                std::cout << "Введите партию: ";
                std::cin >> party;
                std::cout << "Введите количество голосов: ";
                std::cin >> votes;

                Candidate newCandidate(name, age, party, votes);
                Candidate::addCandidate(candidates, count, newCandidate);
                std::cout << "Кандидат добавлен.\n";
                break;
            }

            case 3: {
                if (count == 0) {
                    std::cout << "База данных пуста.\n";
                    break;
                }

                int index;
                Candidate::printDatabase(candidates, count);
                std::cout << "Введите номер кандидата для удаления (1-" << count << "): ";
                std::cin >> index;

                if (index < 1 || index > count) {
                    std::cout << "Неверный номер.\n";
                    break;
                }

                Candidate::removeCandidate(candidates, count, index - 1);
                std::cout << "Кандидат удален.\n";
                break;
            }

            case 4: {
                if (count == 0) {
                    std::cout << "База данных пуста.\n";
                    break;
                }

                int index;
                Candidate::printDatabase(candidates, count);
                std::cout << "Введите номер кандидата для редактирования (1-" << count << "): ";
                std::cin >> index;

                if (index < 1 || index > count) {
                    std::cout << "Неверный номер.\n";
                    break;
                }

                char name[256];
                int age;
                char party[256];
                int votes;

                std::cout << "Введите новое имя кандидата: ";
                std::cin >> name;
                std::cout << "Введите новый возраст: ";
                std::cin >> age;
                std::cout << "Введите новую партию: ";
                std::cin >> party;
                std::cout << "Введите новое количество голосов: ";
                std::cin >> votes;

                Candidate newCandidate(name, age, party, votes);
                Candidate::editCandidate(candidates, count, index - 1, newCandidate);
                std::cout << "Кандидат отредактирован.\n";
                break;
            }

            case 5:
                Candidate::sortDatabase(candidates, count);
                std::cout << "База данных отсортирована по голосам.\n";
                break;

            case 6:
                Candidate::writeDatabase(filename, candidates, count);
                std::cout << "База данных сохранена в файл.\n";
                break;

            case 0:
                running = false;
                break;

            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    // Освобождаем память перед выходом
    delete[] candidates;
}
