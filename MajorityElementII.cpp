class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
       int n = arr.size();

    // Initialize two candidates and their counts
    int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;

    for (int ele : arr) {
      
        // Increment count for candidate 1
        if (ele1 == ele) {
            cnt1++;
        }
      
        // Increment count for candidate 2
        else if (ele2 == ele) {
            cnt2++;
        }
      
        // New candidate 1 if count is zero
        else if (cnt1 == 0) {
            ele1 = ele;
            cnt1++;
        }
      
        // New candidate 2 if count is zero
        else if (cnt2 == 0) {
            ele2 = ele;
            cnt2++;
        }
      
        // Decrease counts if neither candidate
        else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> res;
    cnt1 = 0;
    cnt2 = 0;

    // Count the occurrences of candidates
    for (int ele : arr) {
        if (ele1 == ele) cnt1++;
        if (ele2 == ele) cnt2++;
    }

    // Add to result if they are majority elements
    if (cnt1 > n / 3) res.push_back(ele1);
    if (cnt2 > n / 3 && ele1 != ele2) res.push_back(ele2);
    
    if(res.size() == 2 && res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}
    
};