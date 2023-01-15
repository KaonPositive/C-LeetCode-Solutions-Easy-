#include <iostream>
#include <vector>

std::vector<int> plusOne( std::vector<int>& );

int main()
{
    std::vector<int> vec = {};

    std::cout << "Enter numbers:\t";

    int input{};

    while ( input >= 0 ) {
        std::cin >> input;

        if ( input >= 0 )
            vec.push_back( input );
        else
            break;
    }

    plusOne( vec );

    for ( auto i : vec )
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}

std::vector<int> plusOne( std::vector<int>& digits )
{
    int tail = digits.size() - 1;
    int addIndex{tail};

    if ( digits[tail] == 9 ) {
        while( tail >= 0 ) {
            if ( digits[tail] == 9 ) {
                // if reached at the front of vector
                if ( tail == 0 ) {
                    // expands vector--inserts 0 at the end of vector
                    digits.resize( digits.size() + 1 );
                    // 0 is set to have leading num be incremented after breaking out of the loop
                    digits[0] = 0;
                }
                else {
                    // sets current vector number to 0
                    digits[tail] = 0;
                    --tail;
                }
            }
            else break;
        }
    }
        
    ++digits[tail];

    return digits;
}