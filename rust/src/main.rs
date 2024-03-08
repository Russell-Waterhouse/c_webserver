use std::net::{Shutdown, TcpListener};
use std::io::{Error, Read};
use std::net::TcpStream;
use std::io::{self, Write};
use io::ErrorKind::InvalidData;
use std::str::{self};

fn main() -> Result<(), std::io::Error> {
    let result_or_error = TcpListener::bind("127.0.0.1:9999");
    if result_or_error.is_err() { eprintln!("Error: {}\n", result_or_error.as_ref().unwrap_err()); return Err(result_or_error.unwrap_err());
    }

    let socket_file_descriptor = result_or_error.unwrap();

    for stream in socket_file_descriptor.incoming() {
        match stream {
            Ok(mut ok_stream) => {
                println!("New connection!");
                let r = send_hello(&mut ok_stream);
                if r.is_err() {
                    eprintln!("Error: {}\n", r.unwrap_err());
                }
            }
            Err(e) => {
                eprintln!("Error: {}\n", e);
            }
        };
    }

    Ok(())
}

fn send_hello(stream: &mut TcpStream) -> io::Result<()> {
    println!("New connection!");
    let mut bufr: [u8; 1024] = [0; 1024];
    let reply = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    let response = reply.to_owned().into_bytes();
    loop {
        let num_bytes_read = stream.read(&mut bufr)?;
        if num_bytes_read == 0 {
            // client has no more to send
            break;
        }
        println!("Bytes read: {}", &num_bytes_read);
        let msg_received = str::from_utf8(&bufr);
        if msg_received.is_err() {
            return Err(Error::new(InvalidData, msg_received.unwrap_err()));
        }
        println!("Contents read: {}", msg_received.unwrap());
        let write_success = stream.write_all(&response);
        if write_success.is_err() {
            return Err(write_success.unwrap_err());
        }
    }
    let _ = stream.shutdown(Shutdown::Both);

    Ok(())
}
