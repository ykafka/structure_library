//
//  main.cpp
//  workspace
//
//  Created by Yuting Liu on 12/1/22.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> nums1, int m, vector<int> nums2, int n) {
    int i = 0, j = 0;
    vector<int> res;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            res.push_back(nums1[i++]);
        } else {
            res.push_back(nums2[j++]);
        }
    }
    
    for (; i<m; i++) {
        res.push_back(nums1[i]);
    }
    for (; j<n; j++) {
        res.push_back(nums2[j]);
    }
    
    return res;
}

int main(void) {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
}
