// Файл stack/MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.
#ifndef Stack_h           // защита от повторной компиляции
#define Stack_h           // модуль подключен

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode              // узел списка
{
private:
    INF d;                  // информационная часть узла
    ListNode *next;         // указатель на следующий узел списка
    ListNode(void) { next = nullptr; } //конструктор
    
    // Конструктор копирования
    ListNode(const ListNode& other) {
        d = other.d;
        next = nullptr; // Не копируем next, чтобы не копировать весь список
    }
    
    // Перегрузка оператора присваивания
    ListNode& operator=(const ListNode& other) {
        if (this != &other) {
            d = other.d;
            // next не копируем
        }
        return *this;
    }
    
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void);           // конструктор
    MyStack(const MyStack& other); // конструктор копирования
    MyStack& operator=(const MyStack& other); // перегрузка оператора =
    ~MyStack(void);          // освободить динамическую память
    bool empty(void);        // стек пустой?
    bool push(INF n);        // добавить узел в вершину стека
    bool pop(void);          // удалить узел из вершины стека
    INF top_inf(void);       // считать информацию из вершины стека
};

// Реализация методов класса MyStack

// Конструктор по умолчанию
template<class INF>
MyStack<INF>::MyStack(void) {
    top = nullptr;
}

// Конструктор копирования
template<class INF>
MyStack<INF>::MyStack(const MyStack& other) {
    if (other.top == nullptr) {
        top = nullptr;
        return;
    }
    
    // Создаем новый узел и копируем данные из вершины other
    top = new Node();
    top->d = other.top->d;
    
    // Указатели для построения нового стека
    Node* current = top;
    Node* otherCurrent = other.top->next;
    
    // Копируем остальные узлы
    while (otherCurrent != nullptr) {
        current->next = new Node();
        current->next->d = otherCurrent->d;
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

// Перегрузка оператора присваивания
template<class INF>
MyStack<INF>& MyStack<INF>::operator=(const MyStack& other) {
    if (this != &other) {
        // Удаляем старое содержимое
        while (!empty()) {
            pop();
        }
        
        if (other.top == nullptr) {
            top = nullptr;
            return *this;
        }
        
        // Создаем новый узел и копируем данные из вершины other
        top = new Node();
        top->d = other.top->d;
        
        // Указатели для построения нового стека
        Node* current = top;
        Node* otherCurrent = other.top->next;
        
        // Копируем остальные узлы
        while (otherCurrent != nullptr) {
            current->next = new Node();
            current->next->d = otherCurrent->d;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
    return *this;
}

// Деструктор
template<class INF>
MyStack<INF>::~MyStack(void) {
    while (!empty()) {
        pop();
    }
}

// Проверка, пуст ли стек
template<class INF>
bool MyStack<INF>::empty(void) {
    return top == nullptr;
}

// Добавление элемента в стек
template<class INF>
bool MyStack<INF>::push(INF n) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        return false; // Не удалось выделить память
    }
    
    newNode->d = n;
    newNode->next = top;
    top = newNode;
    
    return true;
}

// Удаление элемента из вершины стека
template<class INF>
bool MyStack<INF>::pop(void) {
    if (empty()) {
        return false; // Стек пуст
    }
    
    Node* temp = top;
    top = top->next;
    delete temp;
    
    return true;
}

// Чтение информации из вершины стека без удаления
template<class INF>
INF MyStack<INF>::top_inf(void) {
    if (empty()) {
        // Возвращаем дефолтное значение в случае пустого стека
        return INF();
    }
    
    return top->d;
}

// Функция для разложения числа на простые множители
template<class DATA>
void Multipliers(int n, MyStack<DATA> &stack) {
    if (n <= 1) {
        return; // Для чисел 0 и 1 нет простых множителей
    }
    
    // Проверяем делимость на 2
    while (n % 2 == 0) {
        stack.push(2);
        n /= 2;
    }
    
    // Проверяем делимость на нечетные числа начиная с 3
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            stack.push(i);
            n /= i;
        }
    }
    
    // Если n > 1, то n - простое число
    if (n > 1) {
        stack.push(n);
    }
}

#endif