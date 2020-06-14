//
// Created by student on 12.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "Hand.h"
#include "Unit/Unit.h"
#include <sstream>

BOOST_AUTO_TEST_SUITE(HandTestSuite)

    BOOST_AUTO_TEST_CASE(HandParameterConstructorTest) {
        Hand hand;
        for (unsigned int i = 0; i < 5; i++) {
            BOOST_TEST_CHECK(hand.getCard(i) != nullptr);
        }
    }

    BOOST_AUTO_TEST_CASE(HandGetCardsInfo) {
        Hand hand;
        std::ostringstream sout;

        for (unsigned int i = 0; i < 5; i++) {
            sout << "Zycie: " << hand.getCard(i)->getHealth() << " ";
            sout << "Atak: " << hand.getCard(i)->getAttackPower() << " ";
            sout << "Specjalna umiejestnosc: " << hand.getCard(i)->getAbility() << " ";
            sout << std::endl;
        }
        BOOST_CHECK_EQUAL(hand.getCardsInfo(), sout.str());


    }


BOOST_AUTO_TEST_SUITE_END()