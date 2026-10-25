#include <iostream>
#include <string>
using namespace std;

int main() {

    string str = "Hello world,";
    cout << "Before: " << str << endl;

    
    str.append(" Have a good day!");

    cout << "After: " << str << endl;

    str.insert(20 , "BENBURAK");
    cout << "sonra:"<< str << endl;

    return 0;
}