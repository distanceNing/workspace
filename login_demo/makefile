obj=dal.o bll.o \
	tcp_socket.o  mysql_data.o mysql_cpp.o main.o


VPATH=net_helper sql_helper bll dal 

demo:$(obj)
	g++    -o demo $(obj) -I/usr/include/mysql -L/usr/lib/mysql -lpthread -lmysqlclient 

main.o:common.h tcp_socket.h main.cpp

bll.o:dal.h bll.cpp

tcp_socket.o:tcp_socket.h

dal.o: mysql_cpp.h mysql_data.h dal.cpp

mysql_data.o:mysql_data.h 

mysql_cpp.o:mysql_cpp.h mysql_data.h  uncopyable.h


.PHONY:clean
clean:
	-rm $(obj) demo client

