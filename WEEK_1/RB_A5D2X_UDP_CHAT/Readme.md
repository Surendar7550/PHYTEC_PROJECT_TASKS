RB-A5D2X UDP Chat App (Client-Server):

STEPS:

1:Connect Rb-BOARD and Ethernet
   ->click to wired setting and click "+" icon set configuration of gateway,netmask,ip
	| Item                          | Value           |
	| ----------------------------- | --------------- |
	| **Gateway (default gateway)** | `192.168.1.1`   |
	| **Netmask (subnet mask)**     | `255.255.255.0` |
	| **Device IP address**         | `192.168.1.11`  |

TERMINAL CMD
2:Go to RB_A5D2X_UDP_CHAT
  //Enable tool chain
	-> . /opt/poky-tiny/2.5.2/environment-setup-cortexa5hf-neon-poky-linux-musleabi 
	
3:Compile the server code for terminal 
	-> gcc Rb_server.c -o server

4:Cross-compile for minicom
	-> $CC Rb_client.c -o client

5:Copy client file tftp
	-> sudo cp client /var/lib/tftp/

MINICOM CMD

6:ifconfig eth0 192.168.1.20  //assign an address to a network interface

7:ping 192.168.1.11   //check the connection of our IP address

8:paste client file using tftp
	-> tftp -g -r client1 192.168.1.11
	
9:change the excutable formate
	-> chmod +x client (or) chmod 777 client
	
10:run the client code
	-> ./client1 192.168.1.11 9000   //<server_ip> <port> port defult declare in program 
	
11:run the server code in terminal
	-> ./server 9000

Output :

Client:
	root@rugged-board-a5d2x-sd1:/home/Rb_udp_chat# ./client 192.168.1.11 9000
	
	Connected to server 192.168.1.11:9000
	hi
	Client: Server: hello

	i want help!
	Client: Server: what ?

Server:

	./server 9000
	Server listening on port 9000...
	Client: hi

	Server: hello
	Client: i want help!

	Server: what ?


