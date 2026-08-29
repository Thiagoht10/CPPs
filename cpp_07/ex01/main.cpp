#include "iter.hpp"

int main(void)
{
    int array[3] = {15, 16, 18};
    const int   array_c[3] = {9, 10, 11};

    iter(array, 3, print);

    iter(array_c, 3, show);

    return 0;
}