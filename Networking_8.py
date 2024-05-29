# Server sends a list of files before sending the requested file
import socket
# TCP Client
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 12345))
file_list = client_socket.recv(1024).decode().split(',')
file_name = input('Enter file name from list: ').encode()
client_socket.sendall(file_name)
file_content = client_socket.recv(1024)
client_socket.close()
