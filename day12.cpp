#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
class format{
public:
    void operator ()(int val)const{
        std::cout<<val<<" ";
    }
};

class Solution {
public:
  std::vector<int> shuffle(std::vector<int> nums, int n) {
    std::vector<int>temp;
    temp.resize(nums.size());
    for(int i = 0;i<nums.size();i++){
        temp[2*i] =nums[i];
        temp[2*i+1] =nums[i+3];
    }
    return temp;
    }
};
// int main(){
//     std::vector<int>test;
//     int length =0;
//     std::cout<<"enter the num:"<<std::endl;
//     std::cin>>length;
//     for(int i = 0;i<length;i++){
//         test.push_back(i);
//     }
//     int nums= 0;
//     std::cout<<"enter the test num:"<<std::endl;
//     std::cin>>nums;
//     Solution s;
//     std::vector<int>result = s.shuffle(test,nums);
//     std::for_each(result.begin(),result.end(),format());
// }