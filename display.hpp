#pragma once

#include <iostream>
#include <iomanip>
#include <cctype>
#include "setup.hpp"
#include "sevseg.hpp"
#include "color.hpp"


void dispBanner()
{ //will be moved to separate header later
    std::cout << blue_fg;
    std::cout << R"(
    ##     ##  ##  ##    ## ########  ######  ##      ## ######## ######## ########  ######## ########
    ###   ###  ##  ###   ## ##       ##    ## ##  ##  ## ##       ##       ##     ## ##       ##     ##
    #### ####  ##  ####  ## ##       ##       ##  ##  ## ##       ##       ##     ## ##       ##     ##
    ## ### ##  ##  ## ## ## ######    ######  ##  ##  ## ######   ######   ########  ######   ########
    ##     ##  ##  ##  #### ##             ## ##  ##  ## ##       ##       ##        ##       ##   ##
    ##     ##  ##  ##   ### ##       ##    ## ##  ##  ## ##       ##       ##        ##       ##    ##
    ##     ##  ##  ##    ## ########  ######   ###  ###  ######## ######## ##        ######## ##     ##)";
    std::cout << reset << "\n";
}

void dispFlagCounter()
{
    writeBuf << white_fg << R"(                (_)               )" << "\n";
    writeBuf << white_fg << R"(   _ __ ___  _ _ __   ___ ___ )" << "\n";
    writeBuf << white_fg << R"(  | '_ ` _ \| | '_ \ / _ / __|)" << "\n";
    writeBuf << white_fg << R"(  | | | | | | | | | |  __\__ \)" << "\n";
    writeBuf << white_fg << R"(  |_| |_| |_|_|_| |_|\___|___/)" << "\n";
    writeBuf << reset;

    flagDisp.update("      ");
}

void dispControls()
{
    writeBuf << "\n";
    writeBuf << white_fg << "  ↑, ←, ↓, → : " << "\n";
    writeBuf << white_fg << "       OR      Movement" << "\n";
    writeBuf << white_fg << "  H, J, K, L : " << "\n";
    writeBuf << white_fg << "  S or ENTER : Sweep" << "\n";
    writeBuf << white_fg << "  F or SPACEBAR : Toggle Flag" << "\n";
}

void dispVictoryOrDefeat()
{
    writeBuf << "\n";
    COLOR col = gameState == VICTORY ? green_fg : red_fg;

    writeBuf << col << R"(  __   _____  _   _ )" << "\n";
    writeBuf << col << R"(  \ \ / / _ \| | | |)" << "\n";
    writeBuf << col << R"(   \ V / (_) | |_| |)" << "\n";
    writeBuf << col << R"(    |_| \___/ \___/ )" << "\n";

    writeBuf << "\n";

    if (gameState == VICTORY)
    {

        writeBuf << col << R"(  __      _____ _  _ _ )" << "\n";
        writeBuf << col << R"(  \ \    / /_ _| \| | |)" << "\n";
        writeBuf << col << R"(   \ \/\/ / | || .` |_|)" << "\n";
        writeBuf << col << R"(    \_/\_/ |___|_|\_(_))" << "\n";
    }

    else
    {
        writeBuf << col << R"(   _    ___  ___ ___ _ )" << "\n";
        writeBuf << col << R"(  | |  / _ \/ __| __| |)" << "\n";
        writeBuf << col << R"(  | |_| (_) \__ \ _||_|)" << "\n";
        writeBuf << col << R"(  |____\___/|___/___(_))" << "\n";
    }
}

void setGameMode()
{
    int ch;
    do
    {
        dispBanner();
        std::cout << std::setw(30);
        std::cout << yellow_fg << "Maximise Terminal or press F11 for the optimal experience" << reset;
        std::cout << "\n"
                  << "\n";
        std::cout << std::setw(30);
        std::cout << white_fg << "Choose Game Mode:\n";
        std::cout << std::setw(30);
        std::cout << green_fg << "1. Beginner\n";
        std::cout << std::setw(30);
        std::cout << yellow_fg << "2. Intermediate\n";
        std::cout << std::setw(30);
        std::cout << red_fg << "3. Expert\n";
        std::cout << std::setw(30);
        std::cout << blue_fg << "4. Custom\n\n";
        std::cout << "                       ";
        std::cin >> ch;

        if (ch < 1 || ch > 4)
        {
            std::cout << red_fg << "Invalid Choice. Try again\n";
            auto c = getch();
        }
        else
            gameMode = (GAME_MODE)ch;
        system("clear");

    } while (ch < 1 || ch > 4);
}

void getQuickClearSettings()
{
    char ch;
    int choice;
    do
    {
        dispBanner();
        std::cout << "\n";
        std::cout << yellow_fg << 
        R"(            Quick Clear : If a cell with a number on it is already revealed,
                         and it's neighbours have been flagged with the same number,
                         then all tiles adjacent to this cell are also sweeped.
            
            Enable Quick Clear? )";
        
        std::cout << white_fg << "[" << green_fg <<"Y" << white_fg << " / " << red_fg << "N" << white_fg << "] : " << reset;

        std::cin >> ch;

        ch = std::tolower(ch);

        if (!(ch == 'y' || ch == 'n'))
        {
            std::cout << red_fg << "Invalid Choice. Try again\n";
            auto c = getch();
        }
        else
            QUICKCLEAR = std::tolower(ch) == 'y' ? true : false;
        
        system("clear");


    } while (!(ch == 'y' || ch == 'n'));
    
}