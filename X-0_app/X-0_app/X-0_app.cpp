#define _CRT_SECURE_NO_WARNINGS //Disable security warnings; used for scanf

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

#define player1 1
#define player2 2


void matrix_init(char matrix[][3]) {
    char c = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = c;
            c++;
        }
    }
}

void matrix_print(char matrix[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c  ", matrix[i][j]);
        }
        printf("\n\n");
    }
}

bool symbol_check(char matrix[][3], char poz) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] == poz) {
                return true;
            }
        }
    }
    return false;
}

void symbol_insertion(char matrix[][3], char poz, int player) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] == poz) {
                if (player == 1) {
                    matrix[i][j] = 'X';
                }
                else {
                    matrix[i][j] = 'O';
                }
            }
        }
    }
}

int game_win(char matrix[][3]) {
    int i;

    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) { //diag principala
        if (matrix[1][1] == 'X') {
            //printf("Jucatorul 1 a castigat");
            return 1;
        }
        else {
            if (matrix[1][1] == 'O') {
                //printf("Jucatorul 2 a castigat");
                return 2;
            }
        }
    }


    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) { //diag secundara
        if (matrix[1][1] == 'X') {
            //printf("Jucatorul 1 a castigat");
            return 1;
        }
        else {
            if (matrix[1][1] == 'O') {
                //printf("Jucatorul 2 a castigat");
                return 2;
            }
        }
    }

    for (i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) { //linii
            if (matrix[i][1] == 'X') {
                //printf("Jucatorul 1 a castigat");
                return 1;
            }
            else {
                if (matrix[i][1] == 'O') {
                    //printf("Jucatorul 2 a castigat");
                    return 2;
                }
            }
        }

        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) { //coloane
            if (matrix[1][i] == 'X') {
                //printf("Jucatorul 1 a castigat");
                return 1;
            }
            else {
                if (matrix[1][i] == 'O') {
                    //printf("Jucatorul 2 a castigat");
                    return 2;
                }
            }
        }
    }

    //printf("Nu exista castigator");
    return 0;
}

void game_print(char matrix[][3]) {
    system(CLEAR_SCREEN);
    printf("Tabla de joc:\n\n");
    //matrix_init(matrix);
    matrix_print(matrix);
}

void game_play() {
    char matrix[3][3];
    matrix_init(matrix);

    //int player;
    char poz;
    int turn = 1;

    while (1) {
        game_print(matrix);
        if (turn % 2 != 0) { //first player turn
            while (1) {
                printf("\nPlayer 1 move:");
                scanf("%c", &poz);
                if (poz == '\n') {
                    scanf("%c", &poz);
                }
                if (symbol_check(matrix, poz)) {
                    //player = 1;
                    symbol_insertion(matrix, poz, player1);
                    turn++;
                    break;
                }
                else {
                    printf("\nPozitie incorecta!!!");
                }
            }
        }
        else {
            while (1) {
                printf("\nPlayer 2 move:");
                scanf("%c", &poz);
                if (poz == '\n') {
                    scanf("%c", &poz);
                }
                if (symbol_check(matrix, poz)) {
                    symbol_insertion(matrix, poz, player2);
                    turn++;
                    break;
                }
                else {
                    printf("\nPozitie incorecta!!!");
                }
            }
        }

        if (game_win(matrix) == 1) {
            printf("\nJucatorul 1 a castigat\n\n");
            matrix_print(matrix);
            return;
        }

        if (game_win(matrix) == 2) {
            printf("\nJucatorul 2 a castigat\n\n");
            matrix_print(matrix);
            return;
        }
           
        /*if (game_win(matrix) == 0) {
            printf("\nNu exista castigator\n");
            matrix_print(matrix);
            return;
        }
              
        if (turn == 10) {
            return;
        }*/

        if (turn == 10) {
            printf("Nu exista castigator");
            return;
        }
    }
}

int main()
{
    game_play();
    return 0;
}


//X  0  X
//0  0  X
//X  X  0
//
//1  2  3
//4  5  6
//7  8  9

