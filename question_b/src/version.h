#ifndef VERSION_CMP_H_
#define VERSION_CMP_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

class version {
public:
    version(const std::string& str) : str_(str) {
        size_t end = str_.length();
        size_t tmp = 0;
        size_t pos = 0;
        size_t start = 0;

        // build tag
        tmp = str_.find("+");
        if (tmp != std::string::npos) {
            pos = tmp + 1;
            build_tag_ = std::string_view(str_.c_str() + pos, end - pos);
            end -= build_tag_.length() + 1;
        }

        // // pre-release tag
        tmp = str_.find("-");
        if (tmp != std::string::npos) {
            pos = tmp + 1;
            pre_release_ = std::string_view(str_.c_str() + pos, end - pos);
            end -= pre_release_.length() + 1;
        }

        // core versions
        core_versions_ = split(str_.substr(0, end), ".");

        // major
        pos = std::min(end, str_.find(".", start));
        major_ = std::string_view(str_.c_str() + start, pos - start);
        start += (major_.length()) ? major_.length() + 1 : 0;

        // minor
        pos = std::min(end, str_.find(".", start));
        minor_ = std::string_view(str_.c_str() + start, pos - start);
        start += (minor_.length()) ? minor_.length() + 1 : 0;

        // patch
        pos = std::min(end, str_.find(".", start));
        patch_ = std::string_view(str_.c_str() + start, pos - start);
        start += (patch_.length()) ? patch_.length() + 1 : 0;
    };

    bool operator<(const version& rhs) const {
        auto this_it = core_versions_.begin();
        for (auto it = rhs.core_versions_.begin(); it != rhs.core_versions_.end(); it++) {
            if (this_it == core_versions_.end()) {
                return true;
            }
            auto ls = *this_it;
            auto rs = *it;
            if (is_number(ls) && is_number(rs)) {
                if (std::stoi(ls) < std::stoi(rs)) {
                    return true;
                }
            } else {
                if (std::lexicographical_compare(ls.begin(), ls.end(), rs.begin(), rs.end())) {
                    return true;
                }
            }
            this_it++;
        }

        if (pre_release_ != "" && rhs.pre_release_ == "")
            return true;
        
        if (pre_release_ != "" && rhs.pre_release_ != "") {
            return version(std::string(pre_release_)) < version(std::string(rhs.pre_release_));
        }
        return false;
    }

    bool operator>(const version& rhs) const {
        return rhs < (*this);
    }

    bool operator<=(const version& rhs) const {
        return rhs > (*this) || rhs == (*this);
    }

    bool operator>=(const version& rhs) const {
        return rhs < (*this) || rhs == (*this);
    }

    bool operator==(const version& rhs) const {
        return !((*this) < rhs || rhs < (*this)); 
    }

    bool operator!=(const version& rhs) const {
        return !((*this) == rhs);
    }

    std::string major() const { return std::string(major_); }
    std::string minor() const { return std::string(minor_); }
    std::string patch() const { return std::string(patch_); }
    std::string pre_release() const { return std::string(pre_release_); }
    std::string build_tag() const { return std::string(build_tag_); }

private:
    std::string_view major_;
    std::string_view minor_;
    std::string_view patch_;
    std::string_view pre_release_;
    std::string_view build_tag_;

    std::vector<std::string> core_versions_;
    const std::string str_;
};

#endif // VERSION_CMP_H_
