Third school project. Repeated calls to get_next_line() function should read the text file pointed to by the file descriptor, one line at a time (including the terminating '\n' character). Function returns the line that was read. If there is nothing else to read or if an error occurred, it should return NULL. Function should work as expected reading from a file or stdin.
Bonus part handles multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd.