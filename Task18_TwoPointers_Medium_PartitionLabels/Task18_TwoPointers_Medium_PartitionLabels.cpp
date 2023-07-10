#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_map>

class Solution {
public:
    static std::vector<int> partitionLabels(std::string s) {
        std::unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); i++)
            umap[s[i]] = i;
        std::vector<bool> visited(26, false);
        int head = 0, tail = 0;
        std::vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            if (i > tail) {
                result.push_back(tail - head + 1);
                head = i;
            }
            tail = std::max(tail, umap[s[i]]);
        }
        result.push_back(tail - head + 1);
        return result;
    }
};

int main()
{
    std::vector<int> result = Solution::partitionLabels("ababcbacadefegdehijhklij");
    for (int i : result) {
        std::cout << i << " ";
    }
}
