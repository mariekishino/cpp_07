template <typename T>
Array<T>::Array()
    : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
    : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const& other)
    : _array(NULL), _size(other._size)
{
    if (_size == 0)
        return;
    _array = new T[_size]();
    try
    {
        for (unsigned int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
    catch (...)
    {
        delete[] _array;
        throw;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& other)
{
    if (this == &other)
        return *this;

    T* newElements = NULL;
    if (other._size != 0)
    {
        newElements = new T[other._size]();
        try
        {
            for (unsigned int i = 0; i < other._size; ++i)
                newElements[i] = other._array[i];
        }
        catch (...)
        {
            delete[] newElements;
            throw;
        }
    }
    delete[] _array;
    _array = newElements;
    _size = other._size;
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Array index out of bounds");
    return _array[index];
}

template <typename T>
T const& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Array index out of bounds");
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
