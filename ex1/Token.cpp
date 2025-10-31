#include"Token.h"
#include <sstream>

//switch实现
std::string tokenTypeToString(TokenType t){
    switch (t) {
		case TokenType::VOID: return "VOID";
		case TokenType::INT: return "INT";
		case TokenType::FLOAT: return "FLOAT";
		case TokenType::DOUBLE: return "DOUBLE";
		case TokenType::IF: return "IF";
		case TokenType::ELSE: return "ELSE";
		case TokenType::FOR: return "FOR";
		case TokenType::DO: return "DO";
		case TokenType::WHILE: return "WHILE";
		case TokenType::RETURN: return "RETURN";
		case TokenType::BREAK: return "BREAK";


		case TokenType::LEFT_PAREN: return "LEFT_PAREN";
		case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
		case TokenType::LEFT_BRACE: return "LEFT_BRACE";
		case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
		case TokenType::COMMA: return "COMMA";
		case TokenType::DOT: return "DOT";
		case TokenType::MINUS: return "MINUS";
		case TokenType::PLUS: return "PLUS";
		case TokenType::SEMICOLON: return "SEMICOLON";
		case TokenType::SLASH: return "SLASH";
		case TokenType::COMMENT: return "COMMENT";
		case TokenType::STAR: return "STAR";
		case TokenType::QUESTION: return "QUESTION";
		case TokenType::COLON: return "COLON";

		case TokenType::BANG: return "BANG";
		case TokenType::BANG_EQUAL: return "BANG_EQUAL";
		case TokenType::EQUAL: return "EQUAL";
		case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
		case TokenType::GREATER: return "GREATER";
		case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
		case TokenType::LESS: return "LESS";
		case TokenType::LESS_EQUAL: return "LESS_EQUAL";
		case TokenType::ARROW: return "ARROW";
		case TokenType::PLUS_PLUS: return "PLUS_PLUS";
		case TokenType::MINUS_MINUS: return "MINUS_MINUS";
		case TokenType::AMPERSAND: return "AMPERSAND";
		case TokenType::AMPERSAND_AMPERSAND: return "AMPERSAND_AMPERSAND";
		case TokenType::PIPE: return "PIPE";
		case TokenType::PIPE_PIPE: return "PIPE_PIPE";

		case TokenType::IDENTIFIER: return "IDENTIFIER";
		case TokenType::STRING_LITERAL: return "STRING_LITERAL";
		case TokenType::NUMBER_LITERAL: return "NUMBER_LITERAL";
		case TokenType::CHAR_LITERAL: return "CHAR_LITERAL";

		case TokenType::END_OF_FILE: return "END_OF_FILE";
		case TokenType::ERROR: return "ERROR";
	}
	return std::string("UNKNOWN");
}

Token::Token(TokenType type,std::string lexeme,int line):type(type), lexeme(lexeme), line(line){}
//类外定义构造函数

std::string Token::toString() const{//这里const保证不对类内属性进行任何修改
    std::ostringstream oss;
    oss<<'<'<<tokenTypeToString(type)<<','<<lexeme<<"> "<< " [line=" << line << "]";
    return  oss.str();
}
