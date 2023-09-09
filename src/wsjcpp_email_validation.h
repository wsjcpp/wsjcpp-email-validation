#ifndef __WSJCPP_EMAIL_VALIDATION_H__
#define __WSJCPP_EMAIL_VALIDATION_H__

#include <string>
#include <vector>
#include <regex>

class WsjcppEmailValidation {
    public:
        static bool isValid(const std::string &sValue, std::string &sError);
};

#endif // __WSJCPP_EMAIL_VALIDATION_H__
