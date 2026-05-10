#pragma once

#include <vector>
#include <string>

#include "token.hpp"

class Lexer {

public:

    Lexer(const std::string& source);

    std::vector<Token> tokenize();

private:

    std::string source;
};