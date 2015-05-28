#include "get-k-min-element.h"

// complexity O(nlogn)
EMT_TYPE get_k_min_element(EMT_TYPE * emts, int size, int k){
    PRIORITY_QUEUE pq = init(100);
    int i;

    for (i = 0; i < size; i++)
        insert(emts[i], pq);

    for ( i = 1; i < k; i++ )
        delete_min(pq);

    return delete_min(pq);
}
