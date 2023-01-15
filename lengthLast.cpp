#include <iostream>
#include <vector>
#include <sstream>

int lengthOfLastWord1( std::string );
int lengthOfLastWord2( std::string );

int main()
{
    std::string s = "luffy is still joyboy";

    std::cout << lengthOfLastWord1( s ) << '\n';

    std::cout << lengthOfLastWord2( s ) << '\n';

    return 0;
}

int lengthOfLastWord1( std::string s )
{   
    std::stringstream parse( s );
    std::string output;

    // will read string and remove whitespace delim
    // output string will always change to latest string
    while( parse >> output ) {}

    return output.size();
}

int lengthOfLastWord2( std::string s )
{
    int tail = s.length() - 1, count{};

    // flag needed to indicate that a current character is a white-space and that it is the end of the valid string.
    bool flag = false;

    while ( tail >= 0 ) {
        // if the end of the current string, then exit
        if ( flag and s[tail] == ' ' ) break;

        // keep looping until there is a valid white-space character
        if ( s[tail] == ' ' )
            --tail;
        // count the number of valid characters and toggle flag as true
        else {
            ++count;
            flag = true;
            --tail;
        }
    }

    return count;
}