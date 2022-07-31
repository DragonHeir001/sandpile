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

void drop_sand(struct board *input) {
    input->sand[2][2]++;
}

void receap(struct board *input) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (input->sand[i][j] > 3) {
                input->sand[i][j] -= 4;
                if (i+1 < 5 && j < 5 && i+1 >= 0 && j >= 0) {
                    input->sand[i+1][j]++;
                }
                if (i-1 < 5 && j < 5 && i-1 >= 0 && j >= 0) {
                    input->sand[i-1][j]++;
                }
                if (i < 5 && j+1 < 5 && i >= 0 && j+1 >= 0) {
                    input->sand[i][j+1]++;
                }
                if (i < 5 && j-1 < 5 && i >= 0 && j-1 >= 0) {
                    input->sand[i][j-1]++;
                }
            }
        }
    }
}

int main() {
    struct board sandpiles;
    fill_array(&sandpiles, 0);
    while (1) {
        system("clear");
        drop_sand(&sandpiles);
        receap(&sandpiles);
        receap(&sandpiles);
        receap(&sandpiles);
        receap(&sandpiles);
        print_array(&sandpiles);
        usleep(300000);
    }
}
