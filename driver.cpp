#include <iostream>
#include <stdexcept>
#include <cassert>
#include "LinkedQueue.hpp"

using namespace std;

template <typename T>
void printQueueByValue(LinkedQueue<T> q, const string& label) {
    // Pass-by-value triggers the copy constructor
    cout << label << " [len=" << q.getLength() << "]: ";
    while (!q.isEmpty()) {
        cout << q.front() << (q.getLength() > 1 ? " " : "");
        q.dequeue();
    }
    cout << endl;
}

template <typename T>
void basicChecks() {
    LinkedQueue<T> q;
    assert(q.isEmpty());
    assert(q.getLength() == 0);
}

void testIntQueue() {
    cout << "=== INT QUEUE TESTS ===" << endl;

    LinkedQueue<int> q;
    assert(q.isEmpty());
    assert(q.getLength() == 0);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    assert(!q.isEmpty());
    assert(q.getLength() == 3);
    assert(q.front() == 10);
    assert(q.back()  == 30);
    printQueueByValue(q, "q (copy view)");

    q.dequeue();
    assert(q.front() == 20);
    assert(q.getLength() == 2);

    q.dequeue();
    assert(q.front() == 30);
    assert(q.back()  == 30);
    assert(q.getLength() == 1);

    q.dequeue();
    assert(q.isEmpty());
    assert(q.getLength() == 0);


    try {
        q.front();
        assert(false && "front() on empty should throw");
    } catch (const string& e) {
        cout << "Caught expected (front on empty): " << e << endl;
    }
    try {
        q.back();
        assert(false && "back() on empty should throw");
    } catch (const string& e) {
        cout << "Caught expected (back on empty): " << e << endl;
    }
    try {
        q.dequeue();
        assert(false && "dequeue() on empty should throw");
    } catch (const string& e) {
        cout << "Caught expected (dequeue on empty): " << e << endl;
    }


    for (int i = 1; i <= 5; ++i) q.enqueue(i * 100);
    LinkedQueue<int> qCopy(q);
    printQueueByValue(qCopy, "qCopy (should be 100 200 300 400 500)");

    assert(q.getLength() == 5);
    assert(q.front() == 100);
    assert(q.back() == 500);

    LinkedQueue<int> qAssign;
    qAssign.enqueue(-1);
    qAssign = q;
    printQueueByValue(qAssign, "qAssign (should be 100 200 300 400 500)");
    assert(qAssign.getLength() == 5);
    assert(q.getLength() == 5);


    q = q;
    assert(q.getLength() == 5);
    assert(q.front() == 100);
    assert(q.back() == 500);


    q.clear();
    assert(q.isEmpty());
    assert(q.getLength() == 0);

    q.enqueue(42);
    assert(!q.isEmpty());
    assert(q.front() == 42);
    assert(q.back() == 42);
    q.clear();
    assert(q.isEmpty());
    cout << "INT tests passed" << endl << endl;
}

void testStringQueue() {
    cout << "=== STRING QUEUE TESTS ===" << endl;

    LinkedQueue<string> s;
    s.enqueue("alpha");
    s.enqueue("beta");
    s.enqueue("gamma");

    assert(s.front() == "alpha");
    assert(s.back()  == "gamma");
    assert(s.getLength() == 3);
    printQueueByValue(s, "s (copy view)");


    LinkedQueue<string> s2(s);
    assert(s2.getLength() == 3);
    printQueueByValue(s2, "s2 (should be alpha beta gamma)");

    LinkedQueue<string> s3;
    s3 = s;
    assert(s3.getLength() == 3);
    s3.dequeue();
    assert(s3.front() == "beta");
    assert(s.front() == "alpha");

    // Clear
    s.clear();
    assert(s.isEmpty());
    cout << "STRING tests passed" << endl << endl;
}

int main() {
    try {
        basicChecks<int>();
        basicChecks<string>();
        testIntQueue();
        testStringQueue();
        cout << "All tests completed successfully" << endl;
    } catch (const exception& e) {
        cout << "exception: " << e.what() << endl;
    } catch (const string& e) {
        cout << "string exception: " << e << endl;
    } catch (...) {
        cout << "Unknown exception" << endl;
    }
    return 0;
}