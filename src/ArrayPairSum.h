/**
 * ArrayPairSum.h
 *
 */

#ifndef __ARRAYPAIRSUM_H__
#define __ARRAYPAIRSUM_H__

#include <vector>
#include <unordered_map>

size_t two_sum(const std::vector<uint32_t>& input, const uint32_t sum) {
    size_t result = 0;
    std::unordered_map<uint32_t, size_t> odmap;
    typedef std::unordered_map<uint32_t, size_t>::iterator ODMapIter;

    if (input.empty())
        return result;

    for(const auto& i : input) {
        std::pair<ODMapIter, bool> ret = odmap.emplace(i, 1);
        if (!ret.second)
            ++ret.first->second;
    }

    for(const auto& p : odmap) {
        uint32_t k = p.first;
        size_t v = p.second;
        if (2 * k == sum && v > 1) {
            result += v * (v - 1);
        } else {
            ODMapIter it = odmap.find(sum - k); 
            if (it != odmap.end()) {
                result +=  v * it->second;
            }
        }
    }
    return result/2;
}

struct Triplet {
    int one;
    int two;
    int three;
};

std::vector<Triplet> three_sum(const std::vector<uint32_t>& input, const uint32_t sum) {
    return std::vector<Triplet>();
}

#endif // __ARRAYPAIRSUM_H__
