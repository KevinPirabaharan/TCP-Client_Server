# **TCP Client & Server**
This is a repository comprises of 2 programs that act as a TCP server application and a TCP client application to send and received text data and storing it on a local text file.
The client and server has been modified to implement a new TCP based protocol. The server has been updated to support multiple clients and take advantage of threading using Pthreads.

HINT: The portnumbers and addresses should be hardcoded into the program.
*****************
## **Build/Compilation Commands**
| Command | Description |
| ----------- | ----------- |
| **make all** | This creates the executables for server and client. |
| **make test** | This creates all the clients to test code with. |
| **make server** | This creates the executable for server only. |
| **make clean** | This removes all executables from the directory. |

*****************
## **Run Commands**
| Command | Description |
| ----------- | ----------- |
| **./bin/server** | This runs the server program. |
| **./bin/client** | This runs the client program. |
| **chmod u+x script.sh** | Initializes script for multi-clients |
| **./script.sh** | Automates and runs dummy clients to post to server |
