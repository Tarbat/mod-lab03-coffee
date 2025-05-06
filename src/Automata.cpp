// Copyright 2022 GHA Test Team
#include "Automata.h"
#include <string>
#include <vector>
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
    currChoice = -1;
    menu = { "Горячая вода", "Чай", "Кофе", "Горячий шоколад"};
    price = { 5, 15, 20, 30 };
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Автомат включен" << std::endl;
    } else {
        std::cout << "Некорректное состояние или запрос" << std::endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Возврашена сдача в размере: " << cash << std::endl;
        cash = 0;
        std::cout << "Автомат выключен" << std::endl;
    } else {
        std::cout << "Некорректное состояние или запрос" << std::endl;
    }
}

void Automata::coin(int coin) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        if (coin < 0) {
            std::cout << "Неверная сумма ввода" << std::endl;
            coin = 0;
        }
        std::cout << "Баланс пополнен на: " << coin << std::endl;
        cash += coin;
        std::cout << "Текущий баланс: " << cash << std::endl;
    } else {
        std::cout << "Некорректное состояние или запрос" << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << "Меню:" << std::endl;
    for (int i = 0; i < menu.size(); i++) {
        std::cout << menu[i] << ": " << price[i] << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int choice) {
    if (state == ACCEPT) {
        state = CHECK;
        if (choice > menu.size()) {
            std::cout << "Нет напитка с данным номером" << std::endl;
            state == ACCEPT;
        }
        currChoice = choice;
    } else {
        std::cout << "Некорректное состояние или запрос" << std::endl;
    }
}

void Automata::check() {
    if (state == CHECK) {
        state = CHECK;
            if (cash >= price[currChoice]) {
                std::cout << "Баланс достаточный для покупки" << std::endl;
            } else {
                std::cout << "Пополните баланс" << std::endl;
            }
    } else {
        std::cout << "Некорректное состояние или запрос" << std::endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        std::cout << "Сеанс остановлен" << std::endl;
        std::cout << "Возврашена сдача в размере: " << cash << std::endl;
        cash = 0;
    } else {
        std::cout << "Некорректное состояние или запрос" << std::endl;
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
       std::cout << "Процесс готовки" << std::endl;
    } else {
        std::cout << "Некорректное состояние или запрос" << std::endl;
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        std::cout << "Ваш напиток " << menu[currChoice]
            << " Готов" << std::endl;
        cash -= price[currChoice];
        std::cout << "Текущий баланс: " << cash << std::endl;
        currChoice = -1;
    } else {
        std::cout << "Некорректное состояние или запрос" << std::endl;
    }
}
