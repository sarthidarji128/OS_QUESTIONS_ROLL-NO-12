
import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind(('localhost', 12345))
while True:
    message, client_address = server_socket.recvfrom(1024)
    server_socket.sendto(message, client_address)


client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
client_socket.sendto(b'Hello, Server!', ('localhost', 12345))
response, server_address = client_socket.recvfrom(1024)
client_socket.close()
