// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1) {
    Automata automata;
    ASSERT_EQ(automata.getState(), OFF);
}

TEST(task, test2) {
    Automata automata;
    automata.on();
    ASSERT_EQ(automata.getState(), WAIT);
}

TEST(task, test3) {
    Automata automata;
    automata.on();
    automata.cook();
    testing::internal::CaptureStdout();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Некорректное состояние или запрос"), std::string::npos);
}

TEST(task, test4) {
    Automata automata;
    automata.on();
    automata.coin(30);
    ASSERT_EQ(automata.getState(), ACCEPT);
}

TEST(task, test5) {
    Automata automata;
    automata.on();
    automata.coin(30);
    automata.coin(30);
    ASSERT_EQ(automata.getState(), ACCEPT);
}

TEST(task, test6) {
    Automata automata;
    automata.on();
    automata.coin(30);
    automata.choice(1);
    ASSERT_EQ(automata.getState(), CHECK);
}

TEST(task, test7) {
    Automata automata;
    automata.on();
    automata.coin(30);
    automata.choice(1);
    automata.check();
    ASSERT_EQ(automata.getState(), CHECK);
    testing::internal::CaptureStdout();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Баланс достаточный для покупки"), std::string::npos);
}

TEST(task, test8) {
    Automata automata;
    automata.on();
    automata.coin(30);
    automata.choice(1);
    automata.check();
    automata.cook();
    ASSERT_EQ(automata.getState(), COOK);
}

TEST(task, test9) {
    Automata automata;
    automata.on();
    automata.coin(30);
    automata.choice(1);
    automata.cancel();
    ASSERT_EQ(automata.getState(), WAIT);
    testing::internal::CaptureStdout();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Возврашена сдача в размере: 30"), std::string::npos);
}

TEST(task, test10) {
    Automata automata;
    automata.on();
    automata.coin(30);
    automata.choice(1);
    automata.check();
    automata.cook();
    automata.finish();
    automata.off();
    ASSERT_EQ(automata.getState(), OFF);
}
