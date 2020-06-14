//
// Created by student on 12.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Pillar/PillarsArray.h"
#include <sstream>

BOOST_AUTO_TEST_SUITE(PillarsArrayTestSuite)

    BOOST_AUTO_TEST_CASE(PillarsArrayParameterConstructorTest) {
        PillarsArray pillars_array;
        for(unsigned int i =0 ; i<5;i++)
        {
            BOOST_TEST_CHECK(pillars_array.getPillar(i)!= nullptr);
        }
    }

    BOOST_AUTO_TEST_CASE(PillarsArrayGetPillarInfo) {
        PillarsArray pillars_array;
        std::ostringstream sout;

        for(unsigned int i =0 ; i<5;i++)
        {
            sout<<"Zycie: "<<pillars_array.getPillar(i)->getHealth()<<" ";
            sout<<"Specjalna umiejetnosc: "<<pillars_array.getPillar(i)->getAbility()<<std::endl;

        }
        BOOST_CHECK_EQUAL(pillars_array.getPillarsInfo(),sout.str());

    }





BOOST_AUTO_TEST_SUITE_END()