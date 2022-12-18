# minitalk

Basic communication between a server and a client using only unix signals SIGUSR1 and SIGUSR2.

The client receives a string as parameter and sends it to the server using two SIGUSR

The server listen to the signals and read it as binary data, converts and print the string on the screen.
