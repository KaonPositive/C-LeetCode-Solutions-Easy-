#include <iostream>
#include <unordered_map>

int romanToInt( std::string );

int main()
{
    std::string input;
    std::cout << "Enter a roman string:\t";
    std::cin >> input;
    std::cout << romanToInt( input ) << '\n';
}

int romanToInt(std::string s) {
    // unordered map so retrieval is O(1)
    std::unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5},
        {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500},
        {'M', 1000}
    };

    int total{};

    // case if only a string of length 1 is given
    if ( s.size() == 1 )
        return roman[s[0]];
    
    // case if the string length is > 1
    for ( int i{}; i < s.length(); ++i ) {
        // check val 0 and 1, 1 and 2, etc.. until string length times
        int val1 = roman[s[i]];
        int val2 = roman[s[i+1]];

        if ( val1 < val2 ) 
            total -= val1;
        else
            total += val1;
    }

    return total;
}