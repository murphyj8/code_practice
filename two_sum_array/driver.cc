#include <iostream>
#include <vector>

/*
Given an aray of integers & a target sum, return the index of the 
numbers that give the sum target sum
*/

/*
easy test -> [1,3,7,9,2], target = 11, answer = [3,4]
easy test fail -> [1,3,7,9,2], target = 25, answer = null

empty [], t = 1, answer = null
1 entry [5], t = 1, answer = null

[1,6], t = 67, answer = [0,1]

*/


std::vector<int> two_sum_test(const std::vector<int>& nums, const int& target){
    if(nums.empty()){
        return std::vector<int>(); 
    }
    if(nums.size() == 1){
        return std::vector<int>();  
    }

    std::vector<int>::const_iterator p1 = nums.begin(); 
    for(; p1 != nums.end(); ++ p1){
        const int& num_to_find = target - *p1;
        std::vector<int>::const_iterator find_loc = std::find(nums.begin(), nums.end(), num_to_find); 
        if(find_loc != nums.end()){
            //return(std::make_pair(std::distance(test_arr.begin(), p1), std::distance(test_arr.begin(),find_loc )));
            return std::vector<int>{ static_cast<int>(std::distance(nums.begin(), p1)), static_cast<int>(std::distance(nums.begin(),find_loc))};
        }
    } 
    return std::vector<int>();
}
std::pair<int, int> two_sum_test_brute_force(const std::vector<int>& test_arr, const int& target){
    if(test_arr.empty()){
        return std::make_pair(-1,-1); 
    }

    if (test_arr.size() == 1){
        return std::make_pair(-1,-1); 
    }

    for(std::vector<int>::const_iterator iter = test_arr.begin(); iter != test_arr.end(); ++ iter){
        for(std::vector<int>::const_iterator inner_iter = test_arr.begin(); inner_iter != test_arr.end(); ++ inner_iter){
            if(iter != inner_iter){
                if(*iter + *inner_iter == target){
                    return std::make_pair(std::distance(test_arr.begin(), iter), std::distance(test_arr.begin(), inner_iter));
                }
            }
        }
    }
    return std::make_pair(-1,-1);
}

std::vector<int> two_sum_test_v3(const std::vector<int> nums, const int& target){
    if(nums.empty()){
        return std::vector<int>(); 
    }
    if(nums.size() == 1){
        return std::vector<int>();  
    }

    std::vector<int>::const_iterator p1 = nums.begin(); 
    for(; p1 != nums.end(); ++ p1){
        const int& num_to_find = target - *p1;

        std::vector<int>::const_iterator find_loc = std::find(p1 + 1,  nums.end(), num_to_find); 
        if(find_loc != nums.end()){
            //return(std::make_pair(std::distance(test_arr.begin(), p1), std::distance(test_arr.begin(),find_loc )));
            return std::vector<int>{ static_cast<int>(p1 - nums.begin()), static_cast<int> (find_loc - nums.begin())};
        }
    } 
    return std::vector<int>();
}

std::vector<int> two_sum_test_hashmap(const std::vector<int>& nums, const int& target){
    if(nums.empty()){ return std::vector<int> ();}
    if(nums.size() == 1){ return std::vector<int> ();}

    std::unordered_map<int, int> nums_to_find; 
    std::vector<int>::const_iterator p1 = nums.begin(); 
    for(;p1 != nums.end(); ++ p1){
        const int& search_num = target - *p1; 
        std::unordered_map<int,int>::const_iterator search_iter = nums_to_find.find(search_num); 
        if(search_iter != nums_to_find.end()){
            // found the number
            return std::vector<int>{ nums_to_find[search_num], static_cast<int> (p1 - nums.begin())} ; 
        }else{
            nums_to_find[*p1] = p1 - nums.begin(); 
        }
    }
    return std::vector<int> (); 
}

int main(int argc, char* argv[]){
    std::cout << "starting" << std::endl; 
    std::vector<int> nums = {2,7,11, 15};
    int target = 9;
    //std::vector<int> nums = {1,3,7,9,2}; 
    //int target = 11; 
    //std::vector<int> nums = {3,3}; 
    //int target = 6; 
    std::vector<int> res = two_sum_test_v3(nums, target); 
    if(res.size() == 0){
        std::cout << "No values returned" << std::endl;
    }else{
        std::cout << "second pointer with lookup -> " << res[0] << "," << res[1] << std::endl; 
    }
    std::pair<int, int> res_two = two_sum_test_brute_force(nums, target); 
    std::cout << "brute force loop -> " << res_two.first << "," << res_two.second << std::endl; 

    std::vector<int> res_opt = two_sum_test_hashmap(nums, target); 
    std::cout << "optimised loop -> " << res[0] << "," << res[1] << std::endl; 
    return 0; 
}