#include "LinkedQueue.hpp"
template <typename T>
LinkedQueue<T>::LinkedQueue() {
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    this->head = nullptr;
    this->last = nullptr;
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
        throw string("error: empty list");
    } else {
        Node* ptr = this->head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        return ptr->value;
    }
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
        throw string("error: empty list");
    } else {
        cout << "Removing " << this->head->value << endl;
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->length--;
        if (this->isEmpty()) {
            this->last = nullptr;
        }
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
    if (this->head == nullptr) {
        throw string("error: empty queue");
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
