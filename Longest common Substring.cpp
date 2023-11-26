#include <iostream>
#include <vector>
#include <string>

std::string longestCommonSubstring(std::string str1, std::string str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int maxLength = 0;
    std::string longestSubstring = "";

    std::vector<std::vector<int>> lookup(len1 + 1, std::vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
                if (lookup[i][j] > maxLength) {
                    maxLength = lookup[i][j];
                    longestSubstring = str1.substr(i - maxLength, maxLength);
                }
            }
        }
    }

    return longestSubstring;
}

int main() {
    std::string str1, str2;

    std::cout << "Enter the first string: ";
    std::cin >> str1;

    std::cout << "Enter the second string: ";
    std::cin >> str2;

    std::cout << "Longest common substring is: " << longestCommonSubstring(str1, str2) << std::endl;

    return 0;
}
