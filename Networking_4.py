# Server with threading
import socket
import threading

def handle_client(connection):
    message = connection.recv(1024)
    connection.sendall(message[::-1])
    connection.close()

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))
server_socket.listen(5)

while True:
    connection, client_address = server_socket.accept()
    client_thread = threading.Thread(target=handle_client, args=(connection,))
    client_thread.start()

