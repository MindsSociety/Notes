# CS320 - Networks
Notes from last minute study 2014  
Jack Higgins  

**Notes:**
- Does not cover all labs
- Some content will not render correctly on Dropbox.  Rendered best with GitHub
style Markdown.  I'm using the Atom editor by GitHub.

# Layer 1 - Physical
## Fourier Analysis
![Fourier Analysis](https://dl.dropboxusercontent.com/u/10023442/Permanent/images/Fourier%20Analysis.png)

### Bandwidth
- Number of bits that can be sent per second
- Measured in `Hz`

### Bit Rate
- Number of Bits sent per second
- Measured in bits per second - `bps`

### Fundamental Frequency
- The lowest frequency of a periodic waveform
- Measured in `Hz`

### Time to send one byte
- `T = 8/b`
- Where `b` is the bandwidth

### Harmonics
- `number of Harmonics = bandwidth / fundamental frequency`

### What are the effects of the varying bit rate
```haskell
bandwidth = 6000 Hz

b = 300 bps

f = 300 / 8 = 37.5

no. of harmonics = 6000 / 37.5 = 160 Harmonics

High number of Harmonics -> High fidelity
```

# Layer 2 - Data Link

## Role of the Data Link Layer
- Efficient communication between two adjacent nodes
- Communication circuits are error-prone due to thermal or impulsive noises,
  signal distorsion, etc.
- The main function of the data-link layer is to hide these errors happening at
  the physical level

## Cyclic Redundancy Check (CRC)
Aka polynomial code
- Checks for errors in transmission
- Similar to Checksum
- Treats the data as a representation of polynomial equation and uses polynomial
  arithmetic to detect errors
- Any bit string containing k bits can be used to represent a polynomial of
  degree k-1 with coefficients 0 and 1

### How it works
- Generator number G(x), 12 and 16 are good numbers to use
- Method:
  - Sender generates `G(x)`
  - Append `G(x) - 1` `0`'s to to `M(x)`
  - Divide the Message `M(x)` by `G(x)` to generate `r` the remainder
  - `T(x)` = `r XOR M(x)`
  - `T(x)` is sent
  - If `T(x)` has no remainder then the message sent successfully
- Example:

```python
G(x)      | M(x)
--------- | ---------------------------
1 0 0 1 1 | 1 1 0 1 0 1 1 0 1 1 0 0 0 0
          | 1 0 0 1 1 |
          | --------- ▼
          |   1 0 0 1 1
          |   1 0 0 1 1 | | | | |
          |   --------- ▼ ▼ ▼ ▼ ▼
          |             1 0 1 1 0
          |             1 0 0 1 1 | |
          |             --------- ▼ ▼
          |                 1 0 1 0 0
          |                 1 0 0 1 1 |
          |                 --------- ▼
          |                     1 1 1 0
          |
---------------------------------------

            1 1 0 1 0 1 1 0 1 1 0 0 0 0
                                1 1 1 0
            ---------------------------
     T(x) = 1 1 0 1 0 1 1 0 1 1 1 1 1 0

```


#### [Difference between Mac Address and IP Address](http://www.differencebetween.net/technology/difference-between-mac-and-ip-address/)

# Layer 3 - Network

## [Internet Protocol](http://en.wikipedia.org/wiki/Internet_Protocol)
- Primary protocol in the Network Layer
- Defines Datagram construction, IP addressing and Routing

## [Internet Control Message Protocol (ICMP)](http://searchnetworking.techtarget.com/definition/ICMP)
- Message control and error-reporting protocol between a host server and a
  gateway to the Internet.
- ICMP uses Internet Protocol (IP) datagrams, but the messages are processed by
  the IP software and are not directly apparent to the application user.

## Forwarding
Transfer of a datagram from an incoming link to an outgoing link within a single
router

## Routing
Determine the paths of the datagrams from source to destination

## IPV4 Header
![IPV4 Header](https://dl.dropboxusercontent.com/u/10023442/Permanent/images/IPV4Header.png)

## IP Addressing of Subnets
IP addresses refer to a subnet as follows  `a.b.c.d/x` where `/x` is the number
of bits used to address the subnet.

## Classfull Addressing
| Class     | Number of bits for Subnet address | Format                                |
| :-------: | :-------------------------------- | :------------------------------------ |
| *Class A* | 8-bit Subnet address              | `0sssssss.hhhhhhhh.hhhhhhhh.hhhhhhhh` |
| *Class B* | 16-bit Subnet address             | `10ssssss.ssssssss.hhhhhhhh.hhhhhhhh` |
| *Class C* | 24-bit Subnet address             | `11ssssss.ssssssss.ssssssss.hhhhhhhh` |

- `s` = Subnet Addressing
- `h` = Host Addressing

## Classless Inter Domain Routing (CIDR)
Allows allocation of different segments of the same network to different domains

# Layer 4 - Transmission

## [UDP](http://searchsoa.techtarget.com/definition/UDP)
User Datagram Protocol
- UDP (User Datagram Protocol) is a communications protocol similar to TCP
- UDP does not provide the service of dividing a message into packets
  (datagrams) and reassembling it at the other end
- Specifically, UDP doesn't provide sequencing of the packets that the data
  arrives in
- Connectionless
- No mechanism to resend data

## [Datagram](http://searchnetworking.techtarget.com/definition/datagram)
A self-contained, independent entity of data carrying sufficient information to
be routed from the source to the destination computer without reliance on
earlier exchanges between this source and destination computer and the
transporting network.

## [TCP](http://searchnetworking.techtarget.com/definition/TCP)
TCP (Transmission Control Protocol) is a standard that defines how to establish
and maintain a network conversation via which application programs can exchange
data.
- Designed to provide reliable end-to-end byte stream over an unreliable
  internetwork
- A TCP connection is a byte stream
- TCP connections are established and maintained until the application programs
  at each end have finished exchanging messages.
- It determines how to break application data into packets

### TCP Sliding Window
Common segment transmission mechanisms are:
- **Stop-and-wait** - The sender stops and wait for ACK after every segment
- **Pipelining** - Allows to transmit multiple segments without waiting for
  ACK (Go-Back-N, Selective Repeat)

TCP uses 3 fields to implement the sliding window protocol with cumulative
acknowledgement:
- The *sequence* number
- The *acknowledgement* number
- The *window size* field to indicate how many more bytes of data the recipient
  is willing to accept before further acknowledgement

#### TCP Sliding Window Example
*Done by Niamh*
![TCP Sliding Window](https://dl.dropboxusercontent.com/u/10023442/Permanent/images/TCP%20Sliding%20Window.jpg)

### TCP Checksum
- The checksum is a 16 bits binary word to verify data integrity
- It's calculated from the data before sending and after reception
- If both checksums differ, it's very likely that the integrity of the data has
  been compromised
- If so, the segment will not be acknowledged


## [Sockets](http://en.wikipedia.org/wiki/Network_socket)
A network socket is an endpoint of an inter-process communication flow across a
computer network.  Sockets are a method for communication between a client
program and a server program in a network.  Sockets can also be used for
communication between processes within the same computer.

Sockets use the set of following primitives:

| Primitive  | Function                                                 |
| :--------- | :------------------------------------------------------- |
| `SOCKET`   | create a new communication endpoint                      |
| `BIND`     | associate a local address with a socket - Bind to a port |
| `LISTEN`   | announce willingness to accept connections               |
| `ACCEPT`   | passively establish an incoming connection               |
| `CONNECT`  | actively attempt to establish a connection               |
| `SEND`     | send data                                                |
| `RECEIVE`  | receive data                                             |
| `CLOSE`    | release the connection                                   |

#### `BIND`
- When an application process wants to set up a connection to a remote
  application process
- Need to define transport addresses to which processes can listen to TSAP,
  Transport Service Access Point
- In the Internet, TSAP are known as ports
- Each socket requires a local address called a port
- Different services use different ports
  - System ports: [0; 1023] (e.g. 80 HTTP, 21 FTP...)
  - Other ports (≥ 1024) can be used for custom applications


### TCP Header
![TCP Header](https://dl.dropboxusercontent.com/u/10023442/Permanent/images/TCPHeader.png)

# Layer 5 - Application Layer

## Client-server architecture
- Host on server
- Client initiates connection

## Peer to Peer architecture (P2P)
- Direct Communication between hosts

## MIME Types
- Multipurpose Internet Mail Extensions
- Used in HTTP
- Examples:
  + text/html
  + text/plain
  + image/jpeg
  + video/quicktime

## Authentication
### Basic Authentication
- Server sends 401 Not Authorised
- Client should resend with an `Authorization` header
- Client sends the username and password, separated by a `:`
- Not for Encryption
- Basic authentication can be made secure by using encrypted data transmission

### Digest Authentication
- Digest authentication doesn't send credentials in the clear
- Contains a `nonce` variable for generating a hash
- A hash function takes a sequence of bits of any length and transforms it into
  a fixed size sequence
- One way function, non-reversable.

## [SSL (Secure Socket Layer)](http://searchsecurity.techtarget.com/definition/Secure-Sockets-Layer-SSL)
The Secure Sockets Layer (SSL) is a computer networking protocol that manages
server authentication, client authentication and encrypted communication between
servers and clients.
- SSL uses a combination of public-key and symmetric-key encryption
- The Transport Layer Security (TLS) protocol evolved from SSL and has largely
  superseded it, although SSL is still widely used.

## HTTPS
- HTTPS uses HTTP over a Secure Socket Layer (SSL)
- The identity of the server is guaranteed to the client by a trustable third
  party issuing a Certification Authority (CA)
- The client encodes data using a public key provided by the CA
- The server can decode the data using a corresponding private key

## [Domain Name System (DNS)](http://searchnetworking.techtarget.com/definition/domain-name-system)
- The domain name system (DNS) is the way that Internet domain names are located
  and translated into Internet Protocol addresses
- The lists of domain names and IP addresses are distributed throughout the
  Internet in a hierarchy of authority.
- DNS use a complicated distributed hierarchical architecture
- This is to avoid a single point of failure


### DNS Servers
- Hierarchical architecture
- Top-level servers are responsible for each top-level domain, e.g. com, org,
  etc.

### [Domain name syntax](http://en.wikipedia.org/wiki/Domain_Name_System#Domain_name_syntax)
The hierarchy of domains descends from right to left.
Each label to the left specifies a subdomain of the domain to the right.  
Example: `www.example.com`
- `com` represents the top-level domain
- `example` is a sub-domain of `com`
- `www` is a sub-domain of `example.com`

### Local DNS servers
- Act as proxies close from the hosts
- ISP, Network administrators may provide Local DNS servers

# Useful Links
- [Why do we have both MAC addresses and IP addresses?](http://www.fixedbyvonnie.com/2014/09/mac-addresses-ip-addresses/)
