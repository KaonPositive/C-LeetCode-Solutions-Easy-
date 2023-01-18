#include <iostream>
#include <string>

bool isPalindrome( std::string );

int main()
{
    std::cout << "Enter a string\t\n";
    std::string input;
    std::getline( std::cin, input );
    
    std::cout << isPalindrome( input ) << '\n';
    return 0;
}

bool isPalindrome( std::string s )
{
    std::string lowercase = "";

    for ( auto i : s ) {
        char lowChar = tolower( i );

        // 48 is the lowerbound for a number found in the ascii table; 57 is the upperbound ( basically represents numbers 0 - 9 )
        // 97 is the lowerbound for a letter found in the ascii table; 122 is the upperbound ( basically represents the lowercase letters )

        int conv = lowChar - 0;
        
        if ( (conv >= 48 and conv <= 57 ) or (conv >= 97 and conv <= 122) )
            lowercase += lowChar;
    }

    int length = lowercase.size() - 1;
    
    for ( int i = length, j{}; i >= 0 or j < length; --i, ++j ) {        
        if ( lowercase[i] != lowercase[j] )
            return false;
    }

    return true;
}