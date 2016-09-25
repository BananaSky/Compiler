#pragma once
#include "../Match/Match.hpp"
#include "../Types/SymbolicToken.hpp"

namespace Parse
{
    using namespace Match;
    using SymbolicTokenParser  = std::function<Result<SymbolicToken>(SymbolicTokens)>;
    using SymbolicTokenParsers = std::vector<SymbolicTokenParser>;

    //Convert a standard parseFunction to one that parses Tokens
    SymbolicTokenParser subTypeParser  (std::string sub_type);
    SymbolicTokenParser typeParser     (std::string type);
    SymbolicTokenParser dualTypeParser (std::string type, std::string sub_type);
}
