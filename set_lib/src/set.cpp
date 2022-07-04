#include<iostream>
#include"set.hpp"

Set::Set() : size_(2), count_(0)
{
    try
    {
        this->mas_ = new char[this->size_];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    this->mas_[0] = '\0';
    this->mas_[1] = '\0';
}

Set::Set(size_t size) : size_(size), count_(0)
{
    try
    {
        this->mas_ = new char[this->size_];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (size_t i = 0; i < this->size_; i++)
        this->mas_[i] = '\0';
}

Set::~Set()
{
    delete []mas_;
}

int Set::find(const char symbol) const
{
    for(size_t i = 0; i < this->size_; i++)
    {
        if(mas_[i] == symbol)
            return i;
    }

    return -1;
}

void Set::grow()
{
    this->size_ *= 2;

    char *new_mas = nullptr;

    try
    {
        new_mas = new char[this->size_];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (size_t i = 0; i < this->size_; i++)
    {
        if(i < this->size_ / 2)
            new_mas[i] = this->mas_[i];
        else
            new_mas[i] = '\0';
    }

    delete[] this->mas_;

    this->mas_ = new_mas;
}

void Set::show() const
{   
    if(!this->count_)
    {
      std::cout<<"Set is empty!"<<std::endl;
      return;
    }

    for (size_t i = 0; i < this->size_; i++)
    {
        if(this->mas_[i] != '\0')
            std::cout << this->mas_[i] << " ";
    }

    std::cout << " ... size_ = " << this->size_ << " count_ = " << this -> count_;
    std::cout << std::endl;
}

size_t Set::findEmpty() const
{
    for (size_t i = 0; i < this->count_; i++)
    {
        if(this->mas_[i] == '\0')
            return i;
    }

    return count_;
}

bool Set::isMember(const char symbol) const
{
    if(this->find(symbol) != -1)
        return true;
    else
        return false;
}

Set::Set(const Set &other)
{
    this->size_ = other.size_;
    this->count_ = other.count_;

    try
    {
        this->mas_ = new char[this->size_];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (size_t i = 0; i < this->size_; i++)
        this->mas_[i] = other.mas_[i];
}

void Set::operator=(const Set &other)
{
    char *new_mas = nullptr;

    try
    {
        new_mas = new char[other.size_];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (size_t i = 0; i < other.size_; i++)
        new_mas[i] = other.mas_[i];

    if(this->mas_ != nullptr)
        delete [](this->mas_);

    this->mas_ = new_mas;
    this->size_ = other.size_;
    this->count_ = other.count_;
}

Set Set::operator+(const char symbol)
{   
    Set new_set = *this;

    if (new_set.isMember(symbol))
        return new_set;

    if(new_set.size_ == new_set.count_)
        new_set.grow();

    size_t empty_position = new_set.findEmpty();

    new_set.mas_[empty_position] = symbol;
    new_set.count_++;

    return new_set;
}

Set Set::operator-(const char symbol)
{
    Set new_set = *this;

    int position = new_set.find(symbol);

    if (position == -1)
        return new_set;

    new_set.mas_[position] = '\0';
    new_set.count_--;

    return new_set;
}

bool Set::operator<(const Set other) const
{
    if(this->count_ < other.count_)
        return true;
    else
        return false;
}

bool Set::operator>(const Set other) const
{
    if(this->count_ > other.count_)
        return true;
    else
        return false;
}


Set Set::operator+(const Set other)
{
    Set new_set;

    new_set = *this;

    for (size_t i = 0; i < other.size_; i++)
        new_set = new_set + other.mas_[i];

    return new_set;
}

Set Set::operator-(const Set other)
{
    Set new_set;

    new_set = *this;

    for (size_t i = 0; i < other.size_; i++)
        if(other.mas_[i] != '\0')
            new_set = new_set - other.mas_[i];

    return new_set;
}

bool Set::operator==(const Set other) const
{
    if(this->count_ != other.count_)
        return false;

    for (size_t i = 0; i < this->count_; i++)
    {
        if (!this->isMember(other.mas_[i]))
            return false;
    }

    return true;
}

bool Set::operator!=(const Set other) const
{
    return !(*this == other);
}
