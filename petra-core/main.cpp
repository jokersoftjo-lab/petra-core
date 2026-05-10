#include <iostream>

#include "core/lexer.hpp"

int main() {

    std::string code =
        "hrk R1 10\n"
        "ktb R1\n"
        "stop\n";

    Lexer lexer(code);

    auto tokens = lexer.tokenize();

    for (auto& token : tokens) {

        std::cout
            << (int)token.type
            << " : "
            << token.value
            << std::endl;
    }

    return 0;
}