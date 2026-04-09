#include "libs/httplib.h"
#include <iostream>
#include <string>

using namespace httplib;

void send_utf8(Response& res, const std::string& body, const std::string& mime = "text/plain") {
    if (mime.find("text/") == 0 || mime == "application/json") {
        res.set_content(body, mime + "; charset=utf-8");
    } else {
        res.set_content(body, mime);
    }
}


int main() {
    // Создаём сервер
    Server svr;
    setlocale(LC_ALL, "RU");

    // Обработчик GET-запроса на корень "/"
    svr.Get("/", [](const Request& req, Response& res) {
        send_utf8(res, "Hello, World! Это простой бекенд на C++", "text/plain");
    });

    // GET-запрос с параметром (например, /hello?name=Alex)
    svr.Get("/hello", [](const Request& req, Response& res) {
        std::string name = "Гость";
        if (req.has_param("name")) {
            name = req.get_param_value("name");
        }
        std::string body = "Привет, " + name + "!";
        send_utf8(res, body, "text/plain");
    });

    // POST-запрос с JSON-данными
    svr.Post("/data", [](const Request& req, Response& res) {
        // Читаем тело запроса (должен быть JSON)
        std::string body = req.body;
        // В реальном проекте здесь парсили бы JSON (например, через nlohmann/json)
        std::string response_json = R"({"status": "ok", "received": ")" + body + R"("})";
        send_utf8(res, response_json, "application/json");
    });

    // Запуск сервера на localhost:8080
    std::cout << "Сервер запущен на http://localhost:8080\n";
    svr.listen("localhost", 8080);

    return 0;
}