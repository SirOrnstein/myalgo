/**
 * MatchBracket.h
 *
 */

#ifndef __MATCHBRACKET_H__
#define __MATCHBRACKET_H__

#include <string>
#include <stack>

class MatchBracket {
    public:
        bool match(const std::string& input);
        void flush();
    private:
        bool isLeft(const char) const;
        bool isRight(const char) const;
        bool matchPair(const char, const char) const;

        std::stack<char> m_stack;
};

#endif // __MATCHBRACKET_H__
