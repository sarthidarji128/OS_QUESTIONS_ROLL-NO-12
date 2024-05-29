# TCP Server
import socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))
server_socket.listen(1)
connection, client_address = server_socket.accept()
message = connection.recv(1024)
connection.sendall(message[::-1])
connection.close()
server_socket.close()

# TCP Client
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 12345))
client_socket.sendall(b'Hello, Server!')
response = client_socket.recv(1024)
client_socket.close()
