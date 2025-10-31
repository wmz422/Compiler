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
    int start=0;
    int cur=0;
    int line=1;

    void scanToken();//读一个字符
    char getChar();//每调用一次,就把扫描指示器当前所指示的源程序字符送入变量ch,然后把扫描器前推一个字符位置.
    void retract();//把扫描指示器回退一个字符位置
    void addToken(TokenType type);//将生成的token加入vector
    void lookup();//检查关键字返回addtoken对应的tokentype，或者是标识符号
    //void number();//处理数字
};