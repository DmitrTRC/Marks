#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

int decimal_to_ternary(int n)
{
    assert(n >= 0);
    int result = 0;
    int base = 1;
    while (n > 0)
    {
        result += n % 3 * base;
        n /= 3;
        base *= 10;
    }
    return result;
}

int ternary_to_decimal(int n)
{
    assert(n >= 0);
    int result = 0;
    int base = 1;
    while (n > 0)
    {
        result += n % 10 * base;
        n /= 10;
        base *= 3;
    }
    return result;
}

void convert_vector_to_ternary(std::vector<int> &v)
{
    for (auto &i : v)
    {
        i = decimal_to_ternary(i);
    }
}

int find_number(std::vector<int> &numbers)
{
    convert_vector_to_ternary(numbers);
    unsigned int result = std::accumulate(numbers.begin(), numbers.end(), 0, [](int lhs, int rhs)
                                          { return lhs ^ rhs; });
    return result;
}
int get_multiplyer(int n)
{
    int tmp = 0;
    tmp = static_cast<int> ( n / 10 );
    
}

int main()
{
    std::vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4};
    std::vector<int> nums2 = {1, 1, 1, 1, 1, 1, 6, 6};
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << decimal_to_ternary(nums[i]) << std::endl;
    }
    std::cout << "Next : " << std::endl;

    std::cout << decimal_to_ternary(std::accumulate(nums2.begin(), nums2.end(), 0, [](int lhs, int rhs)
                                                    { return lhs + rhs; }))
              << std::endl;
    std::cout << "Decimal : " << std::accumulate(nums2.begin(), nums2.end(), 0, [](int lhs, int rhs)
                                                 { return lhs + rhs; })
              << std::endl;
    convert_vector_to_ternary(nums);
}