#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

struct BoardStruct;


enum PawnType {
    PawnType_None = 0,
    PawnType_Pawn,
    PawnType_Tower,
    PawnType_Knight,
    PawnType_Crazy,
    PawnType_Queen,
    PawnType_King
};

enum PawnTeam {
    PawnTeam_None = 0,
    PawnTeam_White,
    PawnTeam_Black
};


typedef struct BoardStruct {
    unsigned char* cells;       //grille avec toutes les pièces (encodage : bits 7 à 4 : équipe ; bits 3 à 0 : type de pièce)
    unsigned char* possible_moves;  //corespond à la grille. 1 = le pion sélectionné peut bouger sur cette case. 0 : non
    enum PawnTeam current_turn; //Indique c'est au tour de quel joueur
    char selected_cell;         //Index de la case actuellmement sélectionné (-1 si aucune)
    int overred_x, overred_y;   //Position de la case survolé par la souris

} Board;


void InitPawnTextures();
void FinitPawnTextures();

Board* MakeBoard();
void DeleteBoard(Board* b);
void UpdateBoard(Board* b);
void DrawBoard(Board* b);

unsigned char BoardGetPawn(Board* b, int x, int y);
void BoardSetPawn(Board* b, int x, int y, enum PawnTeam team, enum PawnType type);

#endif //CHESS_BOARD_H
