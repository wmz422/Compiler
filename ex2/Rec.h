#pragma once
#include "../ex1/Lexer.h"
#include<vector>

class Rec{
public:
    bool rec();//外部调用功能的函数
    Rec(std::vector<Token> tokens);//构造函数
private:
    const std::vector<Token> tokens;//词法分析结果
    int cur;//cur指针
    int len;//tokens长度
    TokenType cur_type=tokens[cur].type;//当前type

    bool adv();//cur加
    
    bool fun1();//S->
    bool fun2();//E->
    bool fun3();//E,->
    bool fun4();//T->
    bool fun5();//T,->
    bool fun6();//M->
    bool fun7();//A->
    bool fun8();//F->
    bool fun9();//V->
};

