#include <iostream>
#include <vector>

int removeElement( std::vector<int>&, int );

int main()
{
    std::vector<int>nums;

    std::cout << "enter a list of numbers\nenter a negative number to exit.\n";

    int numInput{};

    while ( numInput >= 0 ) {
        std::cin >> numInput;
        if ( numInput >= 0 )
            nums.push_back( numInput );
        else
            break;
    }

    std::cout << '\n';
    
    std::cout << removeElement( nums, 2 ) << '\n';

    for ( auto i : nums )
        std::cout << i << '\n';

    return 0;
}

int removeElement( std::vector<int>& nums, int val )
{
    for ( int i{}; i < nums.size(); ++i ) {
        // if the value is the same as the element found in the vector, shift the elements to the left
        if ( nums[i] == val ) {
            // resize the vector by nums.size() - 1 as you're shifting the elements / removing the found number
            nums.resize( nums.size() - 1 );
            // shifts elements to the left
            for ( int j = i; j < nums.size(); ++j )
                nums[j] = nums[j + 1];
            
            // i will be set to 0 to iterate from the beginning of the vector
            i = -1;
        }
    }

    return nums.size();
}