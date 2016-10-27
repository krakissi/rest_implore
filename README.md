rest_implore
------------

Basic command-line tool for quickly generating HTTP requests. This tool
can be used to test REST APIs.

Build Output
------------

`rest_implore` is the actual binary which turns your shorthand
approximation of HTTP into something your remote server can actually
use.

`rest_request` is a bash script which pipes the output of rest_implore
into netcat for convenience sake. You can edit this script to set the
appropriate server and port values for the request, or specify them at
runtime. (i.e. `server="127.8.9.10" port="8085" rest_request`)
