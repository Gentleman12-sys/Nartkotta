#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void print_board(char board[MAX_ROWS][MAX_COLS], int m, int n) {
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i+1);
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Введите количество строк: ");
    scanf("%d", &m);
    printf("Введите количество столбцов: ");
    scanf("%d", &n);

    char board[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                board[i][j] = 'X';
            }
            else if (j == n-1) {
                board[i][j] = 'O';
            }
            else {
                board[i][j] = '.';
            }
        }
    }

    print_board(board, m, n);

    int player = 1;
    int run = 1;
    while (run) {
        bool stopX[MAX_ROWS] = {0};
        bool stopO[MAX_ROWS] = {0};
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'X' && board[i][1] == 'O') {
                stopX[i] = true;
            }
            if (board[i][n-1] == 'O' && board[i][n-2] == 'X') {
                stopO[i] = true;
            }
        }
        bool flagX = true, flagO = true;
        for (int i = 0; i < m; i++) {
            flagX &= stopX[i];
            flagO &= stopO[i];
        }

        if (flagO) {
            printf("Победил X\n");
            break;
        }
        if (flagX) {
            printf("Победил O\n");
            break;
        }

        printf("Ход игрока %d\n", player);

        int row, col;
        char* text;
        if (player == 1) {
            printf("Выберите X: ");
            scanf("%d", &row);
            printf("На какой столбец вы хотите походить: ");
            scanf("%d", &col);

			col--;

            text = board[row-1];
            while (col == strchr(text, 'X') - text) {
                printf("Ход невозможен\n");
                print_board(board, m, n);
                printf("На какой столбец вы хотите походить: ");
                scanf("%d", &col);
            }
            if (col >= strchr(text, 'O') - text) {
                printf("Ход невозможен\n");
            }
            else {
                player = 2;
                text[strchr(text, 'X') - text] = '.';
                text[col] = 'X';
            }
            print_board(board, m, n);
        }
        else if (player == 2) {
            printf("Выберите O: ");
            scanf("%d", &row);
            printf("На какой столбец вы хотите походить: ");
            scanf("%d", &col);

			col--;

            text = board[row-1];
            while (col == strchr(text, 'O') - text) {
                printf("Ход невозможен\n");
                print_board(board, m, n);
                printf("На какой столбец вы хотите походить: ");
                scanf("%d", &col);
            }
            if (col <= strchr(text, 'X') - text) {
                printf("Ход невозможен\n");
            }
            else {
                player = 1;
                text[strchr(text, 'O') - text] = '.';
                text[col] = 'O';
            }
            print_board(board, m, n);
        }
	}
	return 0;
}