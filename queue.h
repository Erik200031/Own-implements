#ifndef QUEUE_H
#define QUEUE_H
#include <list>

template <class T>
class Queue {
    public:
    void push_back(T);
    void pop_front();
    T front();
    T back();
    int size();
    bool is_empty();
    Queue& operator=(const Queue& rhs) {
        this->m_lst = rhs.m_lst;
        return *this;
    }
    private:
    std::list<T> m_lst;
};

template <class T>
void Queue<T>::push_back(T element) {
    m_lst.push_back(element);
}

template <class T>
void Queue<T>::pop_front() {
    m_lst.pop_front();
}

template <class T>
T Queue<T>::front() {
    return m_lst.front();
}

template <class T>
T Queue<T>::back() {
    return m_lst.back();
}

template <class T>
int Queue<T>::size() {
    return m_lst.size();
}

template <class T>
bool Queue<T>::is_empty() {
    return m_lst.empty();
}
#endif //QUEUE_H