//
// Created by student on 12.06.2020.
//
#include <boost/test/unit_test.hpp>
#include <Play.h>
#include "Player/Player.h"
#include "Battlefield.h"
#include "Hand.h"
#include "Pillar/PillarsArray.h"


BOOST_AUTO_TEST_SUITE(PlayerTestSuite)

    BOOST_AUTO_TEST_CASE(PlayerParametrConstructorTest) {
        Play *play = new Play(2, "Wojtus", "Macius");
        Player player("Imie", play);
        BOOST_CHECK_EQUAL(player.getNickname(), "Imie");
        BOOST_CHECK_EQUAL(player.getPlayerPlay(), play);
        BOOST_TEST_CHECK(player.getPlayerBoard() != nullptr);
        BOOST_TEST_CHECK(player.getPlayerHand() != nullptr);
        BOOST_TEST_CHECK(player.getPlayerPillars() != nullptr);
        delete play;
    }

    BOOST_AUTO_TEST_CASE(PlayerGetSetPlayerActionsTest) {
        Play *play = new Play(2, "Wojtus", "Macius");
        Player player("Lolek", play);
        player.setPlayerActions(3);
        BOOST_CHECK_EQUAL(player.getPlayerActions(), 3);
        delete play;
    }

    BOOST_AUTO_TEST_CASE(PlayerGetSetPlayerChoiceTest) {
        Play *play = new Play(2, "Wojtus", "Macius");
        Player player("Lolek", play);
        player.setChoice(3);
        BOOST_CHECK_EQUAL(player.getChoice(), 3);
        delete play;
    }

    BOOST_AUTO_TEST_CASE(PlayerGetPlayerInfoTest) {
        Play *play = new Play(2, "Wojtus", "Macius");
        Player player("Lolek", play);
        std::ostringstream sout;
        sout << "Lolek" << std::endl;
        sout << player.getPlayerHand()->getCardsInfo();
        sout << player.getPlayerBoard()->getCardsInfo();
        sout << player.getPlayerPillars()->getPillarsInfo();
        BOOST_CHECK_EQUAL(player.getPlayerInfo(), sout.str());
        delete play;
    }


BOOST_AUTO_TEST_SUITE_END()