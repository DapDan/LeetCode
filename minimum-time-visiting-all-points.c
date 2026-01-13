int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int i, res;

    res = 0;
    for(i = 1; i < pointsSize; i++) {
        int dx = abs(points[i][0] - points[i - 1][0]);
        int dy = abs(points[i][1] - points[i - 1][1]);

        if(dx > dy)
            res += dx;
        else
            res += dy;
    }

    return res;
}