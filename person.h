#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name = "huakai";
    string  address = "scut";
public:
    Person(const string& na, const string& add): name(na), address(add) { }
    Person() = default;
    string get_name() const { return name; }
    string get_address() const { return address; }
};
#endif 
