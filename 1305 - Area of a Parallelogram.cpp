// 1305 - Area of a Parallelogram
// solved
#include<bits/stdc++.h>

using namespace std;

double triangle_area(int ax, int ay, int bx, int by, int cx, int cy)
{
    double A = sqrt((double)(bx-ax) * (bx-ax) + (by-ay) * (by-ay));
    double B = sqrt((double)(bx-cx) * (bx-cx) + (by-cy) * (by-cy));
    double C = sqrt((double)(ax-cx) * (ax-cx) + (ay-cy) * (ay-cy));
    double s = (A + B + C) / 2;
    double area = sqrt( s * (s-A) * (s-B) * (s-C));
    return area;
}

int main()
{
    int x[4], y[4], t, test = 1;
    scanf("%d", &t);
    while(t--){
        for(int i=0; i<3; i++){
            scanf("%d%d", &x[i], &y[i]);
        }
        int x1, y1;
        x1 = x[2] - x[1];
        y1 = y[2] - y[1];
        x[3] = x[0] + x1;
        y[3] = y[0] + y1;
        double area = triangle_area(x[0], y[0], x[1], y[1], x[2], y[2]);
        area *= 2;
        printf("Case %d: %d %d %.0f\n", test++, x[3], y[3], area);
    }


    return 0;
}
