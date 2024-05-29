# TCP Server
import socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))
server_socket.listen(1)
connection, client_address = server_socket.accept()
file_name = connection.recv(1024).decode()
with open(file_name, 'r') as file:
    connection.sendall(file.read().encode())
connection.close()
server_socket.close()

# TCP Client
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 12345))
client_socket.sendall(b'example.txt')
file_content = client_socket.recv(1024)
client_socket.close()
