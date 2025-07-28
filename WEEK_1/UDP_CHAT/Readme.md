Udp-Chat App (Client-Server):

Project Structure:
UDP_CHAT/
   ├── src/
   │ ├── client.c
   │ ├── server.c
   ├── inc/
   │ ├── client.h
   │ ├── server.h
   ├── README.md
   
   
steps :

1->Go to src and compile the file (client.c & server.c)
	-> gcc client.c -I../inc -o client
	-> gcc server.c -I../inc -o server
	
	// I../inc tells gcc to look for header files in the inc/ directory

2->Run the files
	-> ./server <port>
	-> ./client <server_ip> <port>
	
EX:
 	-> ./server 1024
	-> ./client 127.0.0.1 1024  //Common ip ->127.0.0.1
	
	// Port use 1024–49151 
	// Server_ip 127.0.0.1 → 127.255.255.255 IP address range, which is reserved for loopback functionality. first ->3 bit for reserved in loopback
	// scope ->Local-only, packets never leave your machine
	
Port explain :

	(i)   0–1023 ->Reserved for system services and standard protocols
	(ii)  1024–49151 ->Registered ports (Assigned for user or vendor-specific apps)
	(iii) 49152–65535 ->Client-side ports when your browser connects to a web server
	
	
Output :

Client
	/client 127.0.0.1 1024
        Client: hi
	Server: hello

	Client: how are you
	Server: fine

	Client: 
	
Server
	./server 1024
	Client: hi

	Server: hello
	Client: how are you

	Server: fine



