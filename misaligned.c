#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if (j == 2) { // Introducing a defect: skip printing for index 2
                continue;
            }
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
            // Ensure correct color mapping
            assert(majorColor[i] != NULL);
            assert(minorColor[j] != NULL);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    // Adjust the assertion to account for the defect (expected result should be less than 25)
    assert(result == 25); // This will fail because of the defect
    printf("All is well (maybe!)\n");
    return 0;
}
