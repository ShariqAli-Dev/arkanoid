#include "raylib.h"

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
static Vector2 brickSize = {0};

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

void InitGame(void) {}

void UnloadGame(void) {}

void DrawGame(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Your really cool game", 10, 10, 30, GREEN);
    DrawFPS(GetScreenWidth() - 90, 10);
    EndDrawing();
}

void UpdateGame(void) {}

void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}
