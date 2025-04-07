#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <cstring>

// Общий шаблон класса MyVector
template <typename T>
class MyVector {
protected:
    int max_size;  // Размер вектора
    int size;      // Количество элементов в векторе
    T* pdata;      // Указатель на данные

public:
    // Конструктор с параметром (по умолчанию создает пустой вектор)
    explicit MyVector(int _max_size = 1);
    
    // Конструктор копирования
    MyVector(const MyVector<T>& other);
    
    // Деструктор
    virtual ~MyVector();
    
    // Добавление элемента в конец вектора
    virtual void add_element(const T& element);
    
    // Удаление элемента по индексу
    virtual void delete_element(int index);
    
    // Поиск элемента, возвращает индекс или -1
    int find(const T& element) const;
    
    // Изменение размера вектора
    void resize(int new_max_size);
    
    // Сортировка вектора (для использования в MySet)
    void sort();
    
    // Перегрузка оператора доступа по индексу
    T& operator[](int index);
    const T& operator[](int index) const;
    
    // Оператор присваивания
    MyVector<T>& operator=(const MyVector<T>& other);
    
    // Геттеры
    int get_size() const { return size; }
    int get_max_size() const { return max_size; }
};

// Реализация шаблонных методов для общего случая
template <typename T>
MyVector<T>::MyVector(int _max_size) : max_size(_max_size), size(0) {
    pdata = new T[max_size];
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other) : max_size(other.max_size), size(other.size) {
    pdata = new T[max_size];
    for (int i = 0; i < size; i++) {
        pdata[i] = other.pdata[i];
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}

template <typename T>
void MyVector<T>::add_element(const T& element) {
    if (size >= max_size) {
        resize(max_size * 2);
    }
    pdata[size++] = element;
}

template <typename T>
void MyVector<T>::delete_element(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    
    for (int i = index; i < size - 1; i++) {
        pdata[i] = pdata[i + 1];
    }
    size--;
    
    if (size < max_size / 4 && max_size > 1) {
        int new_max_size = max_size / 2;
        if (new_max_size < 1) new_max_size = 1;
        resize(new_max_size);
    }
}

template <typename T>
void MyVector<T>::resize(int new_max_size) {
    T* new_data = new T[new_max_size];
    int copy_size = (size < new_max_size) ? size : new_max_size;
    
    for (int i = 0; i < copy_size; i++) {
        new_data[i] = pdata[i];
    }
    
    delete[] pdata;
    pdata = new_data;
    max_size = new_max_size;
    
    if (size > max_size) {
        size = max_size;
    }
}

template <typename T>
int MyVector<T>::find(const T& element) const {
    for (int i = 0; i < size; i++) {
        if (pdata[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void MyVector<T>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (pdata[j] > pdata[j + 1]) {
                T temp = pdata[j];
                pdata[j] = pdata[j + 1];
                pdata[j + 1] = temp;
            }
        }
    }
}

template <typename T>
T& MyVector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return pdata[index];
}

template <typename T>
const T& MyVector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return pdata[index];
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
    if (this != &other) {
        delete[] pdata;
        
        max_size = other.max_size;
        size = other.size;
        pdata = new T[max_size];
        
        for (int i = 0; i < size; i++) {
            pdata[i] = other.pdata[i];
        }
    }
    return *this;
}

// Полная специализация класса MyVector для типа char*
template <>
class MyVector<char*> {
protected:
    int max_size;  // Размер вектора
    int size;      // Количество элементов в векторе
    char** pdata;  // Указатель на данные

public:
    // Конструктор с параметром
    explicit MyVector(int _max_size = 1) : max_size(_max_size), size(0) {
        pdata = new char*[max_size];
        for (int i = 0; i < max_size; i++) {
            pdata[i] = nullptr;
        }
    }
    
    // Конструктор копирования
    MyVector(const MyVector<char*>& other) : max_size(other.max_size), size(other.size) {
        pdata = new char*[max_size];
        for (int i = 0; i < size; i++) {
            if (other.pdata[i] != nullptr) {
                pdata[i] = new char[strlen(other.pdata[i]) + 1];
                strcpy(pdata[i], other.pdata[i]);
            } else {
                pdata[i] = nullptr;
            }
        }
    }
    
    // Деструктор
    virtual ~MyVector() {
        for (int i = 0; i < size; i++) {
            delete[] pdata[i];
        }
        delete[] pdata;
    }
    
    // Добавление элемента
    virtual void add_element(const char* element) {
        if (size >= max_size) {
            resize(max_size * 2);
        }
        if (element != nullptr) {
            pdata[size] = new char[strlen(element) + 1];
            strcpy(pdata[size], element);
        } else {
            pdata[size] = nullptr;
        }
        size++;
    }
    
    // Удаление элемента
    virtual void delete_element(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        
        delete[] pdata[index];
        
        for (int i = index; i < size - 1; i++) {
            pdata[i] = pdata[i + 1];
        }
        
        pdata[size - 1] = nullptr;
        size--;
        
        if (size < max_size / 4 && max_size > 1) {
            int new_max_size = max_size / 2;
            if (new_max_size < 1) new_max_size = 1;
            resize(new_max_size);
        }
    }
    
    // Поиск элемента
    int find(const char* element) const {
        for (int i = 0; i < size; i++) {
            if ((pdata[i] == nullptr && element == nullptr) ||
                (pdata[i] != nullptr && element != nullptr && strcmp(pdata[i], element) == 0)) {
                return i;
            }
        }
        return -1;
    }
    
    // Изменение размера
    void resize(int new_max_size) {
        char** new_data = new char*[new_max_size];
        int copy_size = (size < new_max_size) ? size : new_max_size;
        
        for (int i = 0; i < copy_size; i++) {
            if (pdata[i] != nullptr) {
                new_data[i] = new char[strlen(pdata[i]) + 1];
                strcpy(new_data[i], pdata[i]);
            } else {
                new_data[i] = nullptr;
            }
        }
        
        for (int i = copy_size; i < new_max_size; i++) {
            new_data[i] = nullptr;
        }
        
        for (int i = 0; i < size; i++) {
            delete[] pdata[i];
        }
        delete[] pdata;
        
        pdata = new_data;
        max_size = new_max_size;
        
        if (size > max_size) {
            size = max_size;
        }
    }
    
    // Сортировка
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (pdata[j] != nullptr && pdata[j+1] != nullptr && 
                    strcmp(pdata[j], pdata[j+1]) > 0) {
                    char* temp = pdata[j];
                    pdata[j] = pdata[j+1];
                    pdata[j+1] = temp;
                }
            }
        }
    }
    
    // Оператор доступа
    char*& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return pdata[index];
    }
    
    const char* operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return pdata[index];
    }
    
    // Оператор присваивания
    MyVector<char*>& operator=(const MyVector<char*>& other) {
        if (this != &other) {
            for (int i = 0; i < size; i++) {
                delete[] pdata[i];
            }
            delete[] pdata;
            
            max_size = other.max_size;
            size = other.size;
            pdata = new char*[max_size];
            
            for (int i = 0; i < size; i++) {
                if (other.pdata[i] != nullptr) {
                    pdata[i] = new char[strlen(other.pdata[i]) + 1];
                    strcpy(pdata[i], other.pdata[i]);
                } else {
                    pdata[i] = nullptr;
                }
            }
        }
        return *this;
    }
    
    // Геттеры
    int get_size() const { return size; }
    int get_max_size() const { return max_size; }
};

#endif // MYVECTOR_H