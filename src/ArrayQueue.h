/* ArrayQueue.h
 * header file for ArrayQueue class
 */

#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include <vector>

class ArrayQueue 
{
    public:
        ArrayQueue();
        ArrayQueue(size_t);
        ~ArrayQueue();

        size_t size() const;
        //empty all entries
        void flush();
        void print();

        int front();
        bool enqueue(int); 
        bool dequeue(); 

    private:
        // the actual storage
        std::vector<int> m_vec;
        size_t m_size;
        size_t m_capacity;
        size_t m_head;
        size_t m_tail;
};

#endif // __ARRAYQUEUE_H__
