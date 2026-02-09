#include <iostream>

#include "./infix.h"
#include "./prefix.h"
#include "./postfix.h"

int main() {
    Infix in;
    std::string infix_to_prefix = "(A+B)*C-D+F";
    std::string infix_to_postfix = "a+b*(c^d-e)";
    
    std::cout << "\t ----------------- Infix Conversion ----------------- \t" << std::endl;
    std::cout << "\t Given Infix : |" << infix_to_prefix << "| \t Convert To Prefix : |" << in.InfixToPrefix(infix_to_prefix) << "|" << std::endl;
    std::cout << "\t Given Infix : |" << infix_to_postfix << "| \t Convert To Postfix : |" << in.InfixToPostfix(infix_to_postfix) << "|" << std::endl;


    Prefix prefix;
    std::string prefix_to_infix = "*+PQ-MN";
    std::string prefix_to_postfix = "-AB*+DEF";

    std::cout << "\t ----------------- Prefix Conversion ----------------- \t" << std::endl;
    std::cout << "\t Given Prefix : |" << prefix_to_infix << "| \t Convert To Infix : |" << prefix.PrefixToInfix(prefix_to_infix) << "|" << std::endl;
    std::cout << "\t Given Prefix : |" << prefix_to_postfix << "| \t Convert To Postfix : |" << prefix.PrefixToPostfix(prefix_to_postfix) << "|" << std::endl;

    Postfix postfix;
    std::string postfix_to_infix = "AB-DE+F*/";
    std::string postfix_to_prefix = "AB-DE+F*/";

    std::cout << "\t ----------------- Postfix Conversion ----------------- \t" << std::endl;
    std::cout << "\t Given Postfix : |" << prefix_to_infix << "| \t Convert To Infix : |" << postfix.PostfixToInfix(postfix_to_infix) << "|" << std::endl;
    std::cout << "\t Given Postfix : |" << prefix_to_postfix << "| \t Convert To Prefix : |" << postfix.PostfixToPrefix(postfix_to_prefix) << "|" << std::endl;

    return 0;
}