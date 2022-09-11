CTomorrow's Date
===============
Simple script in c for **posix systems**, this script calculates tomorrow's date given the current date.

## Usage
```console
user@machine:~$ make init && make
/usr/bin/mkdir -p builds
cc -Wall -c datetime.c -o builds/datetime.o
cc -Wall -c main.c -o builds/main.o
cc -Wall -c timeutils.c -o builds/timeutils.o
cc -Wall -o builds/main builds/datetime.o builds/main.o builds/timeutils.o

user@machine:~$ builds/./main
Today: 11/09/2022
Tomorrow: 12/09/2022
```

## About the script
The format of the date is: DD/MM/YYYYYY
