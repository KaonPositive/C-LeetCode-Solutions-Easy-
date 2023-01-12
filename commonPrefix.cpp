#include <iostream>
#include <vector>

std::string longestCommonPrefix( std::vector<std::string>& );

int main()
{
    std::vector<std::string>vec;

    std::string words = "";

    std::cout << "Enter a valid string to append to vector.\n -1 to quit\n";

    while ( 1 ) {
        std::cin >> words;
        if ( words == "-1" )
            break;

        vec.push_back( words );
    }
    
    std::cout << longestCommonPrefix( vec ) << '\n';


    return 0;
}

std::string longestCommonPrefix( std::vector<std::string> &strs )
{
    bool common = false;
    std::string prefix = "";

    if ( strs.size() == 1 )
        return strs[0];

    int j{};
    // will keep looping until a common prefix is established
    while ( !common ) {
        // if reached at the end of the string
        if ( j == strs[0].size() ) {
            common = true;
            break;
        }
        
        bool append = false;
        // iterates through the vector of strings
        for ( int i{1}; i < strs.size(); ++i ) {
            // if index (j) has reached the end of the iterative string
            if ( j == strs[i].length() - 1 )
                common = true;
            // if the iterative string's character is not the same as initial string
            if ( strs[i][j] != strs[0][j] ) {
                append = false;
                common = true;
                break;
            } 
            else 
                append = true;
        }
        
        if ( append )
            prefix += strs[0][j];

        ++j;
    }

    return prefix;
}