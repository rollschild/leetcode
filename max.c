#include <stdio.h>
int main() {
    int i;
    int count = 0;
    for(i = 1; i <= 5; i<<=1) {
        ++count;
    }
    printf("%d\n", i);
    return 0;
}
