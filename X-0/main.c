#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

void matrix_init ( char matrix[][3] ){
    char c = '1';
    for ( int i = 0; i < 3; i++ ){
        for ( int j = 0; j < 3; j++ ){
            matrix[i][j] = c;
            c++;
        }
    }
}

void matrix_print ( char matrix[][3] ){
    for( int i = 0; i < 3; i++ ){
        for( int j = 0; j < 3; j++){
            printf("%s  ", matrix[i][j]);
        }
        printf("\n\n");
    }
}

bool symbol_check ( char matrix[][3], char poz ) {
    int i, j;
    for( i = 0; i < 3; i++){
        for( j = 0; j < 3; j++ ){
            if ( matrix[i][j] == poz ){
                return true;
            }
        }
    }
    return false;
}

void symbol_insertion ( char matrix[][3], char poz, int player ) {
    int i, j;
    for( i = 0; i < 3; i++){
        for( j = 0; j < 3; j++ ){
            if ( matrix[i][j] == poz ){
                if( player == 1 ){
                    matrix[i][j] = 'X';
                }else{
                    matrix[i][j] = 'O';
                }
            }
        }
    }
}

bool game_win ( char matrix[][3] ) {
    int i;
    for( i = 0; i < 3; i++ ){
        if( matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] ){
            if( matrix[i][1] == 'X' ){
                printf("Jucatorul 1 a castigat");
            }else{
                if( matrix[i][1] == 'O' ){
                    printf("Jucatorul 2 a castigat");
                }
            }
            return true;
        }

        if( matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] ){
            if( matrix[1][i] == 'X' ){
                printf("Jucatorul 1 a castigat");
            }else{
                if( matrix[1][i] == 'O' ){
                    printf("Jucatorul 2 a castigat");
                }
            }
            return true;
        }

        if( matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] ){
            if( matrix[1][1] == 'X' ){
                printf("Jucatorul 1 a castigat");
            }else{
                if( matrix[1][1] == 'O' ){
                    printf("Jucatorul 2 a castigat");
                }
            }
            return true;
        }

        if( matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] ){
            if( matrix[i][1] == 'X' ){
                printf("Jucatorul 1 a castigat");
            }else{
                if( matrix[i][1] == 'O' ){
                    printf("Jucatorul 1 a castigat");
                }
            }
            return true;
        }

        if( matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] ){
            if( matrix[1][1] == 'X' ){
                printf("Jucatorul 1 a castigat");
            }else{
                if( matrix[1][1] == 'O' ){
                    printf("Jucatorul 2 a castigat");
                }
            }
            return true;
        }
    }
    printf("Nu exista castigator");
    return false;
}

void game_print( char matrix[][3] ){
    printf("Tabla de joc:\n");
    matrix_init( matrix );
    matrix_print( matrix );
}

int game_play ( char matrix[][3] ){
    int player;
    char poz;
    int turn = 1;

    if( turn % 2 != 0 ){
        while ( 1 ){
            printf("Player 1 move:");
            scanf("%d", &poz);
            if( symbol_check( matrix, poz ) == 0 ){
                return 0;
            }else{
                return 1;
                player = 1;
                symbol_insertion ( matrix, poz, player );
                turn++;
            }
        }
    }else{
        while ( 1 ){
            printf("Player 2 move:");
            scanf("%d", &poz);
            if( symbol_check( matrix, poz ) == 0 ){
                return 0;
            }else{
                return 1;
                player = 2;
                symbol_insertion ( matrix, poz, player );
                turn++;
            }
        }
    }

    if( turn == 10 ){
        system( CLEAR_SCREEN );
        game_win( matrix );
    }
}



int main()
{
    char matrix[3][3];
    game_play( matrix );
    return 0;
}


//X  0  X
//0  0  X
//X  X  0
//
//1  2  3
//4  5  6
//7  8  9

