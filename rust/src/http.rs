pub mod http {
    use std::str::from_utf8;

    pub struct Header {
        pub key: String,
        pub value: String,
    }

    pub enum RequestMethod {
        GET,
        POST,
    }

    pub struct Request {
        pub method: RequestMethod,
        pub headers: Vec<Header>,
        pub path: String,
        pub body: String,
    }

    impl Request {
        pub fn from_bytes(request: [u8; 1024]) -> Self {
            let request_str = from_utf8(&request).unwrap();
            let mut lines = request_str.lines();
            let first_line = lines.next().unwrap();
            let mut parts = first_line.split_whitespace();
            let method = parts.next().unwrap();
            let path = parts.next().unwrap();
            let request_headers = Vec::new();
            for line in lines {
                let _parts = line.split(": ");
                // let key = parts.next().unwrap();
                // let value = parts.next().unwrap();
                // request_headers.push(Header{key: key.to_string(), value: value.to_string()});
            }
            Request {
                method: match method {
                    "GET" => RequestMethod::GET,
                    "POST" => RequestMethod::POST,
                    _ => panic!("Unsupported method")
                },
                headers: request_headers,
                path: path.to_string(),
                body: String::new()
            }
        }
    }

    pub struct Response {
        pub status: u16,
        pub headers: Vec<Header>,
        pub body: String,
    }

    impl Response {
        pub fn to_bytes(&self) -> Vec<u8> {
            let reply = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
            let reply_bytes: Vec<u8> = reply.to_owned().into_bytes();
            reply_bytes
        }

    }
}
