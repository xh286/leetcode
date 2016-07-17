class Solution {
    /*
      Recursively call visit function to visit all black pixels, and update x_min, x_max, y_min, y_max.
      Image has '0' or '1'. x for row, y for column.
    */
private:
    int x_min;
    int y_min;
    int x_max;
    int y_max;
    int m;
    int n;
    void visitPixel(vector<vector<char>>& image, int x, int y)
    {
        x_min = min(x, x_min);
        y_min = min(y, y_min);
        x_max = max(x, x_max);
        y_max = max(y, y_max);
        image[x][y] = '0';
        if(x-1>=0 && image[x-1][y]=='1') visitPixel(image, x-1, y);
        if(x+1<m && image[x+1][y]=='1')  visitPixel(image, x+1, y);
        if(y-1>=0 && image[x][y-1]=='1') visitPixel(image, x, y-1);
        if(y+1<n && image[x][y+1]=='1')  visitPixel(image, x, y+1);
        image[x][y] = '1';
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        m = image.size();
        if(m==0) return 0;
        n = image[0].size();
        if(n==0) return 0;
        x_min = INT_MAX;
        x_max = INT_MIN;
        y_min = INT_MAX;
        y_max = INT_MIN;
        // assert(image[x][y] == '1');
        visitPixel(image, x, y);
        return ((x_max - x_min+1)*(y_max - y_min+1));
    }
};