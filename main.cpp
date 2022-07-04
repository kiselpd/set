#include<iostream>
#include"set.hpp"

int main()
{

    Set u;
    u = u + 'n';
    u.show();

    Set r;
    r = r + 'r';
    r = r+ 'y';
    r.show();

    r = r+u;
    r.show();

    u = r - u;
    u.show();

    r.show();

    Set b;

    b = b + 'y';
    b = b + 'n';
    b = b + 'r';

    b.show();

    if(r == b)
        std::cout << "equally!" << std::endl;

    b = b + 'z';
    r = r+'t';

    b.show();
    r.show();

    if(r != b)
        std::cout << "not equally!" << std::endl;
    else
         std::cout << "equally!" << std::endl;       

    return 0;
}