
#[cfg(test)]
mod tests {
    use crate::http::http::{Request, RequestMethod, Header};

    #[test]
    fn test_from_null_bytes_is_error() {
        let r = Request::from_bytes([0; 1024]);
        assert!(r.is_err());
    }

    #[test]
    fn test_base_request() {
        let request_str = "GET / HTTP/1.1
Host: localhost:9999
User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:123.0) Gecko/20100101 Firefox/123.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8
Accept-Language: en-CA,en-US;q=0.7,en;q=0.3
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Upgrade-Insecure-Requests: 1
Sec-Fetch-Dest: document
Sec-Fetch-Mode: navigate
Sec-Fetch-Site: none
Sec-Fetch-User: ?1
";
        // put request_str into a 1024 byte buffer
        let mut argument: [u8; 1024] = [0; 1024];
        let request_bytes = request_str.as_bytes();
        let len = request_bytes.len().min(argument.len());
        argument[..len].copy_from_slice(&request_bytes[..len]);

        let r = Request::from_bytes(argument);

        assert!(r.is_ok());
        let actual: &RequestMethod = &r.as_ref().unwrap().method;
        assert_eq!(RequestMethod::GET, *actual);


        let expected_headers = vec![
            Header { key: "Host".to_string(), value: "localhost:9999".to_string() },
            Header { key: "User-Agent".to_string(), value: "Mozilla/5.0 (X11; Linux x86_64; rv:123.0) Gecko/20100101 Firefox/123.0".to_string() },
            Header { key: "Accept".to_string(), value: "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8".to_string() },
            Header { key: "Accept-Language".to_string(), value: "en-CA,en-US;q=0.7,en;q=0.3".to_string() },
            Header { key: "Accept-Encoding".to_string(), value: "gzip, deflate, br".to_string() },
            Header { key: "Connection".to_string(), value: "keep-alive".to_string() },
            Header { key: "Upgrade-Insecure-Requests".to_string(), value: "1".to_string() },
            Header { key: "Sec-Fetch-Dest".to_string(), value: "document".to_string() },
            Header { key: "Sec-Fetch-Mode".to_string(), value: "navigate".to_string() },
            Header { key: "Sec-Fetch-Site".to_string(), value: "none".to_string() },
            Header { key: "Sec-Fetch-User".to_string(), value: "?1".to_string() },
        ];

        let actual_headers = r.unwrap().headers;
        assert_eq!(expected_headers, actual_headers);
    }
}

