
#include <string>
#include <unordered_map>
enum RequestMethod {
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE
};

class HttpRequest {
public:
    std::unordered_map<std::string, std::string> m_headers;
    RequestMethod m_requestMethod;
    std::string m_url;
    std::string m_destination;
    std::string mode;
    std::string body;

    HttpRequest(std::string request_str) {
        //todo: initialize request here
    }
};
