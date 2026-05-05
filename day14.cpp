#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int result = 0;
        
        int sum = 0;
        for(std::vector<int>::iterator it = nums.begin();it != nums.end();it++){
            if(*it ==1){
                result++;
                
            }else if(*it ==0){
               if(result>sum){
                sum =result;
               }

                result = 0;
            }
        }
        if(result>sum)sum = result;
        return sum;
    }
};

// int main(){
//     Solution s;
//     std::vector<int>v;
//     v.push_back(1);
//     v.push_back(1);
//     v.push_back(0);
//     v.push_back(1);
//     v.push_back(1);
//     v.push_back(1);
//     int result = s.findMaxConsecutiveOnes(v);
//     std::cout<<result;
// }