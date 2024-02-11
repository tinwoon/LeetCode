class Solution {
public:
    bool calculate(vector<int>& nums, int target){
        if(nums.size() == 1) return nums[0] == target;
        
        int turning_point = 0;
        std::vector<int> data(nums.size(), 0);
        
        for(int k = 1; k < nums.size(); k++){
            if(nums[k - 1] > nums[k]){
                turning_point = k;
                break;
            }
        }
        
        for(int k=0; k < nums.size(); k++){
            data[k] = nums[((k + turning_point) % nums.size())];
        }
        
        auto itr = std::lower_bound(data.begin(), data.end(), target);
        
        return (itr != data.end()) ? (*itr == target) : false;
    }
    
    bool search(vector<int>& nums, int target) {
        return calculate(nums, target);
    }
};