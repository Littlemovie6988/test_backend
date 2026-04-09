#include "SimpleController.h"
#include <drogon/HttpResponse.h>
#include <json/json.h>

void SimpleController::handleHello(const HttpRequestPtr &req,
                                   std::function<void(const HttpResponsePtr &)> &&callback) const
{
    Json::Value json;
    json["message"] = "Hello from Drogon controller!";
    json["status"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

void SimpleController::handleStart(const HttpRequestPtr &req,
                                   std::function<void(const HttpResponsePtr &)> &&callback) const
{
    Json::Value json;
    json["message"] = "Hello! Sart page!";
    json["status"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}