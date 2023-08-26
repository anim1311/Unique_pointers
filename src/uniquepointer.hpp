#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP


#include <iostream>

#define DEBUG_LOG 1

#if DEBUG_LOG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

template <typename T>
class UniquePointer
{
public:
    UniquePointer(T* ptr); // default constructor
    ~UniquePointer(); // destructor
    UniquePointer(const UniquePointer&) = delete; // copy constructor
    UniquePointer& operator=(const UniquePointer&) = delete; // copy assignment operator
    UniquePointer(UniquePointer&&) = delete; // move constructor    

    T* operator->() const { return m_ptr; } // overload -> operator
    T& operator*() const { return *m_ptr; } // overload * operator
    T* get() const { return m_ptr; } // get the pointer
    void reset(T* ptr) { delete m_ptr; m_ptr = ptr; } // reset the pointer
    T* release() { T* ptr = m_ptr; m_ptr = nullptr; return ptr; } // release the pointer

    T(*get_deleter())(T*) { return [](T* ptr) { delete ptr; }; } // get the deleter (lambda function

    

private:
    T* m_ptr; // pointer to the object
};
template <typename T>
UniquePointer<T>::UniquePointer(T* ptr)
{
    LOG("UniquePointer constructor called of type " + std::string(typeid(T).name()));
    m_ptr = ptr;
}

template <typename T>
UniquePointer<T>::~UniquePointer()
{
    LOG("UniquePointer destructor called of type " + std::string(typeid(T).name()));
    delete m_ptr;
}




#endif // UNIQUEPOINTER_HPP