#include "unorderedSet.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create an array of integers and strings
    int intArray[] = { 1, 2, 3, 4, 5 };
    string strArray[] = { "apple", "banana", "orange", "apple" };

    // Create an unorderedSet object for integers
    unorderedSet<int> intSet;
    // Add integers from intArray to the set
    for (int i = 0; i < 5; ++i) {
        intSet.insertEnd(intArray[i]);
    }

    // Create an unorderedSet object for strings
    unorderedSet<string> strSet;
    // Add strings from strArray to the set
    for (int i = 0; i < 4; ++i) {
        strSet.insertEnd(strArray[i]);
    }

    // Verify that insertEnd does not allow duplicate entries
    cout << "Integer Set after insertEnd:" << endl;
    intSet.print();

    cout << "String Set after insertEnd:" << endl;
    strSet.print();

    // Verify that insertAt will allow a unique item but not a duplicate entry
    intSet.insertAt(3, 6); // Insert 6 at index 3
    strSet.insertAt(2, "pear"); // Insert "pear" at index 2

    cout << "Integer Set after insertAt:" << endl;
    intSet.print();

    cout << "String Set after insertAt:" << endl;
    strSet.print();

    // Verify that replaceAt will allow a unique item but not a duplicate entry
    intSet.replaceAt(2, 7); // Replace the item at index 2 with 7
    strSet.replaceAt(1, "grape"); // Replace the item at index 1 with "grape"

    cout << "Integer Set after replaceAt:" << endl;
    intSet.print();

    cout << "String Set after replaceAt:" << endl;
    strSet.print();

    // Test union and intersection operations for integer sets
    unorderedSet<int> intSet1, intSet2, intSet3;
    intSet1.insertEnd(1);
    intSet1.insertEnd(2);
    intSet2.insertEnd(2);
    intSet2.insertEnd(3);

    cout << "Union of Integer Sets:" << endl;
    intSet3 = intSet1 + intSet2;
    intSet3.print();

    cout << "Intersection of Integer Sets:" << endl;
    intSet3 = intSet1 - intSet2;
    intSet3.print();

    // Test union and intersection operations for string sets
    unorderedSet<string> strSet1, strSet2, strSet3;
    strSet1.insertEnd("apple");
    strSet1.insertEnd("banana");
    strSet2.insertEnd("banana");
    strSet2.insertEnd("orange");

    cout << "Union of String Sets:" << endl;
    strSet3 = strSet1 + strSet2;
    strSet3.print();

    cout << "Intersection of String Sets:" << endl;
    strSet3 = strSet1 - strSet2;
    strSet3.print();

    return 0;
}
