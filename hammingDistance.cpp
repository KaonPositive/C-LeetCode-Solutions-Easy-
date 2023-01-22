#include <iostream>

int hammingDistance( int, int );

int main()
{
    std::cout << "Enter numbers\t\n";

    int inputX{}, inputY{};

    std::cin >> inputX >> inputY;

    std::cout << hammingDistance( inputX, inputY ) << '\n';

    return 0;
}

int hammingDistance( int x, int y )
{
    int result{}, xorNum = x ^ y;

    // basically says to keep shifting the bits to the right until it turns to 0.
    while( xorNum > 0 ) {
        // will only add the number of bits if the bit position reaches to 2^0 or 1
        if( xorNum % 2 == 1 )
            ++result;

        xorNum = xorNum >> 1;
    }

    return result;
}