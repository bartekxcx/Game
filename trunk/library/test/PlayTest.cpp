//
// Created by student on 12.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Play.h"
#include <sstream>
#include <Player/ComputerPlayer.h>
#include <Player/HumanPlayer.h>
#include <cstddef>

using namespace std;

BOOST_AUTO_TEST_SUITE(PlayTestSuite)

    BOOST_AUTO_TEST_CASE(PlayParameterConstructorTest) {
        Play play(0,"Wojtus","Macius");
        Play play2(1,"Wojtus","Macius");
        Play play3(2,"Wojtus","Macius");
        for (unsigned int i = 0; i < 2; i++) {
            BOOST_TEST_REQUIRE(play.getPlayer() != nullptr);
            PlayerPtr player = play.getPlayer();
            BOOST_TEST_CHECK(dynamic_pointer_cast<ComputerPlayer>(player) != nullptr);
                play.setWhoseTurn();
        }

        PlayerPtr player = play2.getPlayer();
        BOOST_TEST_CHECK(dynamic_pointer_cast<HumanPlayer>(player) != nullptr);
                play2.setWhoseTurn();
        player = play2.getPlayer();
        BOOST_TEST_CHECK(dynamic_pointer_cast<ComputerPlayer>(player) != nullptr);


        for (unsigned int i = 0; i < 2; i++) {
            player = play3.getPlayer();
            BOOST_TEST_CHECK(dynamic_pointer_cast<HumanPlayer>(player) != nullptr);
                play3.setWhoseTurn();
        }



    }



BOOST_AUTO_TEST_SUITE_END()