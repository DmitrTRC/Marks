#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::vector<int> nums = {1, 1, 1, 2, 2, 4, 2, 7, 4, 7, 3, 4, 3, 3, 4, 4, 4};
    std::map <int, int> ocuurence;
    for ( auto item : nums ){
        ocuurence[item]++;

    }
    
    for ( auto item : ocuurence ){
     if (item.second % 3 != 0){
            std::cout << "Number found : " << item.first << " " << std::endl;
     }
        
    }
}