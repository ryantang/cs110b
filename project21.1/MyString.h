/* MyString.h

This header file declares the MyString class. The MyString class has a default constructor, a constructor 
that takes a C-style string as a parameter, a copy constructor, and a destructor. It also has a length 
function that returns the length of the string, an overloaded subscript operator for accessing characters, and 
an overloaded assignment operator. The class overloads the equality, inequality, less than, less than or equal 
to, greater than, and greater than or equal to operators.

The class also overloads the insertion operator for outputting the string to an output stream. The class
includes the "big three" (constructor, destructor, and assignment operator) to manage dynamic memory properly.


void MyString::MyString()

Precondition: None.
Postcondition: Initializes the MyString object to an empty string (length 0), but actually contains the null character '\0'.


void MyString::MyString(const char* str)

Precondition: Requires a valid C-style string (char*).
Postcondition: Initializes the MyString object to the given C-style string.


void MyString::MyString(const MyString& other)

Precondition: Requires a valid MyString object.
Postcondition: Initializes the MyString object to a copy of the given MyString object.


void MyString::~MyString()

Precondition: Requires a valid MyString object.
Postcondition: Deallocates the memory used by the MyString object.


int MyString::length() const

Precondition: Requires a valid MyString object.
Postcondition: Returns the length of the MyString object (excluding the null terminator).


char& MyString::operator[](int index)

Precondition: Requires a valid MyString object and a valid index (0 <= index < length())
Postcondition: Returns a reference to the character at the given index in the MyString object. Throws an assertion error if the index is out of bounds.


const char& MyString::operator[](int index) const

Precondition: Requires a valid MyString object and a valid index (0 <= index < length())
Postcondition: Returns a const reference to the character at the given index in the MyString object. Throws an assertion error if the index is out of bounds.


const MyString& MyString::operator=(const MyString& other)
Precondition: Requires a valid MyString object.
Postcondition: Performs a deep copy of the given MyString object into the current object. Manages memory properly to avoid leaks.
    If the call is to assign the object to itself, this function does nothing.


MyString operator+(const MyString& left, const MyString& right)

Precondition: Requires two valid MyString objects. Or one MyString object and one C-style string.
Postcondition: Returns a new MyString object that is the concatenation of the two MyString objects.


MyString& MyString::operator+=(const MyString& other)

Precondition: Requires a valid MyString object and another MyString object to concatenate.
Postcondition: Concatenates the other MyString object to the current object. The current object is modified to hold the new string.

bool operator==(const MyString& left, const MyString& right)

Precondition: Requires two valid MyString objects. Or one MyString object and one C-style string.
Postcondition: Returns true if they are equal (same length and same characters), false otherwise.


bool operator!=(const MyString& left, const MyString& right)

Precondition: Requires two valid MyString objects. Or one MyString object and one C-style string.
Postcondition: Returns true if they are not equal (different length or different characters), false otherwise.


bool operator<(const MyString& left, const MyString& right)

Precondition: Requires two valid MyString objects. Or one MyString object and one C-style string.
Postcondition: Returns true if the left string is lexicographically less than the right string, false otherwise.


bool operator<=(const MyString& left, const MyString& right)

Precondition: Requires two valid MyString objects. Or one MyString object and one C-style string.
Postcondition: Returns true if the left string is lexicographically less than or equal to the right string, false otherwise.


bool operator>(const MyString& left, const MyString& right)

Precondition: Requires two valid MyString objects. Or one MyString object and one C-style string.
Postcondition: Returns true if the left string is lexicographically greater than the right string, false otherwise.


bool operator>=(const MyString& left, const MyString& right)

Precondition: Requires two valid MyString objects. Or one MyString object and one C-style string.
Postcondition: Returns true if the left string is lexicographically greater than or equal to the right string, false otherwise.


std::ostream& operator<<(std::ostream& out, const MyString& str)

Precondition: Requires a valid MyString object.
Postcondition: Outputs the MyString object to the given output stream.


std::istream& operator>>(std::istream& in, MyString& str)
Precondition: Requires an input stream and a valid MyString object. The string being read from the input stream must be less 
    than or equal to 127 characters (MAX_INPUT_LENGTH).
Postcondition: Reads a C-style string from the input stream and assigns it to the MyString object.


MyString& read(std::istream& in, char delimiter = '\n')

Precondition: Requires an input stream and a valid MyString object. The string being read from the input stream must be less 
    than or equal to 127 characters (MAX_INPUT_LENGTH). Also takes in an optional delimiter character.
Postcondition: Reads a C-style string from the input stream until the delimiter is found and assigns it to the MyString object.
    If a delimiter is not passed in, it reads until the end of the line.

*/


#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;
namespace cs_mystring {
    class MyString {
        public:
            static const int MAX_INPUT_LENGTH = 127;

            MyString();
            MyString(const char* str);
            MyString(const MyString& other);
            ~MyString();
            
            int length() const;
            char& operator[](int index);
            const char& operator[](int index) const;

            MyString& operator=(const MyString& other);
            
            friend MyString operator+(const MyString& left, const MyString& right);
            MyString& operator+=(const MyString& other);

            friend bool operator==(const MyString& left, const MyString& right);
            friend bool operator!=(const MyString& left, const MyString& right);
            friend bool operator<(const MyString& left, const MyString& right);
            friend bool operator<=(const MyString& left, const MyString& right);
            friend bool operator>(const MyString& left, const MyString& right);
            friend bool operator>=(const MyString& left, const MyString& right);

            friend std::ostream& operator<<(std::ostream& out, const MyString& str);
            friend std::istream& operator>>(std::istream& in, MyString& str);
            MyString& read(std::istream& in, char delimiter = '\n');
        private:
           char *str;
    }; 
}


#endif