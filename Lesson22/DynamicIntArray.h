#pragma once
#include <cstdlib>

template <typename T>
class DynamicIntArray
{
public:
    //default c-tor
    DynamicIntArray();

    //c-tor with size
    DynamicIntArray(std::size_t size);

    //copy c-tor
    DynamicIntArray(const DynamicIntArray<T>& other);

    //free allocated memory
    ~DynamicIntArray();

    DynamicIntArray<T>& operator=(const DynamicIntArray<T>& other);

    T& operator[](std::size_t index);

    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    //Clear internal memory, set size to 0
    void clear();

    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(T element);

    // Reserve memory
    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;
    void shrinkToFit();
    void pop_back();
    T back() const;
    bool operator==(const DynamicIntArray<T>& other) const;
private:
    std::size_t m_size;
    int m_position;
    T* m_elements;
};