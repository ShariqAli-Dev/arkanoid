#include "raylib.h"

static const unsigned int screen_width = 800;
static const unsigned int screen_height = 600;

static void init_game(void);
static void unload_game(void);
static void update_draw_frame(void);
static void update_game(void);
static void draw_game(void);

int main()
{
    InitWindow(screen_width, screen_height, "Conway's Game of Life");
    init_game();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        update_draw_frame();
    }

    unload_game();
    CloseWindow();
    return 0;
}

void init_game(void) {}

void unload_game(void) {}

void draw_game(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Your really cool game", 10, 10, 30, GREEN);
    DrawFPS(GetScreenWidth() - 90, 10);
    EndDrawing();
}

void update_game(void) {}

void update_draw_frame(void)
{
    update_game();
    draw_game();
}
