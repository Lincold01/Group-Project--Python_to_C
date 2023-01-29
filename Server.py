import socket
import os

def handle_client(client_socket):
    request = client_socket.recv(1024)
    response = request.decode() + " from server xyz"
    client_socket.send(response.encode())
    client_socket.close()

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(("0.0.0.0", 8080))
server_socket.listen(5)

while True:
    conn, addr = server_socket.accept()
    pid = os.fork()
    if pid == 0:
        server_socket.close()
        handle_client(conn)
        os._exit(0)
    else:
        conn.close()


