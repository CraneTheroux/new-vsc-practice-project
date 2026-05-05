#include<iostream>
#include<vector>
#include<map>
class solution{
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int length = nums.size();
        std::map<int,int>freq;
        for(int x:nums)freq[x]++;
        int dup = 0; 
        int miss = 0;
        for(int i =1;i<=length;i++){
            if(freq[i]==2)dup =i;
            if(freq[i]==0)miss = i;
        }
        return {dup,miss};
       
        /*完整版：for(int i =0;x<nums.size();i++){
            int x = nums[i];
            freq[x]++;
        
        }*/

    
    }
};
int main(){
    
}