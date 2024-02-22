#pragma once
#include <cstdlib>

template <typename T>
class DynamicArray
{
public:
    //default c-tor
    DynamicArray();

    //c-tor with size
    DynamicArray(std::size_t size);

    //copy c-tor
    DynamicArray(const DynamicArray<T>& other);

    //free allocated memory
    ~DynamicArray();

    DynamicArray<T>& operator=(const DynamicArray<T>& other);

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
    bool operator==(const DynamicArray<T>& other) const;
private:
    std::size_t m_size; // real size of array
    std::size_t m_capacity; // storage space size, can be equal or greater than m_size
    T* m_elements;
};