#ifndef Stack_h
#define Stack_h

template<class INF, class FRIEND>
class ListNode
{
private:
    INF d;
    ListNode *next;
    ListNode(void) { next = nullptr; }

    ListNode(const ListNode& other) {
        d = other.d;
        next = nullptr;
    }

    ListNode& operator=(const ListNode& other) {
        if (this != &other) {
            d = other.d;
        }
        return *this;
    }

    friend FRIEND;
};

template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void);
    MyStack(const MyStack& other);
    MyStack& operator=(const MyStack& other);
    ~MyStack(void);
    bool empty(void);
    bool push(INF n);
    bool pop(void);
    INF top_inf(void);
};

template<class INF>
MyStack<INF>::MyStack(void) {
    top = nullptr;
}

template<class INF>
MyStack<INF>::MyStack(const MyStack& other) {
    if (other.top == nullptr) {
        top = nullptr;
        return;
    }

    top = new Node();
    top->d = other.top->d;

    Node* current = top;
    Node* otherCurrent = other.top->next;

    while (otherCurrent != nullptr) {
        current->next = new Node();
        current->next->d = otherCurrent->d;
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

template<class INF>
MyStack<INF>& MyStack<INF>::operator=(const MyStack& other) {
    if (this != &other) {
        while (!empty()) {
            pop();
        }

        if (other.top == nullptr) {
            top = nullptr;
            return *this;
        }

        top = new Node();
        top->d = other.top->d;

        Node* current = top;
        Node* otherCurrent = other.top->next;

        while (otherCurrent != nullptr) {
            current->next = new Node();
            current->next->d = otherCurrent->d;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
    return *this;
}

template<class INF>
MyStack<INF>::~MyStack(void) {
    while (!empty()) {
        pop();
    }
}

template<class INF>
bool MyStack<INF>::empty(void) {
    return top == nullptr;
}

template<class INF>
bool MyStack<INF>::push(INF n) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        return false;
    }

    newNode->d = n;
    newNode->next = top;
    top = newNode;

    return true;
}

template<class INF>
bool MyStack<INF>::pop(void) {
    if (empty()) {
        return false;
    }

    Node* temp = top;
    top = top->next;
    delete temp;

    return true;
}

template<class INF>
INF MyStack<INF>::top_inf(void) {
    if (empty()) {
        return INF();
    }

    return top->d;
}

template<class DATA>
void Multipliers(int n, MyStack<DATA> &stack) {
    if (n <= 1) {
        return;
    }

    while (n % 2 == 0) {
        stack.push(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            stack.push(i);
            n /= i;
        }
    }

    if (n > 1) {
        stack.push(n);
    }
}

#endif
