#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 800;
    
    const float falling = 5.0f;
    
    float speed = 100.f;

    InitWindow(screenWidth, screenHeight, "moonshot");
    
    Vector2 spaceshipCords = { (float)200, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        if((IsKeyPressed(KEY_SPACE)) && spaceshipCords.y > 200) {
            spaceshipCords.y -= speed;
        }else if((!IsKeyPressed(KEY_SPACE)) && spaceshipCords.y <= 500){
            spaceshipCords.y += falling;
        }
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            
            DrawCircleV(spaceshipCords, 50, WHITE);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}