
client_obj=tcp_socket.o client.o

VPATH=../net_helper 




client:$(client_obj)
	g++    -o client $(client_obj)

client.o: tcp_socket.h client.cpp

tcp_socket.o:tcp_socket.h


.PHONY:clean
clean:
	-rm $(obj)  client

