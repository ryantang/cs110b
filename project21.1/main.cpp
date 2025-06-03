#include <iostream>
#include <cassert>
#include <sstream>
#include "MyString.h"

using namespace std;
using namespace cs_mystring;


void runMyStringTests();
void BasicTest();
void RelationTest();
void CopyTest();
MyString AppendTest(const MyString& ref, MyString val);
string boolString(bool convertMe);

int main() {
    runMyStringTests();
    // BasicTest();
    // RelationTest();
    // CopyTest();
}

void runMyStringTests()
{
    MyString s1("Hello");
    assert(s1.length() == 5);
    assert(s1[0] == 'H');
    assert(s1[4] == 'o');

    assert(s1 == "Hello");
    string stringObject;


    assert(s1 != "hello");
    
    s1[0] = 'Y';
    assert(s1 == "Yello");

    MyString s2("String with 1+ spaces");
    assert(s2.length() == 21 );

    MyString s3 = MyString();
    assert(s3.length() == 0);
    assert(s3 == MyString("")); 
    assert(s3 == ""); //Need to check both strings and c-string comparisons

    MyString s4 = "a";
    MyString s5 = "b";
    assert(s4 < s5); // alphabetical order
    assert(s4 <= s5);
    assert(s5 > s4);
    assert(s5 >= s4);

    MyString s6;
    s6 = MyString("Cheese");
    assert(s6.length() == 6);

    istringstream in;
    in.str("Some string coming from a stream");
    MyString s7, s8;
    in >> s7;
    in >> s8;
    assert(s7 == "Some");
    assert(s8 == "string");

    MyString s9;
    in.str("Another string");
    in.clear();
    s9.read(in);
    assert(s9 == "Another string");

    MyString s10;
    in.str("Another string");
    in.clear();
    s10.read(in, 'i');   
    assert(s10 == "Another str");

    MyString s11 = "Hello";
    MyString s12 = " World";
    MyString result;

    assert(s11 + s12 == "Hello World");
    assert(s11 + " Kitty" == "Hello Kitty");
    assert("Hello" + s12 == "Hello World");

    s11 += s12;
    assert(s11 == "Hello World");

}



void BasicTest()
{
    MyString s;
    cout << "----- Testing basic String creation & printing" << endl;
    
    const MyString strs[] = 
                {MyString("Wow"), MyString("C++ is neat!"),
                 MyString(""), MyString("a-z")};
                         
    for (int i = 0; i < 4; i++){
        cout << "string [" << i <<"] = " << strs[i] << endl;
    }

    cout << endl << "----- Testing access to characters (using const)" << endl;
    const MyString s1("abcdefghijklmnopqsrtuvwxyz");
    cout <<  "Whole string is " << s1 << endl;
    cout << "now char by char: ";
    for (int i = 0; i < s1.length(); i++){
        cout << s1[i];
    }

    cout << endl << "----- Testing access to characters (using non-const)" << endl;
    MyString s2("abcdefghijklmnopqsrtuvwxyz");
    cout <<  "Start with " << s2;
    for (int i = 0; i < s2.length(); i++){
        s2[i] = toupper(s2[i]);
    }
    cout << " and convert to " << s2 << endl;
}

string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    } else {
        return "false";
    }
}





void RelationTest()
{
    cout << "\n----- Testing relational operators between MyStrings\n";

    const MyString strs[] = 
        {MyString("app"), MyString("apple"), MyString(""), 
        MyString("Banana"), MyString("Banana")};

    for (int i = 0; i < 4; i++) {
        cout << "Comparing " << strs[i] << " to " << strs[i+1] << endl;
        cout << "    Is left < right? " << boolString(strs[i] < strs[i+1]) << endl;
        cout << "    Is left <= right? " << boolString(strs[i] <= strs[i+1]) << endl;
        cout << "    Is left > right? " << boolString(strs[i] > strs[i+1]) << endl;
        cout << "    Is left >= right? " << boolString(strs[i] >= strs[i+1]) << endl;
        cout << "    Does left == right? " << boolString(strs[i] == strs[i+1]) << endl;
        cout << "    Does left != right ? " << boolString(strs[i] != strs[i+1]) << endl;
    }
 
    cout << "\n----- Testing relations between MyStrings and char *\n";
    MyString s("he");
    const char *t = "hello";
    cout << "Comparing " << s << " to " << t << endl;
    cout << "    Is left < right? " << boolString(s < t) << endl;
    cout << "    Is left <= right? " << boolString(s <= t) << endl;
    cout << "    Is left > right? " << boolString(s > t) << endl;
    cout << "    Is left >= right? " << boolString(s >= t) << endl;
    cout << "    Does left == right? " << boolString(s == t) << endl;
    cout << "    Does left != right ? " << boolString(s != t) << endl;
    
    MyString u("wackity");
    const char *v = "why";
    cout << "Comparing " << v << " to " << u << endl;
    cout << "    Is left < right? " << boolString(v < u) << endl;
    cout << "    Is left <= right? " << boolString(v <= u) << endl;
    cout << "    Is left > right? " << boolString(v > u) << endl;
    cout << "    Is left >= right? " << boolString(v >= u) << endl;
    cout << "    Does left == right? " << boolString(v == u) << endl;
    cout << "    Does left != right ? " << boolString(v != u) << endl;  
}





MyString AppendTest(const MyString& ref, MyString val)
{
    val[0] = 'B';
    return val;
}





void CopyTest()
{
    cout << "\n----- Testing copy constructor and operator= on MyStrings\n";

    MyString orig("cake");
    
    MyString copy(orig);    // invoke copy constructor

    copy[0] = 'f';  // change first letter of the *copy*
    cout << "original is " << orig << ", copy is " << copy << endl;
    
    MyString copy2;      // makes an empty string
    
    copy2 = orig;        // invoke operator=
    copy2[0] = 'f';      // change first letter of the *copy*
    cout << "original is " << orig << ", copy is " << copy2 << endl;
    
    copy2 = "Copy Cat";
    copy2 = copy2;        // copy onto self and see what happens
    cout << "after self assignment, copy is " << copy2 << endl;
    
    cout << "Testing pass & return MyStrings by value and ref" << endl;
    MyString val = "winky";
    MyString sum = AppendTest("Boo", val);
    cout << "after calling Append, sum is " << sum << endl;
    cout << "val is " << val << endl;
    val = sum;
    cout << "after assign,  val is " << val << endl;
}