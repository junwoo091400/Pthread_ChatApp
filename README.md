## How to Use
make Makefile compile

Terminal 1 : ./server 5000
Terminal 2 : ./client 5000
Terminal 3 : ./client 5000



## Questions
1. How does 'connect' function of socket.h work? How does it alter the 'socket file descriptor'?
- descriptor just holds the return value of the socket() call. So it by itself is only a reference to the connect function. To find the 'socket' it designates.


## Resources
Online codes
- https://codereview.stackexchange.com/questions/154969/c-multithreaded-chat-client-and-server
- https://github.com/nikhilroxtomar/Chatroom-in-C
- https://stackoverflow.com/questions/25542887/multithreading-in-client-server-chat-app-in-c-linux

Network
- http://beej.us/guide/bgnet/
- https://www.gta.ufrj.br/ensino/eel878/sockets/htonsman.html
- https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
- https://pubs.opengroup.org/onlinepubs/7908799/xns/recv.html
- https://pubs.opengroup.org/onlinepubs/7908799/xns/syssocket.h.html
- https://pubs.opengroup.org/onlinepubs/7908799/xns/socket.html
- 

Socket Troubleshooting
- https://stackoverflow.com/questions/16154530/storage-size-of-sockaddr-in-variable-isnt-known
- http://ps-2.kev009.com/tl/techlib/manuals/adoclib/aixprggd/progcomc/skthdrs.htm
- 

Pthread
- https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html
- https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_join.html

Markdown
- https://www.markdownguide.org/basic-syntax/

StackOverflow example debugging (Actually CodeReview one)
- https://stackoverflow.com/questions/16508685/understanding-inaddr-any-for-socket-programming
- 

String manipulation
- https://stackoverflow.com/questions/656542/trim-a-string-in-c
- 

Etc
- https://www.howtogeek.com/howto/linux/reset-your-forgotten-ubuntu-password-in-2-minutes-or-less/
- https://stackoverflow.com/questions/5134779/printing-unsigned-short-values
- https://manytools.org/hacker-tools/ascii-banner/
- https://man7.org/linux/man-pages/man3/bzero.3.html
- 

## Troubles
1. Github Authentication
remote: Support for password authentication was removed on August 13, 2021. Please use a personal access token instead.
remote: Please see https://github.blog/2020-12-15-token-authentication-requirements-for-git-operations/ for more information.
fatal: Authentication failed for 'https://github.com/junwoo091400/Pthread_ChatApp.git/'

