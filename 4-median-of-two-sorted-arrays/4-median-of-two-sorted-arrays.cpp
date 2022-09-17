#include <stack>
#define BIGGER(X, Y) X.size() > Y.size() ? X : Y;
#define SMALLER(X, Y) X.size() <= Y.size() ? X : Y;

class Solution {
public:
    //right가 항상 한개 더 많도록 유도할 것
    std::stack<int> left;
    std::stack<int> right;

    void left_to_right(std::stack<int>& left, std::stack<int>& right) {
        right.emplace(left.top());
        left.pop();
    }

    void right_to_left(std::stack<int>& left, std::stack<int>& right) {
        left.emplace(right.top());
        right.pop();
    }

    void equal_size(std::stack<int>& left, std::stack<int>& right) {
        int diff = left.size() - right.size();
        int size = left.size() + right.size();

        while (left.size() != size / 2) {
            if (diff > 0) left_to_right(left, right);
            else if (diff < 0) right_to_left(left, right);
        }
    }

    double ret_ans(std::stack<int>& left, std::stack<int>& right) {
        return ((right.size() - left.size()) == 1) ? (right.top()) : (((double)left.top() + (double)right.top()) / 2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() + nums2.size() == 1) {
            return (nums1.size() == 1) ? nums1[0] : nums2[0];
        }

        //큰거를 left에 절반, right에 절반 넣을 예정(홀수 개면 right가 더 많이)
        std::vector<int> small = SMALLER(nums1, nums2);
        std::vector<int> big = BIGGER(nums1, nums2);

        int index = big.size();
        for (int k = index - 1; k >= index / 2; k--) {
            right.emplace(big[k]);
        }
        for (int k = 0; k < index / 2; k++) {
            left.emplace(big[k]);
        }

        for (int k = 0; k < small.size(); k++) {
            int val = small[k];
            while (1) {
                if (!right.empty() && right.top() < val) {
                    right_to_left(left, right);
                }
                else if (!left.empty() && left.top() > val) {
                    left_to_right(left, right);
                }
                else if (!left.empty() && !right.empty() && left.top() <= val && val <= right.top()) {
                    left.emplace(val);
                    break;
                }
                if (left.empty()) {
                    left.emplace(val);
                    break;
                }
                else if (right.empty()) {
                    right.emplace(val);
                    break;
                }
            }
        }

        equal_size(left, right);
        return ret_ans(left, right);
    }
};