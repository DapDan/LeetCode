int mySqrt(int x) {
    if (x == 0)
        return 0;

    double y = x;
    double z = (y + (x / y)) / 2;

    while (fabs(y - z) >= 0.01) {
        y = z;
        z = (y + (x / y)) / 2;
    }

    return (int)z;
}