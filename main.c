#include <stdlib.h>
#include <stdio.h>

struct board {
    int sand[21][21];
};

void print_array(struct board *input) {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            set_color(input->sand[i][j]);
            printf("%d ", input->sand[i][j]);
            reset_color();
        }
        printf("\n");
    }
}

void fill_array(struct board *input, int num) {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            input->sand[i][j] = num;
        }
    }
}

void reset_color() {
    printf("\033[0m");
}

void set_color(int num) {
    if (num == 1) {
        printf("\033[0;31m"); //red
    }
    if (num == 2) {
        printf("\033[0;33m"); //yellow
    }
    if (num == 3) {
        printf("\033[0;32m"); //green
    }
}

void drop_sand(struct board *input) {
    input->sand[10][10]++;
}

void receap(struct board *input) {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (input->sand[i][j] > 3) {
                input->sand[i][j] -= 4;
                if (i+1 < 21 && j < 21 && i+1 >= 0 && j >= 0) {
                    input->sand[i+1][j]++;
                }
                if (i-1 < 21 && j < 21 && i-1 >= 0 && j >= 0) {
                    input->sand[i-1][j]++;
                }
                if (i < 21 && j+1 < 21 && i >= 0 && j+1 >= 0) {
                    input->sand[i][j+1]++;
                }
                if (i < 21 && j-1 < 21 && i >= 0 && j-1 >= 0) {
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
        usleep(50000);
    }
}
