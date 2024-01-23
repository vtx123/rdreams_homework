#include "DynamicIntArray.h"
#include <iostream>

// Default c-tor
DynamicIntArray::DynamicIntArray() :m_size(5), m_position(0) {
    m_elements = new int[m_size];
}

// C-tor with size
DynamicIntArray::DynamicIntArray(std::size_t size) : m_size(size), m_position(0) {
    m_elements = new int[m_size];
}

// Copy c-tor
DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) {
    if (m_size < other.getSize()) {
        delete[] m_elements;
        m_size = other.m_size;
    }

    m_elements = new int[m_size];
    for (int i = 0; i < m_size; i++) {
        m_elements[i] = other.m_elements[i];
    }
    m_position = other.m_position;
}

// Free allocated memory
DynamicIntArray::~DynamicIntArray() {
    delete[] m_elements;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    return *this;
}

int& DynamicIntArray::operator[](std::size_t index) {
    return m_elements[index];
}

// Delete previous memory, create new inner array with updated size
void DynamicIntArray::setSize(std::size_t newSize) {
    if (m_size < newSize) {
        delete[] m_elements;
        m_size = newSize;
        m_elements = new int[m_size];
        m_position = 0;
    }
    else {
        m_size = newSize;
    }
}

std::size_t DynamicIntArray::getSize() const {
    return m_size;
}

// Clear internal memory, set size to 0
void DynamicIntArray::clear() {
    m_size = 0;
    delete[] m_elements;
}

// Allocate new memory for new element
// Copy old content to new inner array
// insert element at the last index
// update size
void DynamicIntArray::push_back(int element) {
    if (m_position + 1 >= m_size) {
        int* tmp = new int[m_position + 1];
        for (int i = 0; i < m_size; i++) {
            tmp[i] = m_elements[i];
        }
        tmp[m_position] = element;
        m_size = m_position + 1;
        delete[] m_elements;
        m_elements = new int[m_size];
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