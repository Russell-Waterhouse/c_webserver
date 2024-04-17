#include <string>
#include <unordered_map>

class HttpResponse {
public:
    std::string m_type;
    std::string m_url;
    std::unordered_map<std::string, std::string> m_headers;
    std::string m_body;
    int m_status;
    std::string m_statusText;

    HttpResponse(HttpRequest request) {
        m_type = request.m_type;
        // TODO: finish initializing response here
    }
};
