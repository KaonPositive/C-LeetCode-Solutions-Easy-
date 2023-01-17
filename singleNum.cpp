#include <iostream>
#include <unordered_map>
#include <vector>

int singleNumber( std::vector<int>& );
int singleNumber2( std::vector<int>& );

int main()
{
    std::cout << "Enter numbers\t\n";

    int input{};

    std::vector<int> vec;
    
    while ( input >= 0 ) {
        std::cin >> input;

        if ( input < 0 ) break;

        vec.push_back( input );
    }

    std::cout << singleNumber( vec ) << '\n';
    std::cout << singleNumber2( vec ) << '\n';

    return 0;
}

int singleNumber2( std::vector<int>& nums )
{
    int single{};

    for ( auto i : nums )
        single ^= i;

    return single;
}


int singleNumber( std::vector<int>& nums )
{
    std::unordered_map<int, int> numbers;
    int single{};
    
    for ( int i{}; i < nums.size(); ++i )
        ++numbers[nums[i]];

    for ( auto i : numbers )
        if ( i.second == 1 )
            single = i.first;

    return single;
}