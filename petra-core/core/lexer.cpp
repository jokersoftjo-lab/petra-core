#include "lexer.hpp"

#include <sstream>
#include <map>

Lexer::Lexer(const std::string& src)
    : source(src)
{
}

std::vector<Token> Lexer::tokenize() {

    std::vector<Token> tokens;

    std::map<std::string, TokenType> keywords = {

        // English
        {"MOV", TokenType::MOV},
        {"ADD", TokenType::ADD},
        {"PRINT", TokenType::PRINT},
        {"HALT", TokenType::HALT},

        // Arabizi
        {"hrk", TokenType::MOV},
        {"add", TokenType::ADD},
        {"ktb", TokenType::PRINT},
        {"stop", TokenType::HALT}
    };

    std::stringstream ss(source);

    std::string word;

    while (ss >> word) {

        if (keywords.count(word)) {

            tokens.push_back({
                keywords[word],
                word
                });
        }
        else if (word[0] == 'R') {

            tokens.push_back({
                TokenType::REGISTER,
                word
                });
        }
        else {

            bool isNumber = true;

            for (char c : word) {

                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }

            if (isNumber) {

                tokens.push_back({
                    TokenType::NUMBER,
                    word
                    });
            }
            else {

                tokens.push_back({
                    TokenType::UNKNOWN,
                    word
                    });
            }
        }
    }

    return tokens;
}