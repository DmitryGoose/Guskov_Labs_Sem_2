#ifndef MYSET_H
#define MYSET_H

#include "MyVector.h"

// Общий шаблон класса MySet
template <typename T>
class MySet : public MyVector<T> {
private:
    // Бинарный поиск (метод половинного деления)
    int q_find(const T& element) const;

public:
    // Используем конструкторы базового класса
    explicit MySet(int _max_size = 1) : MyVector<T>(_max_size) {}
    MySet(const MySet<T>& other) : MyVector<T>(other) {}
    
    // Проверка наличия элемента в множестве
    bool is_element(const T& element) const;
    
    // Переопределение методов добавления и удаления
    void add_element(const T& element) override;
    void delete_element(int index) override;
    
    // Операции над множествами
    MySet<T>& operator+=(const MySet<T>& other);  // Объединение
    MySet<T>& operator-=(const MySet<T>& other);  // Разность
    MySet<T>& operator*=(const MySet<T>& other);  // Пересечение
    
    // Дружественные функции для операций над множествами
    template <typename U>
    friend MySet<U> operator+(const MySet<U>& set1, const MySet<U>& set2);
    
    template <typename U>
    friend MySet<U> operator-(const MySet<U>& set1, const MySet<U>& set2);
    
    template <typename U>
    friend MySet<U> operator*(const MySet<U>& set1, const MySet<U>& set2);
    
    template <typename U>
    friend bool operator==(const MySet<U>& set1, const MySet<U>& set2);
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const MySet<U>& set);
};

