#include"Stack.h"

template<class T>
inline TStack<T>::TStack(int size, bool _f)
{
    if (size > 0)
    {
        this->length = size;
        this->f = _f;
        if (f)
        {
            data = new T[length];
            for (int i = 0; i < length; i++)
            {
                data[i] = 0;
            }
        }
        this->top = 0;
    }
    else
    {
        throw "Error";
    }
}

template <class T>
TStack<T>::TStack(TStack<T>& _v)
{
    length = _v.length;
    top = _v.top;
    f = _v.f;
    if (f)
    {
        data = new T[length];
        for (int i = 0; i < length; i++)
        {
            data[i] = _v.data[i];
        }
    }
    else
    {
        data = _v.data;
    }

}

template <class T>
TStack<T>::~TStack()
{
    length = 0;
    if (f)
    {
        if (data != NULL)
        {
            delete[] data;
            data = 0;
        }
    }
}

//���
template<typename T>
inline int TStack<T>::max_elem()
{
    T res = data[0];
    for (int i = 1; i < length; i++)
    {
        if (data[i] > res)
        {
            res = data[i];
        }
    }
    return res;
}

template<typename T>
inline int TStack<T>::min_elem()
{
    T res = data[0];
    for (int i = 1; i < length; i++)
    {
        if (data[i] < res)
        {
            res = data[i];
        }
    }
    return res;
}

template<typename T>
inline void TStack<T>::file()
{
    ofstream outf("Data.txt");
    if (!outf)
    {
        throw "Error file";
    }
    for (int i = 0; i < length; i++)
    {
        outf << data[i] << endl;
    }
}

template <class T>
TStack<T>& TStack<T>::operator =(TStack<T>& _v)
{
    if (this == &_v)
        return *this;

    this->length = _v.length;
    f = _v.f;

    if (f)
    {
        if (data != NULL)
        {
            delete[] data;
        }
        this->data = new T[length];

        for (int i = 0; i < length; i++)
        {
            data[i] = _v.data[i];
        }
    }
    else
    {
        data = _v.data;
    }

    this->top = _v.top;
    return *this;
}

template<class T>
inline void TStack<T>::Push(T d)
{
    if (top - 1 > length)
    {
        throw "Error";
    }

    data[top] = d;
    top++;
}

template<class T>
inline void TStack<T>::SetData(T* _x, int size, int _top)
{
    if (f)
    {
        if (data != NULL)
        {
            delete[] data;
        }
        this->length = size;
        f = false;
        data = _x;
        top = _top;
    }
}

template<class T>
inline void TStack<T>::Resize(int _size)
{
    if (_size <= 0)
    {
        throw "Error";
    }

    if (data == NULL)
    {
        delete[] data;
        data = new T[_size];
    }

    else
    {
        T* temp = new T[_size];

        for (int i = 0; i < this->GetCount(); i++)
        {
            temp[i] = Get();
        }

        delete[] data;

        data = new T[_size];

        for (int i = 0; i < 1; i++)
        {
            data[i] = temp[i];
        }
    }
}

template<class T>
inline T TStack<T>::Get()
{
    if (top <= 0)
    {
        throw "Error";
    }

    T d = data[top - 1];
    top--;
    return d;
}

template<class T>
inline int TStack<T>::IsEmpty(void) const
{
    return (top == 0);
}

template<class T>
inline int TStack<T>::IsFull(void) const
{
    return (top - 1 > length);
}

template <class T>
int TStack<T>::GetSize()
{
    return length;
}
template<class T>
inline int TStack<T>::GetCount()
{
    return top;
}