#include <iostream>

int strStr( std::string, std::string );

int main()
{
    std::string haystack, needle;
    
    std::cout << "enter a haystack string:\t";

    std::cin >> haystack;

    std::cout << "\nenter a needle string:\t";

    std::cin >> needle;

    std::cout << strStr( haystack, needle );

    return 0;
}

int strStr( std::string haystack, std::string needle )
{
    int found{-1};

    // iterate through haystack
    for ( int i{}; i < haystack.length(); ++i ) {
        // if the string is found, make found equal to index and break
        if ( haystack.substr( i, needle.length() ) == needle ) {
            found = i;
            break;
        }
    }

    return found;
}