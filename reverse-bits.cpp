#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
    std::bitset<32> binary_32bit(n);

    //cout << binary_32bit.to_string() << std::endl;
    std::string s = binary_32bit.to_string();

    std::reverse(s.begin(), s.end());
    //std::cout << s << std::endl;

    std::bitset<32> reversed_bitset(s);
    unsigned long res = reversed_bitset.to_ulong();
    //std::cout << res << std::endl;

    return res;
}
};