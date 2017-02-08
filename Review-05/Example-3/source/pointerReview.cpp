#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

/**
 * Array of table widths
 */
const int COL_WIDTHS[] = {12, 18, 10, 10};

/**
 * Main Function - Basics of Pointers & References
 */
int main(int argc, char** argv)
{
    int* powersOfTwo = new int();

    powersOfTwo[0] = 1;
    //*powersOfTwo   = 1;

    // Working with a pointer to a singleton
    cout << "powersOfTwo    = " << powersOfTwo    << "\n"
         << "&powersOfTwo   = " << &powersOfTwo   << "\n"
         << "\n";

    // Dereferencing a pointer & using offsets
    cout << "*powersOfTwo   = " << *powersOfTwo   << "\n";
    cout << "powersOfTwo[0] = " << powersOfTwo[0] << "\n";

    /*
    cout << "\n";
    cout << "Using a range based for loop" << "\n";

    for(const int& i : powersOfTwo) {
        cout << i << "\n";
    }
    */

    cout << "\n";
    cout << "Using a traditional for loop" << "\n";

    for(int i = 0; i < 1; i++) {
        cout << powersOfTwo[i] << "\n";
    }

    delete powersOfTwo;

    cout << std::string(48, '-') << "\n";

    // Working with a pointer to an array
    const int numPowers = 32;

    powersOfTwo = new int[numPowers];

    for (int i = 0; i < numPowers; i++) {
        powersOfTwo[i] = (1 << i);
    }

    for (int* it = powersOfTwo; it < powersOfTwo + numPowers; it++) {
        cout << it << " -> " << *it << "\n";
    }

    cout << "\n";
    cout << std::string(48, '-') << "\n";
    cout << "\n";

    for (int i = 0; i < numPowers; i++) {
        cout << right << setw(2)  << i << ": " 
             << right << setw(11) << powersOfTwo[i] 
             << right << setw(33) << std::bitset<32>(powersOfTwo[i])
             << "\n"; 
    }

    cout << "\n";
    cout << std::string(48, '-') << "\n";
    cout << "\n";

    for (int i = 0; i < numPowers; i++) {
        cout << right << setw(2)  << i << ": " 
             << right << setw(11) << powersOfTwo[i] 
             << right << setw(33) << &powersOfTwo[i] 
             << "\n"; 
    }

    // Range based for loop
    /*
    for (const int i : numPowers) {
        cout << i << "\n";
    }
    */

    int sizeInBytes = 0;
    int sizeInBits  = 0;

    sizeInBytes = sizeof(int);
    sizeInBits  = sizeInBytes << 3;

    cout << "\n";
    cout << "sizeof(int) : " << sizeInBytes << " (bytes) / "
                             << sizeInBits  << " (bits)" 
         << "\n";

    sizeInBytes = sizeof(int&);
    sizeInBits  = sizeInBytes << 3;

    cout << "sizeof(int&): " << sizeInBytes << " (bytes) / "
                             << sizeInBits  << " (bits)"  
         << "\n";

    sizeInBytes = sizeof(int*);
    sizeInBits  = sizeInBytes << 3;

    cout << "sizeof(int*): " << sizeInBytes << " (bytes) / "
                             << sizeInBits  << " (bits)"  
         << "\n";

    sizeInBytes = sizeof(sizeof(powersOfTwo));
    sizeInBits  = sizeInBytes << 3;

    cout << "\n";
    cout << "sizeof(powersOfTwo): " << sizeInBytes << " (bytes) / "
                                    << sizeInBits  << " (bits)"  
         << "\n";

    sizeInBytes = (sizeof(int) * numPowers);
    sizeInBits  = sizeInBytes << 3;

    cout << "data size:           " << sizeInBytes << " (bytes) / "
                                    << sizeInBits  << " (bits)"  
         << "\n";

    return 0;
}