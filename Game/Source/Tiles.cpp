#include "App.h"
#include "Tiles.h"
#include "Render.h"
#include "Textures.h"
#include "LevelManager.h"

#include "iostream"

Tiles::Tiles()
{
    floor_01 = { 27, 88, 24, 24 };
    floor_02 = { 27, 200, 24, 24 };
    wall_01 = { 27, 32, 24, 24 };
    wall_02 = { 77, 32, 24, 24 };
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
            if (*(arr + row * i + j) == 1) app->render->DrawTexture(spriteSheet, j * 24, i * 24, &floor_01);
            else if  (*(arr + row * i + j) == 2) app->render->DrawTexture(spriteSheet, j * 24, i * 24, &floor_02);
            else if (*(arr + row * i + j) == 3) app->render->DrawTexture(spriteSheet, j * 24, i * 24, &wall_01);
            else if (*(arr + row * i + j) == 4) app->render->DrawTexture(spriteSheet, j * 24, i * 24, &wall_02);
        }
    }
}

void Tiles::OnCollision(Collider* c1, Collider* c2)
{

}