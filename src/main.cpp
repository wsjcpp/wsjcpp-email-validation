#include <string.h>
#include <iostream>
#include <algorithm>
#include <wsjcpp_core.h>
#include <wsjcpp_email_validation.h>

int main(int argc, char* argv[]) {
    std::string TAG = "MAIN";

    if (!WsjcppCore::dirExists(".wsjcpp")) {
        WsjcppCore::makeDir(".wsjcpp");
    }
    std::string appLogPath = ".wsjcpp/logs";
    if (!WsjcppCore::dirExists(appLogPath)) {
        WsjcppCore::makeDir(appLogPath);
    }
    WsjcppLog::setPrefixLogFile("wsjcpp_validators");
    WsjcppLog::setLogDirectory(".wsjcpp/logs");

    // WsjcppLog::info(TAG, "Hello");
    WsjcppCore::init(
        argc, argv,
        std::string(WSJCPP_APP_NAME),
        std::string(WSJCPP_APP_VERSION),
        "Evgenii Sopov",
        ""
    );
    if (argc != 2) {
        std::cout << "Usage " << argv[0] << " email1 email2 ... emailN" << std::endl;
        return -1;
    }

    std::vector<std::string> vEmails;
    for (int i = 1; i < argc; i++) {
        vEmails.push_back(std::string(argv[i]));
    }

    int nRet = 0;
    for (int i = 0; i < vEmails.size(); i++) {
        std::string sError = "";
        if (!WsjcppEmailValidation::isValid(vEmails[i], sError)) {
            std::cerr << vEmails[i] << " RESULT: FAILED " << sError << std::endl;
            nRet = 1;
        } else {
            std::cout << vEmails[i] << " RESULT: OK" << std::endl;
        }
    }
    return nRet;
}
