#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

int uniqueMorseRepresentations( std::vector<std::string>& );

int main()
{
    std::string input = "";
    std::vector<std::string> words;

    std::cout << "Enter your string here:\t\n";

    while( 1 ) {
        std::cin >> input;
        if( input == "!" ) break;

        words.push_back( input );
    }

    std::cout << uniqueMorseRepresentations( words ) << '\n';

    return 0;
}

int uniqueMorseRepresentations( std::vector<std::string>& words )
{
    std::unordered_map<char, std::string> morse = {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."},
        {'d', "-.."}, {'e', "."}, {'f', "..-."},
        {'g', "--."}, {'h', "...."}, {'i', ".."},
        {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."},
        {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."},
        {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
        {'u', "..-"}, {'v', "...-"}, {'w', ".--",}, {'x', "-..-"},
        {'y', "-.--"}, {'z', "--.."}
    };

    std::set<std::string> morseResult;
    std::string result = "";
    
    for( std::string word : words ) {
        for( char ch : word )
            result += morse[ch];

        morseResult.insert( result );

        result = "";
    }

    return morseResult.size();
}