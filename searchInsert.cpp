#include <iostream>
#include <vector>

int searchInsert( std::vector<int>&, int );

int main()
{
    std::vector<int>vec;

    int input{};

    std::cout << "enter numbers for vec\n";

    while ( input >= 0 ) {
        std::cin >> input;
        if ( input < 0 )
            break;
        vec.push_back( input );
    }

    int target{};

    std::cout << "enter target number\n";

    std::cin >> target;

    std::cout << searchInsert( vec, target ) << '\n';

    return 0;
}

int searchInsert( std::vector<int>& nums, int target )
{
    int low{}, high = nums.size() - 1, mid{-1};

    while ( low <= high ) {
        if ( low == high and nums[high] < target )
            // right side is always greater by one, so it makes since to return ++high.
            return ++high;

        // get median of the vector. ceil( mid ). ex: 99 / 2 = 49.5. ceil(49.5) is 50. do that until 1
        mid = ( high + low ) / 2;
        
        if ( nums[mid] < target )
            low = mid + 1;
        else if ( nums[mid] > target )
            high = mid - 1;
        // if target is found, then break
        else
            break;
    }

    return mid;
}