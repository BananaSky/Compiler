#pragma once
#include "Utilities/IO/IO.hpp"
#include "Utilities/Parse/Parse.hpp"
#include "Utilities/Syntax/Symbols.hpp"
#include "Utilities/Syntax/Token.hpp"
#include "Utilities/Lex/Lex.hpp"
#include "Utilities/Lex/Seperate.hpp"
#include "Utilities/Lex/Language.hpp"
#include "Utilities/Generator/Generator.hpp"
#include <iostream>

namespace Compiler
{
    using namespace Parse;
    using namespace Lex;
    using namespace Syntax;
    using namespace Gen;

    std::vector<Tokens> tokenPass(std::vector<std::string>);
    std::vector<SymbolicTokens> symbolicPass(std::vector<Tokens> tokens);

    const Terms keywords  = {"if", "then", "else"};
    const Terms operators = {"+", "-", "*", "/", "="};

    const Language test_language({std::make_tuple(keywords, "keyword"), std::make_tuple(operators, "operator")},
                                 {std::make_tuple(digits, "int"),       std::make_tuple(alphas, "identifier")});
}
