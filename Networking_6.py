# Server remains the same with a loop to handle continuous connections
import socket
# TCP Client
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 12345))
while True:
    number = input().encode()
    client_socket.sendall(number)
    if number == b'exit':
        break
    response = client_socket.recv(1024)
client_socket.close()

