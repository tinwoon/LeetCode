class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int turtle = 0;
        int rabit = 0;

        do{
            turtle = nums[turtle];
            rabit = nums[nums[rabit]];
        }while(turtle != rabit);

        turtle = 0;
        
        while(turtle != rabit){
            turtle = nums[turtle];
            rabit = nums[rabit];
        }

        return turtle;
    }
};