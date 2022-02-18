#pragma once

#include <boost/format.hpp>
#include <fstream>
#include <map>
#include <string>

#include "domain/models/RequestBody.hpp"

namespace getit::domain::implementations
{
    class FormdataRequestBody: public models::RequestBody
    {
        public:
            explicit FormdataRequestBody(std::string boundary);
            FormdataRequestBody() = default;
            ~FormdataRequestBody() = default;

            void addElement(std::string key, std::string value);
            void addFile(std::string key, std::string filePath);

            void setBoundary(std::string boundary);
            void setElements(std::map<std::string, std::string> elements);
            void setFiles(std::map<std::string, std::string> files);

            std::string getBoundary();
            std::map<std::string, std::string> getElements();
            std::map<std::string, std::string> getFiles();

            std::string getBody() override;
            std::string getContentType() override;

        private:
            std::string boundary;
            std::map<std::string, std::string> elements;
            std::map<std::string, std::string> files;

            std::string getElementsBody();
            std::string getFilesBody();

            // Boost templates
            inline static
            const std::string CONTENT_TYPE_TEMPLATE = "multipart/form-data; boundary=\"%1%\"";
            
            inline static
            const std::string BODY_WITH_BOUNDARY_TEMPLATE = "%1%%2%\r\n--%3%--\r\n";

            inline static
            const std::string ELEMENT_TEMPLATE = "--%1%\r\nContent-Disposition: form-data; name=\"%2%\"\r\n\r\n%3%\r\n";

            inline static
            const std::string FILE_TEMPLATE = "--%1%\r\nContent-Disposition: form-data; name=\"%2%\"; filename=\"%3%\"\r\n\r\n%4%\r\n";
    };
}