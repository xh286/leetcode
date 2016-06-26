class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n3 = s3.size();
        int n1 = s1.size();
        int n2 = s2.size();
        int i1 = 0;
        int i2 = 0;
        for(int i3=0; i3<n; i3++)
        {
            if(i1 < n1 && s3[i3] == s1[i1]) i1++;
            else if(i2 < n2 && s3[i3] == s2[i2]) i2++;
            else return false;
        }
        return true;
    }
};