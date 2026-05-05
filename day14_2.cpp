#include<iostream>
#include<vector>
class solution{
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        std::vector<int>rightRangeNums;
        int preNum =0;
        int rightNextNum = 0;
        for(std::vector<int>::iterator it =nums.begin();it!=nums.end();it++){
            if(preNum!=*it -1){
            int rightNextNum = preNum+1;
            *it =rightNextNum;
            rightRangeNums.push_back(preNum);
            rightRangeNums.push_back(*it);
            }
            preNum = *it;

        }
        return rightRangeNums;
    }
};
int main(){
    
}