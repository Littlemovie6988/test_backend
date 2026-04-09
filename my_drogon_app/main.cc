#include <drogon/drogon.h>
#include <iostream>

int main() {
    std::cout << "Starting Drogon server on http://localhost:8080" << std::endl;
    drogon::app().loadConfigFile("../config.json");
    drogon::app().run();
    return 0;
}