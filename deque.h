#ifndef DEQUE_H
#define DEQUE_H
#include <vector>
#include <algorithm>
template <class T>
class Deque {
    public:
    T& operator[] (int index);
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    bool is_empty();
    int size();

    private:
    std::vector<T> vec1;
    std::vector<T> vec2;
};

template <class T>
T& Deque<T>::operator[] (int index) {
    if (index >= vec1.size() + vec2.size()) {
        std::cout << "Error out of range!\n";
        exit(0);
    }
    else if(index >= vec1.size()) {
        return vec2[index - vec1.size()];
    }
    return vec1[vec1.size()-index - 1];
}

template <class T>
void Deque<T>::push_back(T element) {
    vec2.push_back(element);
}

template <class T>
void Deque<T>::push_front(T element) {
    std::reverse(vec1.begin(),vec1.end());
    vec1.push_back(element);
    std::reverse(vec1.begin(),vec1.end());
}

template <class T>
bool Deque<T>::is_empty() {
    if(vec1.size() == 0 && vec2.size() == 0)
    {
        return true;
    }
    return false;
}

template <class T>
int Deque<T>::size() {
    return vec1.size() + vec2.size();
}

template <class T>
void Deque<T>::pop_back() {
    vec2.pop_back();
}

template <class T>
void Deque<T>::pop_front() {
    vec1.pop_back();
}



#endif //DEQUE_H