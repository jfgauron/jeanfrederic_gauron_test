#ifndef OVERLAP_LIB_H_
#define OVERLAP_LIB_H_

#include <algorithm>

bool lines_overlap(int x1, int x2, int x3, int x4) {
    // normalize data so that x1 is always the smallest value
    // and that x3 is smaller than x4
    if (x1 > x2)
        std::swap(x1, x2);
    if (x3 > x4)
        std::swap(x3, x4);
    if (x1 > x3) {
        std::swap(x1, x3);
        std::swap(x2, x4);
    }
    return x2 >= x3;
}

#endif // OVERLAP_LIB_H_