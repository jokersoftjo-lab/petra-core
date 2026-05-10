#pragma once

#include <string>

enum class TokenType {

    MOV,
    ADD,
    PRINT,
    HALT,

    REGISTER,
    NUMBER,

    UNKNOWN
};

struct Token {

    TokenType type;
    std::string value;
};