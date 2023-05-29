class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int asc = 0;
        int idx = digits.size() - 1;
        digits[idx]++;
        do{
            asc = digits[idx] / 10;
            if(asc){
                digits[idx] = 0;
                if(idx - 1 < 0){
                    digits.insert(digits.begin(), 1);
                    break;
                }else{
                    digits[idx - 1] += asc;
                }
            }
            idx--;
        }while(asc);
        
        return digits;
    }
};