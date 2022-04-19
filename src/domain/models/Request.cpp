#include "domain/models/Request.hpp"

using namespace getit::domain::models;

void Request::setMethod(const std::string& method)
{
    this->method = method;
}

void Request::setUri(const std::string& uri)
{
    this->uri = uri;
}

void Request::setVariables(std::shared_ptr<Variables> variables)
{
    this->variables = variables;
}

void Request::setHeaders(const std::map<std::string, std::string>& headers)
{
    for (const auto& [header, value] : headers) {
        this->headers.emplace(header, value);
    }
}

void Request::setBody(std::shared_ptr<RequestBody> body)
{
    this->body = body;
}

std::string Request::getMethod()
{
    return this->method;
}

std::string Request::getUri()
{
    return this->uri;
}

std::shared_ptr<Variables> Request::getVariables()
{
    return this->variables;
}

std::map<std::string, std::string> Request::getHeaders()
{
    return this->headers;
}

std::shared_ptr<RequestBody> Request::getBody()
{
    return this->body;
}