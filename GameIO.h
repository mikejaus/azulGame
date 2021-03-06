// This class handles I/O for the game, and calls methods in Game_manager.
// The purpose of this class is to easily switch between taing input from stdin
// and taking input from a save file.
//
// Author - Issa Chanzi <s3783615@student.rmit.edu.au>

#ifndef GAME_IO_H
#define GAME_IO_H

#include <iostream>
#include <fstream>
#include <string>

#include "Game_manager.h"

class GameIO
{
    public:
        GameIO (
            Game_manager * game,
            std::istream * in,
            std::ostream * out);

        // TODO delete this method
        void doRound ();

        void doTurn ();

        void addPlayer ();
        void addPlayer (int numPlayers);

        Game_manager * loadGame ();
        void saveGame (std::string filename);
        void print_final();
        void printGameState ();

    private:
        Game_manager * game;
        std::istream * in;
        std::ostream * out;

        std::string doCmd ();
        std::string turnCmd ();
        void saveCmd ();

        void printFactories ();
        void printScore (Player * player);
        void printMozaic (Player * player);


        void printTurn ();
        Turn * getTurn ();

        bool moreInput ();

        //TEMPORARY
        bool checkColour(char colour, int row);



        static std::ostream * devNull;
};


#endif
