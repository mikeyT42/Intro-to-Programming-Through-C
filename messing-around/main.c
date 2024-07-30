#include <stdio.h>

int keystrokes(char input[]);

int main(void) {
    char in[] = "Hello, World!\n";
    int key = keystrokes(in);

    printf("keystrokes = %i\n", key);
}

// -----------------------------------------------------------------------------
int keystrokes(char input[]) {
    int keystrokes = 0;
    for (int index = 0; input[index] != '\n'; index++) {
        keystrokes++;
    }

    return keystrokes;
}
