//
// Created by student on 12.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "Unit/Unit.h"
#include "Unit/Warrior.h"
#include <sstream>
#include <Unit/Archer.h>

BOOST_AUTO_TEST_SUITE(UnitTestSuite)

    BOOST_AUTO_TEST_CASE(UnitParameterConstructorTest) {
        Warrior unit(2);
        BOOST_CHECK_EQUAL(unit.getHealth(), 7);
        BOOST_CHECK_EQUAL(unit.getAttackPower(), 3);
        BOOST_CHECK_EQUAL(unit.getAbility(), "Warrior");
        BOOST_CHECK_EQUAL(unit.getPosition(), 2);
        BOOST_CHECK_EQUAL(unit.isOnBoard(), false);

    }

    BOOST_AUTO_TEST_CASE(UnitSettersTest) {
        Unit unit(4);
        unit.setHealth(12);
        unit.setPosition(2);
        unit.setOnBoard();
        BOOST_CHECK_EQUAL(unit.getHealth(),12);
        BOOST_CHECK_EQUAL(unit.getPosition(), 2);
        BOOST_CHECK_EQUAL(unit.isOnBoard(), true);

    }




    BOOST_AUTO_TEST_CASE(UnitGetInfoTest) {
        Archer unit(4);
        std::ostringstream sout;
        sout<<"Zycie: "<<6<<" ";
        sout<<"Atak: "<<3<<" ";
        sout<<"Specjalna umiejestnosc: "<<"Archer"<<" ";
        sout<<std::endl;
        BOOST_CHECK_EQUAL(unit.get_unit_info(),sout.str());
    }







    BOOST_AUTO_TEST_SUITE_END()
