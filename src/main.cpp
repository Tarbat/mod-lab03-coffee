// Copyright 2022 GHA Test Team
#include "Automata.h"
#include <locale>
#include <codecvt>

int main() {
    std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());

    Automata automata;
    automata.on();
    automata.getMenu();
    automata.coin(20);
    automata.choice(2);
    automata.check();
    automata.cook();
    automata.finish();
    automata.off();
    return 0;
}
