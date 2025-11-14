#include"Rec.h"

Rec::Rec(std::vector<Token> tokens) : tokens(tokens) {}

bool Rec::rec(){
    cur=0;
    cur_type=tokens[cur].type;
    len=tokens.size();//存储的元素数量
    return fun1();
}

bool Rec::adv(){//先不考虑越界
    cur++;
    if(cur>=len)
        return false;
    cur_type=tokens[cur].type;//更新cur_type
    return true;
}

bool Rec::fun1(){//S->
    if(cur_type!=TokenType::IDENTIFIER)
            return false;
    if(fun9()==false)//递归v
        return false;
    if(cur_type!=TokenType::EQUAL)//=
        return false;
    adv();
    if(fun2()==false)//递归E
        return false;
    return true;
}   

bool Rec::fun2(){//E->
    if((cur_type!=TokenType::IDENTIFIER)&&(cur_type!=TokenType::LEFT_PAREN))
        return false;
    if(fun4()==false)
        return false;
    if(fun3()==false)
        return false;
    return true;
}    

bool Rec::fun3(){//E,->
    if((cur_type!=TokenType::PLUS)&&(cur_type!=TokenType::MINUS)){
        if((cur_type==TokenType::RIGHT_PAREN)||(cur_type==TokenType::END_OF_FILE)){//EOF当作#
            return true;
        }
        else
            return false;
    }
    if(fun7()==false)
        return false;
    if(fun4()==false)
        return false;
    return fun3();     
}    

bool Rec::fun4(){//T->
    if((cur_type!=TokenType::IDENTIFIER)&&(cur_type!=TokenType::LEFT_PAREN))
            return false;
    if(fun8()==false)
        return false;
    if(fun5()==false)
        return false;
    return true;
}    

bool Rec::fun5(){//T,->
    if((cur_type!=TokenType::STAR)&&(cur_type!=TokenType::SLASH)){
        if((cur_type==TokenType::RIGHT_PAREN)||(cur_type==TokenType::END_OF_FILE)||(cur_type==TokenType::PLUS)||(cur_type==TokenType::MINUS)){//EOF当作#
            return true;
        }
        else
            return false;
    }
    if(fun6()==false)
        return false;
    if(fun8()==false)
        return false;
    return fun5();
}    

bool Rec::fun6(){//M->
    if((cur_type!=TokenType::STAR)&&(cur_type!=TokenType::SLASH)){
        return false;
    }
    adv();
    return true;
}    

bool Rec::fun7(){//A->
    if((cur_type!=TokenType::PLUS)&&(cur_type!=TokenType::MINUS)){
        return false;
    }
    adv();
    return true;
}    

bool Rec::fun8(){//F->
    if((cur_type!=TokenType::LEFT_PAREN)&&(cur_type!=TokenType::IDENTIFIER))
        return false;
    if(cur_type==TokenType::LEFT_PAREN){
        adv();
        if(fun2()==false)
            return false;
        if(cur_type!=TokenType::RIGHT_PAREN)
            return false;
    }
    adv();
    return true;
}    

bool Rec::fun9(){//V->
    if(cur_type!=TokenType::IDENTIFIER)
        return false;
    adv();
    return true;
}    

