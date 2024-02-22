#include "DynamicIntArray.h"
#include <iostream>
#include <assert.h>

// Default c-tor
template <typename T>
DynamicArray<T>::DynamicArray() : m_size(0), m_capacity(10) {
    m_elements = new T[m_capacity];
    std::cout << "Defalult c-tor" << std::endl;
}

// C-tor with size
template <typename T>
DynamicArray<T>::DynamicArray(std::size_t size) : m_capacity(size * 2), m_size(0) {
    m_elements = new T[m_capacity];
    std::cout << "C-tor with size" << std::endl;
}

// Copy c-tor
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
    m_size = other.m_size;
    //m_position = other.m_position;
    m_capacity = other.m_capacity;
    m_elements = new T[other.m_capacity];

    std::copy(other.m_elements, other.m_elements + other.m_capacity, m_elements);
    std::cout << "Copy c-tor" << std::endl;
}

// Free allocated memory
template <typename T>
DynamicArray<T>::~DynamicArray() {
    std::cout << "D-tor" << std::endl;
    delete[] m_elements;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
    DynamicArray tmp(other);
    delete[] m_elements;
    return tmp;
}

template <typename T>
T& DynamicArray<T>::operator[](std::size_t index) {
    if (index >= m_size) {
        index = m_size - 1;
    }
    return m_elements[index];
}

// Delete previous memory, create new inner array with updated size
template <typename T>
void DynamicArray<T>::setSize(std::size_t newSize) {
    assert(("DynamicArray::setSize >> Data could be lost", newSize >= m_size));
    assert(("DynamicArray::setSize >> Capacity enogh", newSize > m_capacity));

    T* tmp = new T[m_size];
    std::copy(m_elements, m_elements + m_size, tmp);

    delete[] m_elements;
    m_capacity = newSize * 2;
    m_elements = new T[m_capacity];
    std::copy(tmp, tmp + m_size, m_elements);
    delete[] tmp;
}

template <typename T>
std::size_t DynamicArray<T>::getSize() const {
    return m_size;
}

// Clear internal memory, set size to 0
template <typename T>
void DynamicArray<T>::clear() {
    m_size = 0;
    m_capacity = 0;
    delete[] m_elements;
}

// Allocate new memory for new element
// Copy old content to new inner array
// insert element at the last index
// update size
template <typename T>
void DynamicArray<T>::push_back(T element) {
    if (m_size < m_capacity) {
        m_elements[m_size] = element;
        m_size++;
    }
    else {
        m_capacity *= 2;
        T* tmp = new T[m_capacity];
        tmp[m_size] = element;
        m_size++;
        std::copy(m_elements, m_elements + m_size, tmp);
        delete[] m_elements;
        m_elements = tmp;
    }
}

// Reserve memory
template <typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace) {
    assert(("DynamicArray::reserve >> Memory already reserved!", reservedSpace > m_capacity));

    m_capacity = reservedSpace;
    T* tmp = new T[m_capacity];
    std::copy(m_elements, m_elements + m_size, tmp);
    delete[] m_elements;
    m_elements = tmp;
}

template <typename T>
std::size_t DynamicArray<T>::getCapacity() const {
    return m_capacity;
}

template <typename T>
void DynamicArray<T>::shrinkToFit() {
    T* tmp = new T[m_size];
    std::copy(m_elements, m_elements + m_size, tmp);
    delete[] m_elements;
    m_elements = tmp;
    m_capacity = m_size;
}

template <typename T>
void DynamicArray<T>::pop_back() { // remove last element
    assert(("Out of range!", (m_size - 1) > 0));
    m_elements[m_size - 1] = 0;
    m_size--;
}

template <typename T>
T DynamicArray<T>::back() const {
    assert(("DynamicArray::back >> Out of range!", (m_size - 1) > 0 ));
    return m_elements[m_size - 1];
}

template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T>& other) const {
    if (m_size != other.m_size && m_capacity != other.m_capacity) {
        return false;
    }
    for (int i = 0; i < m_size; i++) {
        if (m_elements[i] != other.m_elements[i]) {
            return false;
        }
    }
    return true;
}

template DynamicArray<int>;
template DynamicArray<float>;