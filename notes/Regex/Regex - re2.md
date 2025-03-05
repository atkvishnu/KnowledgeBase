
Regular expressions are a notation for describing sets of character strings. When a particular string is in the set described by a regular expression, we often say that the regular expression _matches_ the string.

The simplest regular expression is a single literal character. Except for the metacharacters like `*+?()|`, characters match themselves. To match a metacharacter, escape it with a backslash: `\+` matches a literal plus character.

Two regular expressions can be alternated or concatenated to form a new regular expression: if _e_1 matches _s_ and _e_2 matches _t_, then _e_1`|`_e_2 matches _s_ or _t_, and _e_1_e_2 matches _st_.

The metacharacters `*`, `+`, and `?` are repetition operators: _e_1`*` matches a sequence of zero or more (possibly different) strings, each of which match _e_1; _e_1`+` matches one or more; _e_1`?` matches zero or one.

The operator precedence, from weakest to strongest binding, is first alternation, then concatenation, and finally the repetition operators. Explicit parentheses can be used to force different meanings, just as in arithmetic expressions. Some examples: `ab|cd` is equivalent to `(ab)|(cd)`; `ab*` is equivalent to `a(b*)`.

The syntax described so far is most of the traditional Unix _egrep_ regular expression syntax. This subset suffices to describe all regular languages: loosely speaking, a regular language is a set of strings that can be matched in a single pass through the text using only a fixed amount of memory. Newer regular expression facilities (notably Perl and those that have copied it) have added many new operators and escape sequences, which make the regular expressions more concise, and sometimes more cryptic, but usually not more powerful.

This page lists the regular expression syntax accepted by RE2. Note that this syntax is a subset of that accepted by PCRE, roughly speaking, and with various [caveats](https://swtch.com/~rsc/regexp/regexp3.html#caveats).

It also lists some syntax accepted by PCRE, PERL, and VIM.