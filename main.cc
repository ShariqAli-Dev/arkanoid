#include "raylib.h"
#include <stdio.h>

#define PLAYER_MAX_LIFE 5
#define LINES_OF_BRICKS 5
#define BRICKS_PER_LINE 20

typedef struct
{
    Vector2 position;
    Vector2 size;
    int life;
} Player;

typedef struct
{
    Vector2 position;
    Vector2 speed;
    int radius;
    bool active;
} Ball;

typedef struct
{
    Vector2 position;
    bool active;
} Brick;

typedef const unsigned int Resolution;

static Resolution screen_width = 800;
static Resolution screen_height = 600;

static bool game_over = false;
static bool pause = false;

static Player player = {0};
static Ball ball = {0};
static Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE] = {0};
static Vector2 brick_size = {0};

static void InitGame(void);
static void UpdateGame(void);
static void DrawGame(void);
static void UpdateDrawFrame(void);
static void UnloadGame(void);

int main()
{
    InitWindow(screen_width, screen_height, "arkanoid");
    InitGame();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }

    UnloadGame();
    CloseWindow();
    return 0;
}

void InitGame(void)
{
    brick_size = (Vector2){(float)GetScreenWidth() / BRICKS_PER_LINE, 40.0f};

    // init player
    player.position = (Vector2){screen_width / 2, screen_height * 7 / 8};
    player.size = (Vector2){(float)GetScreenWidth() / 10.0f, 20.0f};
    player.life = PLAYER_MAX_LIFE;
}

void UpdateGame(void)
{
    if (!game_over)
    {

        if (IsKeyPressed('P'))
        {
            pause = !pause;
        }
        if (!pause)
        {
            if (IsKeyDown(KEY_LEFT))
                player.position.x -= 5;
            if (player.position.x - player.size.x / 2 <= 0)
                player.position.x = 0 + player.size.x / 2;
            if (IsKeyDown(KEY_RIGHT))
                player.position.x += 5;
            if (player.position.x + player.size.x / 2 >= GetScreenWidth())
                player.position.x = GetScreenWidth() - player.size.x / 2;
        }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            game_over = false;
        }
    }
}

void DrawGame(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (!game_over)
    {
        DrawRectangle(player.position.x - player.size.x / 2, player.position.y - player.size.y / 2, player.size.x, player.size.y, BLACK);

        if (pause)
        {
            DrawText("GAME PAUSED", screen_width / 2 - MeasureText("GAME PAUSED", 40) / 2, screen_height / 2 - 40, 40, GRAY);
        }
    }
    else
    {

        DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);
    }

    DrawFPS(GetScreenWidth() - 90, 10);
    EndDrawing();
}

void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}

void UnloadGame(void) {}