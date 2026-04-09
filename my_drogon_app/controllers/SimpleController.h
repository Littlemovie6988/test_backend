#pragma once
#include <drogon/HttpController.h>
using namespace drogon;

class SimpleController : public drogon::HttpController<SimpleController>
{
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(SimpleController::handleHello, "/hello", Get);
        ADD_METHOD_TO(SimpleController::handleStart, "/", Get);
    METHOD_LIST_END

    void handleHello(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback) const;
    void handleStart(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback) const;
};