#include"Rec.h"

Rec::Rec(std::vector<Token> tokens) : tokens(tokens) {}

bool Rec::rec(){
    cur=0;
    len=tokens.size();//存储的元素数量
    return fun1();
}

bool Rec::fun1(){//S->
    TokenType type=tokens[cur].type;
    if(type==TokenType::IDENTIFIER){
        
    }
}   

bool Rec::fun2(){//E->

}    

bool Rec::fun3(){//E,->

}    

bool Rec::fun4(){//T->

}    

bool Rec::fun5(){//T,->

}    

bool Rec::fun6(){//M->

}    

bool Rec::fun7(){//A->

}    

bool Rec::fun8(){//F->

}    

bool Rec::fun9(){//V->

}    

