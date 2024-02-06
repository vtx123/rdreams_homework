#include "DynamicIntArray.h"
#include <iostream>

// Default c-tor
template <typename T>
DynamicIntArray<T>::DynamicIntArray() :m_size(0), m_position(0) {
    m_elements = new T[m_size];
    std::cout << "Defalult c-tor" << std::endl;
}

// C-tor with size
template <typename T>
DynamicIntArray<T>::DynamicIntArray(std::size_t size) : m_size(size), m_position(0) {
    m_elements = new T[m_size];
    std::cout << "C-tor with size" << std::endl;
}

// Copy c-tor
template <typename T>
DynamicIntArray<T>::DynamicIntArray(const DynamicIntArray<T>& other) {
    m_size = other.m_size;
    m_position = other.m_position;
    m_elements = new T[other.m_size];

    std::copy(other.m_elements, other.m_elements + other.m_size, m_elements);
    std::cout << "Copy c-tor" << std::endl;
}

// Free allocated memory
template <typename T>
DynamicIntArray<T>::~DynamicIntArray() {
    std::cout << "D-tor" << std::endl;
    delete[] m_elements;
}

template <typename T>
DynamicIntArray<T>& DynamicIntArray<T>::operator=(const DynamicIntArray<T>& other) {
    DynamicIntArray tmp(other);
    delete[] m_elements;
    return tmp;
}

template <typename T>
T& DynamicIntArray<T>::operator[](std::size_t index) {
    if (index >= m_size) {
        index = m_size - 1;
    }
    return m_elements[index];
}

// Delete previous memory, create new inner array with updated size
template <typename T>
void DynamicIntArray<T>::setSize(std::size_t newSize) {
    if (m_size < newSize) {
        int* tmp = new T[m_size];
        std::copy(m_elements, m_elements + m_size, tmp);
        m_position = 0;

        delete[] m_elements;
        m_elements = new T[newSize];
        for (int i = 0; i < m_size; i++) {
            m_elements[i] = tmp[i];
            m_position++;
        }
        delete[] tmp;
    }

    m_size = newSize;
}

template <typename T>
std::size_t DynamicIntArray<T>::getSize() const {
    return m_size;
}

// Clear internal memory, set size to 0
template <typename T>
void DynamicIntArray<T>::clear() {
    m_size = 0;
    delete[] m_elements;
}

// Allocate new memory for new element
// Copy old content to new inner array
// insert element at the last index
// update size
template <typename T>
void DynamicIntArray<T>::push_back(T element) {
    if (m_position + 1 >= m_size) {
        int* tmp = new T[m_position + 1];
        for (int i = 0; i < m_size; i++) {
            tmp[i] = m_elements[i];
        }
        tmp[m_position] = element;
        m_size = m_position + 1;
        delete[] m_elements;
        m_elements = new T[m_size];
        for (int i = 0; i < m_size; i++) {
            m_elements[i] = tmp[i];
        }
        delete[] tmp;
    }
    else {
        m_elements[m_position] = element;
    }
    m_position++;
}

// Reserve memory
template <typename T>
void DynamicIntArray<T>::reserve(std::size_t reservedSpace) {}

template <typename T>
std::size_t DynamicIntArray<T>::getCapacity() const {
    return 1;
}

template <typename T>
void DynamicIntArray<T>::shrinkToFit() {}

template <typename T>
void DynamicIntArray<T>::pop_back() {}

template <typename T>
T DynamicIntArray<T>::back() const {
    return 1;
}

template <typename T>
bool DynamicIntArray<T>::operator==(const DynamicIntArray<T>& other) const {
    return true;
}

template DynamicIntArray<int>;