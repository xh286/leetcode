/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    using Line = tuple<int,int,int>; // ax-by=c, where GCD(a,b)==1, and a>=0. So (a,b,c) unique for given line.
    int findGCD(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        if(a<b) return findGCD(b,a);
        if(b==0) return a;
        return findGCD(b,a%b);
    }
    void getLine(const Point& point1, const Point& point2, Line& line)
    {
        int v_diff = point2.y - point1.y;
        int h_diff = point2.x - point1.x;
        // v_diff/h_diff = a/b. Make sure a>=0.
        if(v_diff<0)
        {
            v_diff = -v_diff;
            h_diff = -h_diff;
        }
        int gcd = findGCD(v_diff, h_diff);
        int a = v_diff/gcd;
        int b = h_diff/gcd;
        int c = a*point1.x - b*point1.y;
        line = make_tuple(a,b,c);
    }
public:
    int maxPoints(vector<Point>& points) {
        //O(n^2) solution using a hash map from (a,b,c) to count. 
        
        unordered_map<Line,int> mp;
        int n = points.size();
        if(n<=2) return n;
        Line line;
        getLine(points[0], points[1], line);
        mp[line] = 2;
        int max_points = 2;
        for(int i=2;i<n; i++)
            for(int j=0; j<i; j++)
            {
                getLine(points[j],points[i],line);
                auto it = mp.find(line);
                if(it != mp.end())
                {
                    it->second++;
                    max_points = max(max_points,it->second);
                }
                else
                    mp[line] = 2;
            }
        return max_points;
    }
};