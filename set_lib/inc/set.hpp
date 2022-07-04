#include <iostream>

class Set
{   
private:
    size_t size_;
    size_t count_;
    char *mas_;

private:
    int find(const char symbol) const;
    size_t findEmpty() const;
    void grow();

public:
    Set();
    Set(size_t size);
    Set(const Set &other);
    ~Set();

    void show() const;
    bool isMember(const char symbol) const;

    Set operator+(const char symbol);
    Set operator-(const char symbol);
    Set operator+(const Set other);
    Set operator-(const Set other);

    bool operator==(const Set other) const;
    bool operator!=(const Set other) const;
    bool operator<(const Set other) const;
    bool operator>(const Set other) const;

    void operator=(const Set &other);
};