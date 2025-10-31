#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"

int main(int argc, char** argv) {
	std::string source;

	if (argc > 1) {
		std::ifstream in(argv[1]);//找到文件
		if (!in) {
			std::cerr << "Could not open file: " << argv[1] << std::endl;
			return 1;
		}
		std::ostringstream ss;
		ss << in.rdbuf();//从外存到内存
		source = ss.str();
	} else {
        std::cerr<<"please enter a file name"<<std::endl;
	}

	Lexer lexer(source);
	auto tokens = lexer.scanTokens();
	for (const auto& t : tokens) std::cout << t.toString() << std::endl;

	return 0;
}
