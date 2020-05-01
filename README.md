# Lab3
5/1/20
Program emits a status line that includes its PID to stderr
Program registers a handler for each argument
Program pauses itself continually
The handler registers itself again
The handler emits a line to stdout that indicates the signal caught and time it was caught
Program gracefully terminates after three successive SIGTERM signals
Program emits a final sttus message to stderr of the number of signals caught
