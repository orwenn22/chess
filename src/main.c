#include <stdio.h>
#include <raylib.h>

#include "Board.h"


int main() {
    InitWindow(512, 512, "chess lol");
    SetTargetFPS(60);

    InitPawnTextures();

    Board* game_board = MakeBoard();


    while (!WindowShouldClose()) {
        UpdateBoard(game_board);

        BeginDrawing();
        ClearBackground(RED);
        DrawBoard(game_board);
        EndDrawing();
    }

    DeleteBoard(game_board);

    FinitPawnTextures();
    CloseWindow();
    return 0;
}
