#include "LinkedQueue.hpp"

template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), last(nullptr) {
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) : head(nullptr), last(nullptr) {
    this->length = 0;
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (this->length == 0) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return this->last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    Node* curr = this->head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    this->clear();
    Node* curr = copyObj.head;
    while (curr != nullptr) {
        this->enqueue(curr->value);
        curr = curr->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (this->isEmpty()) {
        throw string("dequeue: error, queue is empty, cannot dequeue");
    }
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->length--;
    if (this->isEmpty()) {
        this->last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem);
    newNode->next = nullptr;
    if (this->isEmpty()) {
        this->head = newNode;
        this->last = newNode;
    } else {
        this->last->next = newNode;
        this->last = newNode;
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (this->length == 0) {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return this->head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}