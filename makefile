cflags = -I. -Wall -Wextra
#CC     = clang++ -std=c++11
CC     = g++ -std=c++11

AREA51  = /home/courses/cop3330p/LIB/area51

all:         clients benchmarks
clients:     fqueue.x constTest.x in2post.x
benchmarks:  fqueue_char_i.x fqueue_int_i.x in2post_i.x fqueue_char_reuse_i.x fqueue_String_i.x

# build executables

fqueue.x: fqueue.o
        $(CC) -o fqueue.x fqueue.o

constTest.x: constTest.o
        $(CC) -o constTest.x constTest.o
in2post.x: in2post.o
	$(CC) -o in2post.x in2post.o

# build object code files



fqueue.o: tqueue.h  fqueue.cpp
        $(CC) $(cflags) -c fqueue.cpp

constTest.o: tqueue.h constTest.cpp
        $(CC) $(cflags) -c constTest.cpp
in2post.o: tqueue.h in2post.cpp
	$(CC) $(cflags) -c in2post.cpp
# build benchmarks

fqueue_char_i.x: /home/courses/cop3330p/LIB/area51/fqueue_char_i.x
        cp  /home/courses/cop3330p/LIB/area51/fqueue_char_i.x .
        chmod 700 fqueue_char_i.x

fqueue_char_reuse_i.x: /home/courses/cop3330p/LIB/area51/fqueue_char_reuse_i.x
        cp /home/courses/cop3330p/LIB/area51/fqueue_char_reuse_i.x .
        chmod 700 fqueue_char_reuse_i.x

fqueue_int_i.x: /home/courses/cop3330p/LIB/area51/fqueue_int_i.x
        cp /home/courses/cop3330p/LIB/area51/fqueue_int_i.x .
        chmod 700 fqueue_int_i.x

fqueue_String_i.x: /home/courses/cop3330p/LIB/area51/fqueue_String_i.x
        cp /home/courses/cop3330p/LIB/area51/fqueue_String_i.x .
        chmod 700 fqueue_String_i.x

in2post_i.x: /home/courses/cop3330p/LIB/area51/in2post_i.x
        cp /home/courses/cop3330p/LIB/area51/in2post_i.x .
        chmod 700 in2post_i.x
