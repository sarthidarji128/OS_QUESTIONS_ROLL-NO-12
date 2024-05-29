# Server remains the same
import socket
# UDP Client
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
while True:
    message = input().encode()
    client_socket.sendto(message, ('localhost', 12345))
    if message == b'exit':
        break
    response, server_address = client_socket.recvfrom(1024)
client_socket.close()
