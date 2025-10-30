#pragma once

#include<string>
#include<vector>
#include"Token.h"

class Lexer{
public:
    explicit Lexer(const std::string& source);
    std::vector<Token> scanTokens();

private:
    const std::string source;
    std::vector<Token> tokens;


}