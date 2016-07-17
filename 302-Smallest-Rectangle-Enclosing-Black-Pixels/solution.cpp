class Solution {
    /*
      Recursively call visit function to visit all black pixels, and update x_min, x_max, y_min, y_max.
      Image has '0' or '1'. x for row, y for column.
    */
private:
    void visitPixel(vector<vector<char>>& image, int x, int y, int& x_min, int& x_max, int& y_min, int& y_max)
    {
        int m = image.size();
        int n = image[0].size();
        x_min = min(x, x_min);
        y_min = min(y, y_min);
        x_max = max(x, x_max);
        y_max = max(y, y_max);
        if(x-1>=0 && image[x-1][y]=='1') visitPixel(image, x-1, y, x_min, x_max, y_min, y_max);
        if(x+1<m && image[x+1][y]=='1') visitPixel(image, x+1, y, x_min, x_max, y_min, y_max);
        if(y-1>=0 && image[x][y-1]=='1') visitPixel(image, x, y-1, x_min, x_max, y_min, y_max);
        if(y+1<n && image[x][y+1]=='1') visitPixel(image, x, y+1, x_min, x_max, y_min, y_max);
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        if(m<=0 || n<=0) return 0;
        int x_min = x;
        int x_max = x;
        int y_min = y;
        int y_max = y;
        // assert(image[x][y] == '1');
        visitPixel(image, x, y, x_min, x_max, y_min, y_max);
        return (x_max-x_min+1)*(y_max-y_min+1);
    }
};