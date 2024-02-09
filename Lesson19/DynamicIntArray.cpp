#include "DynamicIntArray.h"
#include <iostream>
#include <cassert>

// Default c-tor
DynamicIntArray::DynamicIntArray() :m_size(0), m_position(0) {
    m_elements = new int[m_size];
    std::cout << "Defalult c-tor" << std::endl;
}

// C-tor with size
DynamicIntArray::DynamicIntArray(std::size_t size) : m_size(size), m_position(0) {
    m_elements = new int[m_size];
    std::cout << "C-tor with size" << std::endl;
}

// Copy c-tor
DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) {
    m_size = other.m_size;
    m_position = other.m_position;
    m_elements = new int[other.m_size];

    std::copy(other.m_elements, other.m_elements + other.m_size, m_elements);
    std::cout << "Copy c-tor" << std::endl;
}

// Free allocated memory
DynamicIntArray::~DynamicIntArray() {
    std::cout << "D-tor" << std::endl;
    delete[] m_elements;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    DynamicIntArray tmp(other);
    delete[] m_elements;
    return tmp;
}

int& DynamicIntArray::operator[](std::size_t index) {
    assert(index >= 0 && index < m_size);
 
    return m_elements[index];
}

// Delete previous memory, create new inner array with updated size
void DynamicIntArray::setSize(std::size_t newSize) {
    if (m_size < newSize) {
        int* tmp = new int[m_size];
        std::copy(m_elements, m_elements + m_size, tmp);
        m_position = 0;

        delete[] m_elements;
        m_elements = new int[newSize];
        for (int i = 0; i < m_size; i++) {
            m_elements[i] = tmp[i];
            m_position++;
        }
        delete[] tmp;
    }

    m_size = newSize;
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
        std::copy(m_elements, m_elements + m_size, tmp);
        //for (int i = 0; i < m_size; i++) {
        //    tmp[i] = m_elements[i];
        //}
        tmp[m_position] = element;
        m_size = m_position + 1;
        delete[] m_elements;
        m_elements = tmp;
        //m_elements = new int[m_size];
        //for (int i = 0; i < m_size; i++) {
        //    m_elements[i] = tmp[i];
        //}
        //delete[] tmp;
    }
    else {
        m_elements[m_position] = element;
    }
    m_position++;
}