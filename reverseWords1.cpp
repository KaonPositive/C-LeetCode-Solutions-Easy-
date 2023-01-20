#include <iostream>
#include <vector>

void reverseString( std::vector<char>& );

int main()
{
    std::cout << "Enter something\t\n";

    std::vector<char>vec;

    char input;

    while( 1 )
    {
        std::cin >> input;
        
        if ( input == '!' )
            break;

        vec.push_back( input );
    }

    reverseString( vec );

    for ( char i : vec )
        std::cout << i;

    std::cout << '\n';

    return 0;
}

void reverseString( std::vector<char>& s )
{
    for ( int i{}, j = s.size() - 1; i < j; ++i, --j ) {
        char temp = s[i];
        
        s[i] = s[j];
        s[j] = temp;
    }
}
