// MemoryBlock.h
#pragma once
#include <iostream>
#include <algorithm>

class MemoryBlock
{
private:
    size_t _length; // The length of the resource.
    int *_data;     // The resource.
    int id;

public:
    // Simple constructor that initializes the resource.
    explicit MemoryBlock(size_t length)
        : _length(length), _data(new int[length])
    {
        id = rand() % 100;
        std::cout << "id=" << id << " "
                  << "In MemoryBlock(size_t). length = " << _length << "." << std::endl;
    }

    // Destructor.
    ~MemoryBlock()
    {
        std::cout << "id=" << id << " "
                  << "In ~MemoryBlock(). length = " << _length << ".";
        if (_data != nullptr)
        {
            std::cout << " Deleting resource.";
            // Delete the resource.
            delete[] _data;
        }

        std::cout << std::endl;
    }

    // 拷贝构造 Copy constructor.
    MemoryBlock(const MemoryBlock &other)
        : _length(other._length), _data(new int[other._length])
    {
        std::cout << "In MemoryBlock(const MemoryBlock&). length = " << other._length << ". Copying resource." << std::endl;
        std::copy(other._data, other._data + _length, _data);
    }

    // 拷贝赋值运算符 Copy assignment operator
    MemoryBlock &operator=(const MemoryBlock &other)
    {
        std::cout << "In operator=(const MemoryBlock&). length = " << other._length << ". Copying resource." << std::endl;
        if (this != &other)
        {
            // Free the existing resource.
            delete[] _data;
            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
        }
        return *this;
    }

    // Retrieves the length of the data resource.
    size_t Length() const
    {
        return _length;
    }

    // 移动构造-Move constructor.
    MemoryBlock(MemoryBlock &&other) noexcept
        : _data(nullptr), _length(0)
    {
        std::cout << "id=" << id << " "
                  << "In MemoryBlock(MemoryBlock&&). length = " << other._length << ". Moving resource."
                  << "other.id=" << other.id << std::endl;

        // Copy the data pointer and its length from the
        // source object.
        _data = other._data;
        _length = other._length;
        id = other.id + 100;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other._data = nullptr;
        other._length = 0;
    }

    // 移动赋值运算符-Move assignment operator.
    MemoryBlock &operator=(MemoryBlock &&other) noexcept
    {
        std::cout << "id=" << id << " "
                  << "In operator=(MemoryBlock&&). length = " << other._length << "." << std::endl;

        if (this != &other)
        {
            // Free the existing resource.
            delete[] _data;

            // Copy the data pointer and its length from the
            // source object.
            _data = other._data;
            _length = other._length;

            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times.
            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }
};