#include "Compiler.hpp"


int main()
{
    using namespace Compiler;

    Terms keywords  = {"return"};
    Terms operators = {"+", "-", "*", "/", "=", ")", "(", ":", ","};

    Lex::LanguageTermSets term_set;
    term_set.push_back(std::make_tuple(keywords,  "keyword"));
    term_set.push_back(std::make_tuple(operators, "operator"));

    Lex::LanguageLexers lexer_set = {
        LanguageLexer(digits, "int", "literal", 3),
        LanguageLexer(startswith("\""), "string", "string", 1),
        LanguageLexer(alphas, "identifier", "identifier", 3)};

    Lex::Language test_language(term_set, lexer_set);

    auto content         = readFile     ("../input/input.txt");
    auto tokens          = tokenPass    (content, test_language); 
    auto symbolic_tokens = symbolicPass (tokens);
    auto joined_tokens   = join         (symbolic_tokens);

    for(auto jt : joined_tokens)
    {
        std::cout << "Joined Token " << jt.type << "  " << jt.sub_type << std::endl;
    }
    
    auto statementresults = buildStatements(joined_tokens);

    std::vector<std::string> output;
    output.push_back("#include \"std/std.hpp\"");
    output.push_back("int main(){");
    if (std::get<0>(statementresults))
    {
        std::cout << "Successfully parsed " << std::get<1>(statementresults).size() << " Statements" << std::endl;
        for (auto statementresult : std::get<1>(statementresults))
        {
            auto generated = statementresult->representation();
            std::cout << generated << std::endl;
            output.push_back(generated);
        }
    }
    else
    {
        print("ERROR - Function template did not match syntax");
    }
    output.push_back("}");

    writeFile(output, "../output/output.cpp");
}

namespace Compiler
{
    std::vector<Tokens> tokenPass(std::vector<std::string> content, const Language& language)
    {
        std::vector<Tokens> tokens;
        for (auto line : content)
        {
            std::cout << "Lexing: " << line << std::endl;
            tokens.push_back(lex(line, language));
        }
        return tokens;
    }

    std::vector<SymbolicTokens> symbolicPass(std::vector<Tokens> tokens)
    {
        std::vector<SymbolicTokens> symbolic_tokens;
        for (auto token_group : tokens)
        {
            symbolic_tokens.push_back(toSymbolic(generatorMap, token_group));
        }
        return symbolic_tokens;
    }

    SymbolicTokens join(std::vector<SymbolicTokens> token_groups)
    {
        auto tokens = SymbolicTokens();
        for (auto token_group : token_groups)
        {
            for (auto t : token_group)
            {
                tokens.push_back(t);
            }
        }
        return tokens;
    }
}
