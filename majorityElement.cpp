#include <iostream>
#include <vector>
#include <unordered_map>

int majorityElement( std::vector<int>& );

int main()
{
    std::vector<int> vec;

    std::cout << "Enter elements of vector\n";

    int input{};

    while ( 1 ) {
        std::cin >> input;

        if ( input < 0 )
            break;
        
        vec.push_back( input );
    }

    std::cout << majorityElement( vec ) << '\n'; 

    return 0;
}

// can also refer to the moore's voting algorithm

int majorityElement( std::vector<int>& nums )
{
    std::unordered_map<int, int>mapNum;
    int major{}, count{};

    for ( int i{}; i < nums.size(); ++i ) {
        ++mapNum[nums[i]];

        std::unordered_map<int, int>::const_iterator it = mapNum.find( nums[i] );
        
        if ( it->second >= count ) {
            count = it->second;
            major = it->first;
        }
    }
    
    return major;
}
