# Low Level Webservers

## Simple web servers using no existing abstractions in C, C++, and Rust!

Using each of these technologies, I'm building a webserver with the following
features:
1. SQLite integration
2. HTML Templates
3. Concurrent request handling

The only existing abstraction that I'll be using is websockets.
Everything else will be built from scratch.

I have a few reasons for doing this:
1. I want to explore more low-level technologies.
2. I want to compare and contrast these low-level technologies.
3. I want to understand EVERYTHING that web servers are doing.

## Project Structure
The project is organized into separate modules for each
programming language, each containing a standalone web server implementation
with equivalent functionality. This modular structure facilitates direct
comparison and experimentation across the three languages.

/c  
/cpp  
/rust  

## Getting Started

### Prerequisites
- GCC compiler for C and C++
- Rust compiler for Rust
- SQLite

### Installation and Running

Instructions for compiling
and running the web servers will be provided for each language-specific module
within the project. Ensure you have the necessary compilers and SQLite
installed before attempting to run the servers.

### Contributing

Contributions are not being accepted at this time. They will be accepted when a
foundation of abstractions are built into the project.

When I have the following built into one language's webserver, I'll open it up
to contributions:
- Basic routing
- Basic concurrent request handling
- Basic database integration
- Basic HTML templating
- Session management
- Authentication
- Logging
- Tests
- Middleware support

# License
This project is open-sourced under the MIT License. See the LICENSE
file for more details.
