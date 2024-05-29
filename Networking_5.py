# TCP Server
import socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))
server_socket.listen(1)
connection, client_address = server_socket.accept()
number = int(connection.recv(1024))
response = b'Even' if number % 2 == 0 else b'Odd'
connection.sendall(response)
connection.close()
server_socket.close()

# TCP Client
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 12345))
client_socket.sendall(b'2')
response = client_socket.recv(1024)
client_socket.close()

