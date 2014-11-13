CTFServer
=========
Easily deploy ctf challenges that involve a client/server model.
Use on Linux.

How To
------
Include ctfserver.h<br>
Inititalize the server with ctfserver(handler) in main<br>
Define a handler function of type void that takes a void pointer as an argument<br>
Compile and run.

Forking vs. Threading
---------------------
This can either fork new processes when accepting connections or just run multithreaded<br>
Generally if you expect the user to crash the process then it should be fork based<br>
Otherwise, threads are good.<br>

By default it uses forking<br>
To use threading, compile with -DCTF_THREADS<br>

Customizing Buffersize, Connection Limit, and Port Number
---------------------------------------------------------
You can do this with the use of the -DCTF_SPEC compile flag<br>
Make a header file called ctfspec.h and put options in there<br>
Options that are not defined in ctfspec.h will be set to defaults<br>

Defaults
--------
MAX_CONNECTIONS 30
PORT 12345
BUFSIZE 1024

DISCLAIMER
----------
Don't use this on a system you care about. It is meant for CTFs and stuff like that<br>
I'm not a secure software engineer so any bugs or security bugs you may find should be reported to me<br>
I will not be responsible if your computer gets owned while using this.<br>
I will probably laugh at you.<br>
