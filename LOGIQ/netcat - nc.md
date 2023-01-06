netcat ( abbv. nc ) is a networking utility for reading from and writing to network connections using TCP and UDP.
The command is designed to be a dependable backend that can be used directly or easily driven by other programs/scripts.
At the same time, it's a feature rich network debugging and investigation tool, since it can produce almost any kind of connection it's user could need and has a number od built-in capabilities.

It's list of features include:
- port scanning
- transferring files
- port listening, it can be used as a backdoor.


## Feature
The original netcat's features include:
- -   Outbound or inbound connections, TCP or UDP, to or from any ports
-   Full [DNS forward/reverse checking](https://en.wikipedia.org/wiki/Reverse_DNS_lookup "Reverse DNS lookup"), with appropriate warnings
-   Ability to use any local source port
-   Ability to use any locally configured network source address
-   Built-in port-scanning capabilities, with randomization
-   Built-in loose source-routing capability
-   Can read command line arguments from standard input
-   Slow-send mode, one line every N seconds
-   [Hex dump](https://en.wikipedia.org/wiki/Hex_dump "Hex dump") of transmitted and received data
-   Optional ability to let another program service establish connections
-   Optional [telnet](https://en.wikipedia.org/wiki/Telnet "Telnet")-options responder

## Examples

1. Opening a raw connection to port 25

```
nc mail.server.net 25
```

2. Performing an HTTP request

```
printf "GET /index.html HTTP/1.0\r\nHost: info.cern.ch\r\n\r\n" | nc info.cern.ch 80
```

The full response (including HTTP headers) will be dumped to standard output.

3. Setting up a one-shot webserver on port 8080 to present the content of a file

```
 { printf 'HTTP/1.0 200 OK\r\nContent-Length: %d\r\n\r\n' "$(wc -c < some.file)"; cat some.file; } | nc -l 8080
```



---
---


## Locally sending TCP/UDP packets using Netcat

###### simulate a client using a useful tool called **Netcat** and realize the immediate connection using your own computer's terminal.

Although **Netcat** can do many things, its main purpose and most desirable function is to:

1.  Create an initial socket to establish a connection from server to the client.
    
2.  Once connected, Netcat will automatically generate a second socket to transmit files from the server to the client and visa versa. (This is the really cool part.)
    

Reference below for a diagram of the data Netcat protocol architecture.


![[Pasted image 20221108072829.png]]

Something so simple happens to be extraordinarily powerful and flexible as you will see below. For simplicity, local connections are used, although, of course, they can be used between different machines.

### Syntax

nc [-options] hostname port[s] [ports]  
nc -l -p port [-options] [hostname] [port]

### Basic parameters

-   -**l**:  set the "listen" mode, waits for the incoming connections.
-   -**p**: local port
-   -**u**: set the UDP mode

With **Netcat** your PC can be converted in a server, you want to begin as a server that listens at port **2399**:
```
> nc localhost 2399
```

In addition, we can use the server to connect to the port (**2399**) recently opened, from the **client** side:
```
> nc -l 2399
```

![[3.gif]]

### UDP client

By default **Netcat**  uses the **TCP** protocol for its communications, but it can also **UDP** using the  **-u** option.

```
$ nc -u -l 2399
```

Once you start the server, establish the connection with the **client**:

```
$ nc -u localhost 2399
```


Now the client and the server are using **UDP** protocol for their communication. You can verify commincation using the **netstat** command in a new (3rd) computer terminal. 

 `$ netstat` `| grep` `2399`  
`udp 0 0 localhost:2399 localhost:57508  ESTABLISHED`







