
import socket
import select

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind(('localhost', 12345))
sockets_list = [server_socket]

while True:
    read_sockets, _, _ = select.select(sockets_list, [], [])
    for notified_socket in read_sockets:
        message, client_address = notified_socket.recvfrom(1024)
        notified_socket.sendto(message, client_address)
