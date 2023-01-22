#include <iostream>
#include <cmath>

bool isHappy( int );

int main()
{
    std::cout << "Enter a number\t\n";
    
    int number{};

    std::cin >> number;

    std::cout << isHappy( number ) << '\n';

    return 0;
}

bool isHappy( int n )
{       
    // base case
    if( n == 1 )
        return true;
    else if( n < 9 and n != 7 )
        return false;

    int result{};

    // keep dividing the number until it becomes a single digit.
    while( n >= 10 ) {
        // add the square of the ones digit        
        result += pow( n % 10, 2 );

        n /= 10;
    }

    // if just a single digit, then add the square to result
    result += pow( n, 2 );

    // recursively call until it is a happy number
    return isHappy( result );
}