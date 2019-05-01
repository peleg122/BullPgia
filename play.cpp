//
// Created by amir on 17-Apr-19.
//

/**
 * Implementation of bull-pgia game
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include "play.hpp"
#include "calculate.hpp"
#include <string>


using std::string;

namespace bullpgia {
    uint play(Chooser& chooser, Guesser& guesser, uint length, uint maxTurns) {
        const uint TECHNICAL_VICTORY_TO_GUESSER = 0;
        const uint TECHNICAL_VICTORY_TO_CHOOSER = maxTurns+1;

        string choice = chooser.choose(length);
        if (choice.length()!=length)       // Illegal choice
            return TECHNICAL_VICTORY_TO_GUESSER;
        guesser.startNewGame(length);  // tell the guesser that a new game starts now
        uint indexOfTurn;
        for (indexOfTurn=0; indexOfTurn<maxTurns; ++indexOfTurn) {

            string guess = guesser.guess();
            cout<<"Guess: "<<guess<<endl;
            if (guess.length()!=length)  // Illegal guess
                return TECHNICAL_VICTORY_TO_CHOOSER;
            if (guess==choice) {
                cout<<"You Won!"<<endl;
                return indexOfTurn + 1;
            } else {
                cout<<"Choise "<<choice<<endl;
                auto reply = calculateBullAndPgia(choice, guess);
                guesser.learn(reply); // tell the guesser how many bull and pgia were in its latest guess
                //cout<<"done with learn"<<endl;
            }
        }
        return TECHNICAL_VICTORY_TO_CHOOSER;  // Guesser could not guess in time
    }
}