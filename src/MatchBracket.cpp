#include "MatchBracket.h"

using namespace std;

bool MatchBracket::isLeft(const char ch) const {
    if ((ch == '(') || (ch == '[') || (ch == '<') || (ch == '{'))
        return true;
    return false;
}

bool MatchBracket::isRight(const char ch) const {
    if ((ch == ')') || (ch == ']') || (ch == '>') || (ch == '}'))
        return true;
    return false;
}

bool MatchBracket::matchPair(const char left, const char right) const {
    switch (right) {
        case ')':
            return left == '(';
        case ']':
            return left == '[';
        case '>':
            return left == '<';
        case '}':
            return left == '{';
        default:
            return false;
    }
}

bool MatchBracket::match(const string& input) {
    if (input.empty())
        return true;

    for (auto& c : input) {
        if (isLeft(c))
            m_stack.push(c);

        if (isRight(c)) {
            if (m_stack.empty())
                return false;
            if (matchPair(m_stack.top(), c))
                m_stack.pop();
            else 
                return false;
        }
    }
    return m_stack.empty();
}

void MatchBracket::flush() {
    while (!m_stack.empty())
        m_stack.pop();
}
