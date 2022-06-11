# Short-Term-Scheduler
This is an implementation, in language C, of the Short-Term-Scheduler also known as CPU scheduler. This helps you to select from a group of processes that are ready to execute and allocates CPU to one of them.
## Usage
```
make
./sts input.txt
```
input.txt must be like this:
```
#NumOfProcesses QuantumTime
Name1 Burst Priority
Name2 Burst Priority
...
NameN Burst Priority
```

Example:
```
# 3 10
P1 16 3
P2 8 1
P3 10 2
```
