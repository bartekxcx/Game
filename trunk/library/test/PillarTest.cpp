//
// Created by student on 12.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Pillar/Pillar.h"
#include "Pillar/GreenPillar.h"
#include <sstream>

BOOST_AUTO_TEST_SUITE(PillarTestSuite)

    BOOST_AUTO_TEST_CASE(PillarParameterConstructorTest) {
        GreenPillar pillar(1);
        BOOST_CHECK_EQUAL(pillar.getHealth(), 15);
        BOOST_CHECK_EQUAL(pillar.getAbility(), "Green");
        BOOST_CHECK_EQUAL(pillar.getPosition(), 1);
    }

    BOOST_AUTO_TEST_CASE(getPillarInfoTest) {
        GreenPillar pillar(1);
        std::ostringstream sout;
        sout<<"Zycie: "<<15<<" ";
        sout<<"Specjalna umiejetnosc: "<<"Green";
        sout<<"Pozycja: "<<1<<std::endl;
        BOOST_CHECK_EQUAL(pillar.getPillarInfo(), sout.str());
    }

    BOOST_AUTO_TEST_CASE(setPillarHealthTest) {
        GreenPillar pillar(1);
        pillar.setHealth(12);
        BOOST_CHECK_EQUAL(pillar.getHealth(), 12);

    }




BOOST_AUTO_TEST_SUITE_END()