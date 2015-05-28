#include "get-k-min-element.h"


int main(){


    EMT_TYPE emts[] = {32, 21, 16, 24, 31, 19, 68, 65, 26, 13};
    int size = sizeof(emts) / sizeof(emts[0]);
    int k = 10;
    EMT_TYPE k_min = get_k_min_element(emts, size, k);

    printf("%d is the %d min element...\n", k_min, k);
    return 0;
}
