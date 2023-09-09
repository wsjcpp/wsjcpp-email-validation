# wsjcpp-email-validation

[![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-email-validation.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-email-validation/stargazers) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-email-validation.svg)](https://github.com/wsjcpp/wsjcpp-email-validation/) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-email-validation.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-email-validation/network/members)

Function for email validation

## static functions

- `WsjcppEmailValidation::isValidDate(const std::string &sValue, std::string &sError)`

## Integrate to your project

Just include this files:

- src/wsjcpp_validators.h
- src/wsjcpp_validators.cpp

## Integrate via wsjcpp

```
$ wsjcpp install https://github.com/wsjcpp/wsjcpp-email-validation:master
```

## Example usage

``` cpp

std::string sError = "";
if (!WsjcppEmailValidation::isValid(vEmails[i], sError)) {
if (!pValidatorUUID->isValid("abcdef01-ABCD-EF23-1000-000000000001", sError)) {
    std::cerr << sError << std::endl;
} else {
    std::cout << "OK" << std::endl;
}
```
