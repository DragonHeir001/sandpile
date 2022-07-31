#include <stdlib.h>
#include <stdio.h>

struct board {
    int sand[5][5];
};

void print_array(struct board *input) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", input->sand[i][j]);
        }
        printf("\n");
    }
}

void fill_array(struct board *input, int num) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            input->sand[i][j] = num;
        }
    }
}

int main() {
    struct board sandpiles;
    fill_array(&sandpiles, 0);
    print_array(&sandpiles);
}