// Реализация методов для общего случая
template <typename T>
int MySet<T>::q_find(const T& element) const {
    int left = 0;
    int right = this->size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (this->pdata[mid] == element) {
            return mid;
        }
        
        if (this->pdata[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Элемент не найден
}

template <typename T>
bool MySet<T>::is_element(const T& element) const {
    return q_find(element) != -1;
}

template <typename T>
void MySet<T>::add_element(const T& element) {
    if (!is_element(element)) {
        MyVector<T>::add_element(element);
        this->sort();
    }
}

template <typename T>
void MySet<T>::delete_element(int index) {
    MyVector<T>::delete_element(index);
}

template <typename T>
MySet<T>& MySet<T>::operator+=(const MySet<T>& other) {
    for (int i = 0; i < other.size; i++) {
        add_element(other.pdata[i]);
    }
    return *this;
}

template <typename T>
MySet<T>& MySet<T>::operator-=(const MySet<T>& other) {
    for (int i = 0; i < other.size; i++) {
        int index = q_find(other.pdata[i]);
        if (index != -1) {
            delete_element(index);
        }
    }
    return *this;
}

template <typename T>
MySet<T>& MySet<T>::operator*=(const MySet<T>& other) {
    MySet<T> result;
    for (int i = 0; i < this->size; i++) {
        if (other.is_element(this->pdata[i])) {
            result.add_element(this->pdata[i]);
        }
    }
    *this = result;
    return *this;
}

// Функции-операторы для общего случая
template <typename T>
MySet<T> operator+(const MySet<T>& set1, const MySet<T>& set2) {
    MySet<T> result(set1);
    result += set2;
    return result;
}

template <typename T>
MySet<T> operator-(const MySet<T>& set1, const MySet<T>& set2) {
    MySet<T> result(set1);
    result -= set2;
    return result;
}

template <typename T>
MySet<T> operator*(const MySet<T>& set1, const MySet<T>& set2) {
    MySet<T> result(set1);
    result *= set2;
    return result;
}

template <typename T>
bool operator==(const MySet<T>& set1, const MySet<T>& set2) {
    if (set1.size != set2.size) {
        return false;
    }
    
    for (int i = 0; i < set1.size; i++) {
        if (!set2.is_element(set1.pdata[i])) {
            return false;
        }
    }
    
    return true;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MySet<T>& set) {
    os << "{";
    for (int i = 0; i < set.size; i++) {
        os << set.pdata[i];
        if (i < set.size - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

// Специализация класса MySet для типа char*
template <>
class MySet<char*> : public MyVector<char*> {
private:
    // Бинарный поиск для строк
    int q_find(const char* element) const;

public:
    // Используем конструкторы базового класса
    explicit MySet(int _max_size = 1) : MyVector<char*>(_max_size) {}
    MySet(const MySet<char*>& other) : MyVector<char*>(other) {}
    
    // Проверка наличия элемента в множестве
    bool is_element(const char* element) const;
    
    // Переопределение методов добавления и удаления
    void add_element(const char* element) override;
    void delete_element(int index) override;
    
    // Операции над множествами
    MySet<char*>& operator+=(const MySet<char*>& other);  // Объединение
    MySet<char*>& operator-=(const MySet<char*>& other);  // Разность
    MySet<char*>& operator*=(const MySet<char*>& other);  // Пересечение
    
    // Дружественные функции-операторы
    friend MySet<char*> operator+(const MySet<char*>& set1, const MySet<char*>& set2);
    friend MySet<char*> operator-(const MySet<char*>& set1, const MySet<char*>& set2);
    friend MySet<char*> operator*(const MySet<char*>& set1, const MySet<char*>& set2);
    friend bool operator==(const MySet<char*>& set1, const MySet<char*>& set2);
    friend std::ostream& operator<<(std::ostream& os, const MySet<char*>& set);
};

// Реализация методов для специализации char*
int MySet<char*>::q_find(const char* element) const {
    int left = 0;
    int right = this->size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (this->pdata[mid] == nullptr && element == nullptr) {
            return mid;
        }
        
        if (this->pdata[mid] != nullptr && element != nullptr && 
            strcmp(this->pdata[mid], element) == 0) {
            return mid;
        }
        
        if (this->pdata[mid] == nullptr || 
            (element != nullptr && strcmp(this->pdata[mid], element) < 0)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

bool MySet<char*>::is_element(const char* element) const {
    return q_find(element) != -1;
}

void MySet<char*>::add_element(const char* element) {
    if (!is_element(element)) {
        MyVector<char*>::add_element(element);
        this->sort();
    }
}

void MySet<char*>::delete_element(int index) {
    MyVector<char*>::delete_element(index);
}

MySet<char*>& MySet<char*>::operator+=(const MySet<char*>& other) {
    for (int i = 0; i < other.size; i++) {
        add_element(other.pdata[i]);
    }
    return *this;
}

MySet<char*>& MySet<char*>::operator-=(const MySet<char*>& other) {
    for (int i = 0; i < other.size; i++) {
        int index = q_find(other.pdata[i]);
        if (index != -1) {
            delete_element(index);
        }
    }
    return *this;
}

MySet<char*>& MySet<char*>::operator*=(const MySet<char*>& other) {
    MySet<char*> result;
    for (int i = 0; i < this->size; i++) {
        if (other.is_element(this->pdata[i])) {
            result.add_element(this->pdata[i]);
        }
    }
    *this = result;
    return *this;
}

// Функции-операторы для специализации char*
MySet<char*> operator+(const MySet<char*>& set1, const MySet<char*>& set2) {
    MySet<char*> result(set1);
    result += set2;
    return result;
}

MySet<char*> operator-(const MySet<char*>& set1, const MySet<char*>& set2) {
    MySet<char*> result(set1);
    result -= set2;
    return result;
}

MySet<char*> operator*(const MySet<char*>& set1, const MySet<char*>& set2) {
    MySet<char*> result(set1);
    result *= set2;
    return result;
}

bool operator==(const MySet<char*>& set1, const MySet<char*>& set2) {
    if (set1.size != set2.size) {
        return false;
    }
    
    for (int i = 0; i < set1.size; i++) {
        if (!set2.is_element(set1.pdata[i])) {
            return false;
        }
    }
    
    return true;
}

std::ostream& operator<<(std::ostream& os, const MySet<char*>& set) {
    os << "{";
    for (int i = 0; i < set.size; i++) {
        os << (set.pdata[i] ? set.pdata[i] : "null");
        if (i < set.size - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

#endif // MYSET_H