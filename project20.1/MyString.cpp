#include <iostream>
#include <cstring>
#include <cassert>
#include "MyString.h"
using namespace std;
using namespace cs_mystring;
namespace cs_mystring {

    MyString::MyString() {
        str = new char[1];
        str[0] = '\0';
    }






    MyString::MyString(const char* str) {
        assert(str != nullptr);
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }






    MyString::MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }






    MyString::~MyString() {
        delete[] str;
    }






    MyString& MyString::operator=(const MyString& other) {
        if (this != &other) {
            delete[] str; // Free the old memory
            str = new char[strlen(other.str) + 1]; // Allocate new memory
            strcpy(str, other.str); // Copy the string
        }
        return *this;
    }







    int MyString::length() const {
        return strlen(str);
    }






    char& MyString::operator[](int index) {
        assert(index >= 0 && index < length());
        return str[index];
    }






    const char& MyString::operator[](int index) const {
        assert(index >= 0 && index < length());
        return str[index];
    }






    bool operator==(const MyString& left, const MyString& right){
        return strcmp(left.str, right.str) == 0;
    }






    bool operator!=(const MyString& left, const MyString& right){
        return !(left == right);
    }






    bool operator<(const MyString& left, const MyString& right){
        return strcmp(left.str, right.str) < 0;
    }






    bool operator<=(const MyString& left, const MyString& right){
        return !(left > right);
    }






    bool operator>(const MyString& left, const MyString& right){
        return strcmp(left.str, right.str) > 0;
    }






    bool operator>=(const MyString& left, const MyString& right){
        return !(left < right);
    }






    std::ostream& operator<<(std::ostream& out, const MyString& str) {
        out << str.str;
        return out;
    }
    
}