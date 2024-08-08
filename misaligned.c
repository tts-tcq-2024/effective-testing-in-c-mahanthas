#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0, count = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if (j == 2) { // Introducing a defect: skip printing for index 2
                continue;
            }
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
            assert(majorColor[i] != NULL);
            assert(minorColor[j] != NULL);
            count++;
        }
    }
    return count;
}

int main() {
    int result = printColorMap();
    assert(result == 25); // This should fail because of the defect
    printf("All is well (maybe!)\n");
    return 0;
}
