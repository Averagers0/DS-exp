#ifndef STACK_H
#define STACK_H

#include <stdexcept>

/**
 * @brief 一个简单的顺序栈（动态数组实现）
 */
template <typename T>
class Stack {
private:
    T* data;
    int topIndex;
    int capacity;

public:
    explicit Stack(int size) {
        data = new T[size];
        capacity = size;
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack overflow");
        }
        data[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return data[topIndex--];
    }

    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[topIndex];
    }
};

#endif // STACK_H
