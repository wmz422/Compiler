#include <unordered_map>
#include <cctype>
#include"Lexer.h"

Lexer::Lexer(const std::string& source):source(source){};

char Lexer::getChar(){
    return source[cur++];
}

void Lexer::retract(){
    cur--;
}

void Lexer::addToken(TokenType type){
    std::string temp;
    temp=source.substr(start,cur-start);
    tokens.push_back(Token(type,temp,line));
}

void Lexer::lookup(){
    TokenType type;
    std::string temp=source.substr(start,cur-start);
    static const std::unordered_map<std::string, TokenType> keywords = {
		{"void", TokenType::VOID},
		{"int", TokenType::INT},
		{"float", TokenType::FLOAT},
		{"double", TokenType::DOUBLE},
		{"if", TokenType::IF},
		{"else", TokenType::ELSE},
		{"for", TokenType::FOR},
		{"do", TokenType::DO},
		{"while", TokenType::WHILE},
		{"return", TokenType::RETURN}
	};
    bool find=false;
    for(const auto &it:keywords){
        if(it.first==temp){
            find=true;
            type=it.second;
            addToken(type);
        }
    }
    if(find==false){
        addToken(TokenType::IDENTIFIER);
    }
}

std::vector<Token> Lexer::scanTokens(){
    while(source[cur]!=EOF){
        scanToken();
    }
    addToken(TokenType::END_OF_FILE);
    return tokens;
}

void Lexer::scanToken(){
    char c=getChar();
    char next;
    switch(c){
        //单字符
        case '(' : addToken(TokenType::LEFT_PAREN); break;
		case ')' : addToken(TokenType::RIGHT_PAREN); break;
		case '{' : addToken(TokenType::LEFT_BRACE); break;
		case '}' : addToken(TokenType::RIGHT_BRACE); break;
		case ',' : addToken(TokenType::COMMA); break;
		case '.' : addToken(TokenType::DOT); break;
        case ';' : addToken(TokenType::SEMICOLON); break;
		case '*' : addToken(TokenType::STAR); break;
		case '?' : addToken(TokenType::QUESTION); break;
		case ':' : addToken(TokenType::COLON); break;

        //单字符或者双字符
        case '!' : 
            next=getChar();
            if(next=='=')
                addToken(TokenType::BANG_EQUAL);
            else{
                retract();
                addToken(TokenType::BANG);
            }
            break;
        case '=':
            next=getChar();
            if(next=='=')
                addToken(TokenType::EQUAL_EQUAL);
            else{
                retract();
                addToken(TokenType::EQUAL);
            }
            break;
        case '>':
            next=getChar();
            if(next=='=')
                addToken(TokenType::GREATER_EQUAL);
            else{
                retract();
                addToken(TokenType::GREATER);
            }
            break;
        case '<':
            next=getChar();
            if(next=='=')
                addToken(TokenType::LESS_EQUAL);
            else{
                retract();
                addToken(TokenType::LESS);
            }
            break;
        case '+':
            next=getChar();
            if(next=='+')
                addToken(TokenType::PLUS_PLUS);
            else{
                retract();
                addToken(TokenType::PLUS);
            }
            break;
        case '-':
            next=getChar();
            if(next=='-')
                addToken(TokenType::MINUS_MINUS);
            else if(next=='>')
                addToken(TokenType::ARROW);
            else{
                retract();
                addToken(TokenType::MINUS);
            }
            break;
        case '&':
            next=getChar();
            if(next=='&')
                addToken(TokenType::AMPERSAND_AMPERSAND);
            else{
                retract();
                addToken(TokenType::AMPERSAND);
            }
            break;
        case '|':
            next=getChar();
            if(next=='|')
                addToken(TokenType::PIPE_PIPE);
            else{
                retract();
                addToken(TokenType::PIPE);
            }
            break;
        case '/':
            next=getChar();
            if(next=='//')
                addToken(TokenType::SLASH_SLASH);
            else{
                retract();
                addToken(TokenType::SLASH);
            }
            break;

        //空字符
        case ' ':
            break;
        case '\n':
            line++;//回车记行数
            break;
        
        //处理标识符或关键字或者数字
        default:
            if(isalpha(c)){
                while(isalnum(c=getChar())){
                    ;
                }
                retract();
                lookup();
            }
            if(isnumber(c)){
                while(isnumber(c=getChar())){
                    ;
                }
                retract();
                addToken(TokenType::NUMBER_LITERAL);
            }
            
    }
    start=cur;//更新token开始位置

}