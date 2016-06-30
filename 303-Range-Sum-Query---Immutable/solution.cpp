class NumArray {
private:
    vector<int> u;
    int n;
public:
    NumArray(vector<int> &nums) : n(nums.size()), u(vector<int>(n+1,0)) {
        for(int i=1; i<n+1; i++)
            u[i] = u[i-1] + nums[i-1];
        // u[0] = 0, u[i] = sum(nums[0...i-1]).
    }

    int sumRange(int i, int j) {
        // sum(nums[i...j]) = u[j+1] - u[i].
        if(i>j || i<0 || j >= n) return 0;
        return (u[j+1] - u[i]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);