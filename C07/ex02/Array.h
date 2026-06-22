#include <stdexcept>

template <typename T>
class Array
{
  private:
    T           *_arr;
    unsigned int _size;

  public:
    Array() : _arr(NULL), _size(0) {};

    Array(unsigned int n) : _arr(new T[n]()), _size(n) {};

    Array(const Array &other) : _arr(new T[other._size]), _size(other._size)
    {
        for (unsigned int i = 0; i < other._size; i++)
            this->_arr[i] = other._arr[i];
    };

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            T *tmp = new T[other._size];
            for (unsigned int i = 0; i < other._size; i++)
                tmp[i] = other._arr[i];
            delete[] _arr;
            _arr  = tmp;
            _size = other._size;
        }
        return *this;
    };

    ~Array()
    {
        delete[] _arr;
    };

    T &operator[](unsigned int n)
    {
        if (n >= this->size())
            throw std::out_of_range("Index is out of bounds");
        return _arr[n];
    }

    const T &operator[](unsigned int n) const
    {
        if (n >= this->size())
            throw std::out_of_range("Index is out of bounds");
        return _arr[n];
    }

    unsigned int size(void) const
    {
        return _size;
    }
};