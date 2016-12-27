#pragma once
#include "seperate.hpp"
#include "import.hpp"

namespace lex
{
    using LanguageTermSet  = tuple<Terms, string>;
    using LanguageTermSets = vector<LanguageTermSet>;

    // A single definition for lexing a language element (ie int, operator)
    struct LanguageLexer
    {
        function<Result<string>(vector<string>)> match;
        string name;
        string type;
        int precedence;
        LanguageLexer(function<Result<string>(vector<string>)> set_match_function, 
                      string set_name, 
                      string set_type, 
                      int set_precedence);
    };

    using LanguageLexers  = vector<LanguageLexer>;

    // A collection of lexers/term sets that can Identify terms
    struct Language
    {
        Seperators    seperators;
        bool          newline;

        LanguageTermSets language_term_sets;
        LanguageLexers   language_lexers;

        Language(const LanguageTermSets& set_term_sets,
                 const LanguageLexers&   set_language_lexers,
                 Seperators whitespace);
        Language();

        tuple<Token, Terms> identify(Terms terms) const;
    };
}