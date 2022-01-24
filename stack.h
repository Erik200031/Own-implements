#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
public:
    Stack();
    ~Stack();
    void push(T element);
    T pop();
    T top();
    bool is_empty();
    Stack& operator=(const Stack& rhs);
private:
    T* arr;
    int size;
    const int capacity; 
};

template <class T>
Stack<T>::Stack() : size (0), capacity (1000) {
    arr = new T[capacity];
}

template <class T>
Stack<T>::~Stack() {
    delete[] arr;
    arr = nullptr;
}

template <class T>
T Stack<T>::pop() {
    --size;
    return arr[size+1];
}

template <class T>
T Stack<T>::top() {
    return arr[size-1];
}

template <class T>
void Stack<T>::push(T element) {
    arr[size] = element;
    ++size;
}

template <class T>
bool Stack<T>::is_empty() {
    if (size == 0) {
        return true;
    }
    return false;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) {
    if(this == &rhs) {
        return *this;
    }
    this->size = rhs.size;
    delete[] this->arr;
    this->arr = new T[capacity];
    for (int i {}; i < rhs.size; ++i ) {
        this->arr[i] = rhs.arr[i];
    }
    return *this;
}

#endif //STACK_H