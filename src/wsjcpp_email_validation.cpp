#include "wsjcpp_email_validation.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

bool WsjcppEmailValidation::isValid(const std::string &sValue, std::string &sError) {
    const std::string m_sValidator = "^[0-9a-zA-Z]{1}[0-9a-zA-Z-._]*[0-9a-zA-Z]{1}@([0-9a-zA-Z]{1}[-.0-9a-zA-Z]*[0-9a-zA-Z]{1}\\.[a-zA-Z]{2,6})$";
    std::regex rgx(m_sValidator);

    if (!std::regex_match(sValue, rgx)) {
        sError = "Email address must match regular expression " + m_sValidator;
        return false;
    }

    std::smatch matches;
    std::regex_search(sValue, matches, rgx);

    std::string sDomain = matches[1].str();
    std::transform(sDomain.begin(), sDomain.end(), sDomain.begin(),
        [](unsigned char c){ return std::tolower(c); });

    const std::map<std::string, std::string> mapEmailWrongDomains = {
        {"yndex.ru", "yandex.ru"},
        {"yande.ru", "yandex.ru"},
        {"yadnex.ru", "yandex.ru"},
        {"mil.ru", "mail.ru"},
        {"nail.ru", "mail.ru"},
        {"mial.ru", "mail.ru"},
        {"mai.ru", "mail.ru"},
        {"mailn.ru", "mail.ru"},
        {"amil.ru", "mail.ru"},
        {"gmail.ru", "gmail.com"},
        {"gmaik.com", "gmail.com"},
        {"gmial.com", "gmail.com"},
        {"gmal.com", "gmail.com"},
        {"inbox.ry", "inbox.ru"},
        {"gamil.com", "gmail.com"},
        {"gmail.cpm", "gmail.com"},
        {"protonmaill.com", "protonmail.com"},
        {"hotnail.com", "hotmail.com"},
    };

    if (mapEmailWrongDomains.find(sDomain) !=  mapEmailWrongDomains.end()) {
        std::string sDomainPropose = mapEmailWrongDomains.at(sDomain);
        sError = "Email has wrong domain name " + sDomain + ", maybe you meen: " + sDomainPropose;
        return false;
    }

    const std::map<std::string, std::string> mapEmailForbiddenDomains = {
        {"fmshool72.ru", "DNS Error: 6986617 DNS type 'mx' lookup of fmshool72.ru responded with code NXDOMAIN Domain name not found: fmshool72.ru"},
    };

    if (mapEmailForbiddenDomains.find(sDomain) !=  mapEmailForbiddenDomains.end()) {
        sError = mapEmailForbiddenDomains.at(sDomain);
        return false;
    }
    return true;
}
