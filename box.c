#include <stdio.h>
#include <unistd.h>
#include <math.h>

char get_char(float angle) {
    angle = fmod(angle, 360.0);
    if (angle < 0) angle += 360.0;

    int sector = (int)((angle + 22.5) / 45) % 8;
    switch (sector) {
        case 0: case 4: return '-';
        case 1: case 5: return '/';
        case 2: case 6: return '|';
        case 3: case 7: return '\\';
        default: return '-';
    }
}

int main() {
    float angle = 0.0;
    while (1) {
        // char top = get_char(angle);
        // char right = get_char(angle + 90);
        // char bottom = get_char(angle + 180);
        // char left = get_char(angle + 270);

        printf("\033[H\033[J");  // Clear screen
        // printf(" %c \n", top);
        //printf("%c   %c\n", left, right);
        //printf(" %c \n", bottom);
        fflush(stdout);

        // angle = fmod(angle + 15, 360);
        usleep(100000);  // 100ms delay
    }
    return 0;
}
