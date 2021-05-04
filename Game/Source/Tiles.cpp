#include "App.h"
#include "Tiles.h"
#include "Render.h"
#include "Textures.h"
#include "LevelManager.h"

#include "iostream"

Tiles::Tiles()
{
    floor_01 = { 89, 335, 116, 116 };
    floor_02 = { 89, 799, 116, 116 };
    wall_01 = { 89, 103, 116, 116 };
    wall_02 = { 320, 103, 116, 116 };
}

Tiles::~Tiles()
{
}

bool Tiles::Start()
{
   spriteSheet = app->tex->Load("Assets/Textures/tileSheet.png");

    return true;
}




bool Tiles::CleanUp()
{
    return true;
}

void Tiles::DrawArray(int* arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(arr + row * i + j) == 1) app->render->DrawTexture(spriteSheet, j * 116, i * 116, &floor_01);
            else if  (*(arr + row * i + j) == 2) app->render->DrawTexture(spriteSheet, j * 116, i * 116, &floor_02);
            else if (*(arr + row * i + j) == 3) app->render->DrawTexture(spriteSheet, j * 116, i * 116, &wall_01);
            else if (*(arr + row * i + j) == 4) app->render->DrawTexture(spriteSheet, j * 116, i * 116, &wall_02);
        }
    }
}
