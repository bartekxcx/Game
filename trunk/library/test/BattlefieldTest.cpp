//
// Created by student on 12.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "Battlefield.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include <Unit/Unit.h>
#include <Unit/Archer.h>
#include <Unit/Medic.h>
#include <Unit/Thief.h>
#include <Unit/Warrior.h>

BOOST_AUTO_TEST_SUITE(BattlefieldTestSuite)

    BOOST_AUTO_TEST_CASE(BattlefieldParameterConstructorTest) {
        Battlefield battlefield;
        for (unsigned int i = 0; i < 5; i++) {
            BOOST_TEST_CHECK(battlefield.getCard(i) == nullptr);
        }
    }

    BOOST_AUTO_TEST_CASE(BattlefieldGetCardTest) {
        Battlefield battlefield;
        UnitPtr card = std::make_shared<Archer>(2) ;
        battlefield.setCard(2, card);
        BOOST_CHECK_EQUAL(battlefield.getCard(2), card);
        BOOST_CHECK_EQUAL(battlefield.getCard(2)->isOnBoard(), true);
    }


    BOOST_AUTO_TEST_CASE(BattlefieldGetCardsInfo) {
        Battlefield battlefield;
        std::ostringstream sout;
        UnitPtr card;
            srand( time( NULL ) );
            for(int i=0; i<5; i++)
            {
                int x=(std::rand()%4)+1;
                if(x==1) card=std::make_shared<Archer>( i);
                else if (x==2) card=std::make_shared<Medic>(i);
                else if(x==3) card=std::make_shared<Thief>( i);
                else card=std::make_shared<Warrior>( i);
                battlefield.setCard(i,card);
            }

        for (unsigned int i = 0; i < 5; i++) {
            sout << "Zycie: " << battlefield.getCard(i)->getHealth() << " ";
            sout << "Atak: " << battlefield.getCard(i)->getAttackPower() << " ";
            sout << "Specjalna umiejestnosc: " << battlefield.getCard(i)->getAbility() << " ";
            sout << std::endl;
        }
        BOOST_CHECK_EQUAL(battlefield.getCardsInfo(), sout.str());


    }


BOOST_AUTO_TEST_SUITE_END()