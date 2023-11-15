#ifndef JFG_UTILS_H_
#define JFG_UTILS_H_

#include <string>
#include <vector>

std::vector<std::string> split(std::string s, std::string delimiter) {
    std::vector<std::string> result;
    size_t last = 0;
    size_t next = 0;
    while ((next = s.find(delimiter, last)) != std::string::npos) {
        result.push_back(s.substr(last, next-last));
        last = next + 1;
    }
    result.push_back(s.substr(last));
    return result;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

#endif // JFG_UTILS_H_