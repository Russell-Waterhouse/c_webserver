pub mod http {

    use std::io::{Error, ErrorKind};

    #[derive(Debug, PartialEq, Clone)]
    pub struct Header {
        pub key: String,
        pub value: String,
    }

    pub struct Query {
        pub key: String,
        pub value: String,
    }

    #[derive(Debug, PartialEq, Copy, Clone)]
    pub enum RequestMethod {
        GET,
        HEAD,
        POST,
        PUT,
        DELETE,
        CONNECT,
        OPTIONS,
        TRACE,
    }

    pub struct Request {
        pub method: RequestMethod,
        pub uri: String,
        pub headers: Vec<Header>,
        pub path: String,
        pub body: String,
        pub queries: Vec<Query>,
    }

    impl Request {
        pub fn from_bytes(request_bufr: [u8; 1024]) -> Result<Request, Error> {
            if request_bufr == [0; 1024] {
                return Err(Error::new(ErrorKind::InvalidInput, "Cannot construct request from empty message"));
            }

            let request_str_result = String::from_utf8(request_bufr.to_vec());
            if request_str_result.is_err() {
                return Err(Error::new(ErrorKind::InvalidInput, "Error converting input buffer to string"));
            }

            let request_str = request_str_result.unwrap();
            let request_lines = request_str.split("\n");
            let mut headers: Vec<Header> = Vec::new();
            for line in request_lines {
                if !line.contains(":") {
                    continue;
                }

                let mut split_line = line.split(":");
                let key = split_line.next();
                let value = split_line.next();
                if key.is_none() || value.is_none() {
                    // it probably wasn't a header I guess
                    continue;
                }
                let header = Header {
                    key: key.unwrap().to_string(),
                    value: value.unwrap().to_string()
                };
                headers.push(header);


            }

            Ok(Request {
                method: RequestMethod::GET,
                headers,
                queries: Vec::new(),
                path: "".to_string(),
                uri: "".to_string(),
                body: String::new()
            })
        }
    }

    pub struct Response {
        pub status: Status,
        pub headers: Vec<Header>,
        pub body: String,
    }

    pub enum Status {
        Continue100,
        SwitchProtocols101,

        Ok200,
        Created201,
        Accepted202,
        NonAuthoritativeInformation203,
        NoContent204,
        ResetContent205,
        PartialContent206,

        MultipleChoices300,
        MovedPermanently301,
        Found302,
        SeeOther303,
        NotModified304,
        UseProxy305,
        Unused306,
        TemporaryRedirect307,
        PermanentRedirect308,

        BadRequest400,
        Unauthorized401,
        PaymentRequired402,
        Forbidden403,
        NotFound404,
        MethodNotAllowed405,
        NotAcceptable406,
        ProxyAuthenticationRequired407,
        RequestTimeout408,
        Conflict409,
        Gone410,
        LengthRequired411,
        PreconditionFailed412,
        ContentTooLarge413,
        UriTooLong414,
        UnsupportedMediaType415,
        RangeNotSatisfiable416,
        ExpectationFailed417,
        Unused418,
        MisdirectedRequest421,
        UnprocessableContent422,
        UpgradeRequired426,

        InternalServerError500,
        NotImplemented501,
        BadGateway502,
        GatewayTimeout504,
        HttpVersionNotSupported505,
    }


    impl Response {
        pub fn to_bytes(&self) -> Vec<u8> {
            let reply = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
            let reply_bytes: Vec<u8> = reply.to_owned().into_bytes();
            reply_bytes
        }

    }
}
