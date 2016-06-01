class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // Findout intersection area
        int Lx = max(A,E);
        int Ly = max(B,F);
        int Hx = min(C,G);
        int Hy = min(D,H);
        int intersectionArea = 0;
        if( (Lx < Hx) && (Ly < Hy) )
            intersectionArea = (Hx - Lx) * (Hy - Ly);
        assert( (A < C) && (B < D) );
        assert( (E < G) && (F < H) );
        int Rect1Area = (C-A) * (D-B);
        int Rect2Area = (G-E) * (H-F);
        return (Rect1Area + Rect2Area - intersectionArea);
    }
};