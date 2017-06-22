/* ArrayQueue.cpp
 * cpp file for Class ArrayQueue
 */

#include <iostream>
#include <iomanip>
#include "ArrayQueue.h"

using namespace std;

ArrayQueue::ArrayQueue(): m_vec(vector<int>(4)), m_size(0), m_capacity(4), m_head(0), m_tail(0) {}
ArrayQueue::ArrayQueue(size_t s): m_vec(vector<int>(s)), m_size(0), m_capacity(s), m_head(0), m_tail(0) {}

ArrayQueue::~ArrayQueue() {
    flush();
}

size_t ArrayQueue::size() const {
    return m_size;
}

void ArrayQueue::flush() {
    m_size = 0;
    m_tail = m_head;
}

void ArrayQueue::print()
{
    for(auto& v : m_vec) {
        cout << std::setw(8) << std::left << v << " ";
    }
    cout <<"\nhead " << m_head << " tail: " << m_tail;
    cout <<"\n-----------------------------------------------" << std::endl;
}

int ArrayQueue::front() {
    if (m_size > 0) {
        return m_vec.at(m_head);
    } else {
        cout << "ERROR: queue is empty!" << endl;
        return -1;
    }
}

bool ArrayQueue::enqueue(int v) {
    if (m_size < m_capacity){
        if (m_tail == m_capacity - 1) {
            m_vec.at(m_tail) = v; 
            m_tail = 0;
        } else {
            m_vec.at(m_tail) = v; 
            ++m_tail;
        }
        ++m_size;
        return true;
    } else {
        return false;
    }
}

bool ArrayQueue::dequeue() {
    if (m_size > 0){
        if (m_head == m_capacity - 1) {
            m_head = 0;
        } else {
            ++m_head;
        }
        --m_size;
        return true;
    } else {
        return false;
    }
}
