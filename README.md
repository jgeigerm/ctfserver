CTFServer
=========
Easily deploy ctf challenges that involve a client/server model.

Use on Linux.

How To
------
Include ctfserver.h

Inititalize the server with ctfserver(handler) in main

Define a handler function of type void that takes a void pointer as an argument

Compile and run.

Check out the test program!

Forking vs. Threading
---------------------
This can either fork new processes when accepting connections or just run multithreaded

Generally if you expect the user to crash the process then it should be fork based

Otherwise, threads are good.

By default it uses forking

To use threading, compile with -DCTF_THREADS

Customizing Buffersize, Connection Limit, and Port Number
---------------------------------------------------------
You can do this with the use of the -DCTF_SPEC compile flag

Make a header file called ctfspec.h and put options in there

Options that are not defined in ctfspec.h will be set to defaults

Available Functions
-------------------
**bool ctfserver(void (*handler)(void *))**

- Takes a function name to handle connecitons with. This is what users connecting to the server will be able to interact with. Returns false if there was an error.

**bool rprintf(sock rsock, char *fmt, ...)**

- Print to a remote socket, allows format string like printf. Returns false if the socket had an error.

**bool rgets(sock rsock, char *rBuf)**

- Get input from the remote socket and put it in rBuf. Returns false if the socket had an error.

**bool send_flag(char *msg)**

- Send the flag to the user. Returns false if the socket had an error.


Defaults
--------
MAX_CONNECTIONS 30

PORT 12345

BUFSIZE 1024

DISCLAIMER
----------
Don't use this on a system you care about. It is meant for CTFs and stuff like that

I'm not a secure software engineer so any bugs or security bugs you may find should be reported to me

I will not be responsible if your computer gets owned while using this.

I will probably laugh at you.


Todo
----
Make everything even more internal

Commenting
