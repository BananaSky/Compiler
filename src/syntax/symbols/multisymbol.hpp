#include "symbol.hpp"

namespace syntax
{

struct MultiSymbol : public Symbol
{
    vector<vector<shared_ptr<Symbol>>> groups;
    string tag;
    MultiSymbol();
    MultiSymbol(string set_tag, vector<vector<shared_ptr<Symbol>>> set_groups);
};

}
