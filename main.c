#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_board(char **board, int m, int n){
    printf("  ");
    for(int i = 0; i < n; i++){
        printf("%d ", i+1);
    }
    printf("\n");
    for(int i = 0; i < m; i++){
        printf("%d ", i+1);
        for(int j = 0; j < n; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m, n;
    printf("Введите кол-во строк: ");
    scanf("%d", &m);
    printf("Введите кол-во столбцов: ");
    scanf("%d", &n);

    char **board = (char **) malloc(m * sizeof(char *));
    for(int i = 0; i < m; i++){
        board[i] = (char *) malloc(n * sizeof(char));
        for(int j = 0; j < n; j++){
            if(j == 0) board[i][j] = 'X';
            else if(j == n-1) board[i][j] = 'O';
            else board[i][j] = '.';
        }
    }

    int run = 1;
    print_board(board, m, n);
    int player = 1;
    int row, col;
    char *text;
    while(run){
        printf("Ход игрока %d\n", player);
        if(player == 1){
            printf("Выберите X: ");
            scanf("%d", &row);
            row--;
            printf("На какой столбец вы хотите походить: ");
            scanf("%d", &col);
            col--;
            text = board[row];
            while(strstr(text, "X") == &text[col]){
                printf("Ход не возможен\n");
                print_board(board, m, n);
                printf("На какой столбец вы хотите походить: ");
                scanf("%d", &col);
                col--;
            }
            if(col >= (strstr(text, "O") - text)){
                printf("Ход не возможен\n");
            }else{
                player = 2;
                text[strstr(text, "X") - text] = '.';
                text[col] = 'X';
            }
            print_board(board, m, n);
        }else{
            printf("Выберите O: ");
            scanf("%d", &row);
            row--;
            printf("На какой столбец вы хотите походить: ");
            scanf("%d", &col);
            col--;
            text = board[row];
            while(strstr(text, "O") == &text[col]){
                printf("Ход не возможен\n");
                print_board(board, m, n);
                printf("На какой столбец вы хотите походить: ");
                scanf("%d", &col);
                col--;
            }
            if(col <= (strstr(text, "X") - text)){
                printf("Ход не возможен\n");
            }else{
                player = 1;
                text[strstr(text, "O") - text] = '.';
                text[col] = 'O';
            }
            print_board(board, m, n);
        }
    }
    for(int i = 0; i < m; i++){
        free(board[i]);
    }
    free(board);
    return 0;
    
}