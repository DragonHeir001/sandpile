#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

void drop_sand(struct board *input) {
    input->sand[2][2]++;
}

void receap(struct board *input, int i, int j) {
    if (input->sand[i][j] == 10) {
        input->sand[i][j] = 0;
        input->sand[i+1][j]++;
        input->sand[i-1][j]++;
        input->sand[i][j+1]++;
        input->sand[i][j-1]++;
    }
}

int main() {
    struct board sandpiles;
    fill_array(&sandpiles, 0);
    while (1) {
        printf ("\n");
        drop_sand(&sandpiles);
        receap(&sandpiles, 2, 2);
        print_array(&sandpiles);
        sleep(1);
    }
}
