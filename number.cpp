#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

int decimal_to_ternary (int n) {
    assert (n >= 0);
    int result = 0;
    int base = 1;
    while (n > 0) {
        result += n % 3 * base;
        n /= 3;
        base *= 10;
    }
    return result;
    }

void convert_vector_to_ternary (std::vector<int> &v) {
    for (auto &i : v) {
        i = decimal_to_ternary (i);
    }
}   

int find_number(std::vector<int> &numbers) {
    convert_vector_to_ternary(numbers);
    unsigned int result =  std::accumulate(numbers.begin(), numbers.end(), 0, [](int lhs, int rhs) { 
        return lhs ^ rhs;
    });
    return result;
}

int main()
{
    std::vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4};
    for ( int i = 0; i < nums.size(); i++ ) {
        std::cout << decimal_to_ternary(nums[i]) << std::endl;
    }
}