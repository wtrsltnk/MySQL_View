#ifndef DELEGATE_H
#define DELEGATE_H

#include <vector>
#include <functional>

template<class T>
class Delegate
{
    std::vector<std::function<void(T)>> _handlers;
public:

    Delegate& operator += (std::function<void(T)> t)
    {
        this->_handlers.push_back(t);
        return *this;
    }

    void operator () (T args)
    {
        for (auto i : _handlers) i(args);
    }

    void clear() { this->_handlers.clear(); }
};

#endif // DELEGATE_H
