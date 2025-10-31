#pragma once

#include<iostream>
#include <cstdint>
#include <string>

enum class TokenType{
    // Keywords
    VOID,
    INT,
    FLOAT,
    DOUBLE,
    IF,
    ELSE,
    FOR,
    DO,
    WHILE,
    RETURN,

    // Single-character tokens
    LEFT_PAREN,     // (
    RIGHT_PAREN,    // )
    LEFT_BRACE,     // {
    RIGHT_BRACE,    // }
    COMMA,          // ,
    DOT,            // .
    MINUS,          // -
    PLUS,           // +
    SEMICOLON,      // ;
    SLASH,          // /
    STAR,           // *
    QUESTION,       // ?
    COLON,          // :

    // One or two character tokens
    BANG,           // !
    BANG_EQUAL,     // !=
    EQUAL,          // =
    EQUAL_EQUAL,    // ==
    GREATER,        // >
    GREATER_EQUAL,  // >=
    LESS,           // <
    LESS_EQUAL,     // <=
    ARROW,          // ->
    PLUS_PLUS,      // ++
    MINUS_MINUS,    // --
    AMPERSAND,      // &
    AMPERSAND_AMPERSAND, // &&
    PIPE,           // |
    PIPE_PIPE,      // ||

    // Literals
    IDENTIFIER,     // 标识符
    STRING_LITERAL, // 字符串
    NUMBER_LITERAL, // 数字
    CHAR_LITERAL,   // 字符

    // Others
    END_OF_FILE,    // 文件结束 (EOF)
    ERROR           // 错误 (用于报告词法错误)
};

// 把enums class转化成字符串
std::string tokenTypeToString(TokenType t);

struct Token{
    TokenType type;
    std::string lexeme;//提取出的字符
    int line;

    Token(TokenType type,std::string lexeme,int line);//构造函数
    std::string toString() const;//输出token结果为字符串
};
