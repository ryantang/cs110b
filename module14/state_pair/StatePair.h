#ifndef STATEPAIR_H
#define STATEPAIR_H
#include <iostream>
using namespace std;

template<typename T1, typename T2>

class StatePair {
    public:
        StatePair() : key(T1()), value(T2()) {};
        StatePair(T1 newKey, T2 newValue) : key(newKey), value(newValue) {};

        void SetKey(T1 newKey) { key = newKey; }
        void SetValue(T2 newValue) { value = newValue; }
        T1 const getKey() { return key; }
        T2 const getValue() { return value; }
        void const PrintInfo() { cout << key << ": " << value << endl; }

    private:
        T1 key;
        T2 value;

};


#endif
