#include <iostream>
#include <unordered_map>

bool isValid( std::string );

int main()
{
    std::string input;
    std::cin >> input;
    
    std::cout << isValid( input );

    return 0;
}

// works but runtime is ass

bool isValid( std::string s ) {
    bool valid = true;
    
    // only accepts an even-length string
    if ( s.length() % 2 == 0 ) {
        std::unordered_map<std::string, bool> paren = {
            {"{}", true}, {"[]", true}, 
            {"()", true}
        };

        // iterate through characters
        for ( int i{}; i < s.length(); ++i ) {            
            // if reached at the end of string, make it invalid since the string is not valid (string must be length 0 to make it valid since pairs are removed)
            if ( i == (s.size() - 1) ) { 
                valid = false;
                break;
            }

            // piece characters together
            std::string substring = s.substr( i, 1 ) + s.substr( i + 1, 1 );
            
            // if valid, then erase characters and starts all the way back to index 0 (i is -1 since at the end of loop it increments i)
            if ( paren[substring] ) {
                s.erase( i, 2 );
                i = -1;
            }
        }
    }
    else
        valid = false;

    return valid;
}