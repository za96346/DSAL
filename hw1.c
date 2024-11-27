#include "stdio.h"

int first(int x) {
    if (x < 5) {
        return 3 * x;
    }
    return 2 * first(x - 5) + 7;
}

int second(int x, int y) {
    if (x < y) {
        return -3;
    }
    return second(x - y, y + 3) + y;
}

int third(int x, int y) {
    if (x > y) {
        return -1;
    } else if (x == y) {
        return 1;
    }
    return x * third(x + 1, y);
}

double fourth(int n) {
    int i = 1;
    double result = 0.0;
    for(i = 1; i <= n; i++) {
        result += (double)1 / i;
    }
    return result;
}


int main() {
    printf("%.10f", fourth(3));
    return 0;
}