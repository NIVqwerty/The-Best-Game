//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <Заголовок>\n
//! @brief      <Подзаголовок>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <Автор>, <Год> (<Имя> <Почта>)
//! @date       <Дата>
//!
//! @par        Протестировано
//!           - (TODO: список платформ)
//!
//! @todo     - (TODO: список ближайших планов по этому файлу)
//!
//! @bug      - (TODO: список найденных ошибок в этом файле)
//!
//! @par        История изменений файла
//!           - Версия 0.01 Alpha
//!             - Только что созданный файл
//!
//}=======================================================================

#include "TXLib.h"

int main()
    {
    txCreateWindow (800, 600);
    //шар
    int ball_x = 400;
    int ball_vx = 10;
    int ball_y = 300;
    int ball_vy = 10;
    int ball_r = 15;
    int ball_t =6;

    //игрок 1
    int gamer1_x = 20;
    int gamer1_y = 180;
    int gamer1_w = 15;
    int gamer1_h =150;
    //--------------------
    //игрок 2
    int gamer2_x = 770;
    int gamer2_y = 180;
    int gamer2_w = 15;
    int gamer2_h =150;

    txSetColor (TX_WHITE, ball_t);
    txSetFillColor (TX_BLACK);

    while(true)
    {
        txClear();
        txBegin();
        txCircle(ball_x, ball_y, ball_r);   //рисуем шарик
        txSetColor (TX_BLUE,ball_t);
        txRectangle(gamer1_x, gamer1_y, gamer1_x+gamer1_w, gamer1_y+gamer1_h);//рисуем игроков
        txSetColor (TX_RED,ball_t);
        txRectangle(gamer2_x, gamer2_y, gamer2_x+gamer1_w, gamer2_y+gamer2_h);
        txSetColor(TX_WHITE,ball_t);
        txEnd();
        // управление шаром
        ball_x = ball_x + ball_vx;
        ball_y = ball_y + ball_vy;

        if(ball_x>txGetExtentX()-ball_r-ball_t || ball_x<0+ball_r+ball_t)
        {
            ball_vx = -ball_vx;
        }
        if(ball_y>txGetExtentY()-ball_r-ball_t || ball_y<0+ball_r+ball_t)
        {
            ball_vy = -ball_vy;
        }
    //---------------------------
    //Управление игрок 1
    if(GetAsyncKeyState('W'))
    {
    gamer1_y -= 15;
    }

    if(GetAsyncKeyState('S'))
    {
    gamer1_y += 15;
    }
    //-----------
    //Управление игрок 2

    if(GetAsyncKeyState(VK_UP))
    {
    gamer2_y -= 15;
    }

    if(GetAsyncKeyState(VK_DOWN))
    {
    gamer2_y += 15;
    }
    //-----------
    //Взаимодействие объектов
    if(ball_x-ball_r-ball_t < gamer1_x+gamer1_w && ball_x+ball_r+ball_t > gamer1_x &&
    ball_y-ball_r > gamer1_y && ball_y+ball_r <gamer1_y+gamer1_h)
    {

        ball_vx = -ball_vx;

    }

    if(ball_x-ball_r-ball_t < gamer2_x+gamer2_w && ball_x+ball_r+ball_t > gamer2_x &&
    ball_y-ball_r > gamer2_y && ball_y+ball_r <gamer2_y+gamer2_h)
    {

        ball_vx = -ball_vx;

    }

    //-------------------


        txSleep(10);
    }

    txTextCursor (false);
    return 0;
    }

