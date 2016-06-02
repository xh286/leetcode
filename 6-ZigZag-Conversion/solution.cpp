class Solution {
public:
    string convert(string s, int numRows) {
        // First row starts with s[0], and all s[i] where i is multiple of (2*k-2), where k=numRows.
        // Last row similar, indices just added by (k-1).
        // All other rows contain additional entries. For each base index, there's an additional index at offset (2*(k-1-i) where i is row index (zero-based). In fact, first / last row also satisfy this property, but this offset is multiple of 2*(k-1), so overlaps with base index. This condition can be tested with %.
        // We need to make sure all the inserted characters are from indices < n.
        int n = s.size();
        string r;
        // check corner cases here later
        if(numRows<1) return r; // no conversion, or empty?
        if(numRows==1) return s;
        int k = numRows;
        int d = 2 * (k-1); // distance between base indices
        
        for(int i=0; i<k; i++) // i is row index
        {
            // process row i
            for(int j = i; j < n; j += d) // jump by d distance each time. Starting at i.
            {
                r.push_back(s[j]);
                int d2 = d - 2*i; // secondary offset relative to the base indices j. For row 0, this is same as d.
                if(i != 0 && i != (k-1)) // not first / last row, equivalent to d2%d, but probably faster?
                    if(j+d2 < n)
                        r.push_back(s[j+d2]);
            }
        }
        return r;
    }
};