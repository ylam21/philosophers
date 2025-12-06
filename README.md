# Philosophers
This project is part of the **42 Prague curriculum**.<br>
The program tackles the [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).<br>
The program logs every state change (taking a fork, eating, sleeping, thinking, dying) with a timestamp in milliseconds.<br>
## Build
Build the executable binary:<br>
```sh
make all
```
## Usage
arg 0: binary executable<br>
arg 1: **number_of_philosophers**<br>
arg 2: **time_to_die** <br>
arg 3: **time_to_eat**<br>
arg 4: **time_to_sleep**<br>
arg 5 (optional): **number_of_times_each_philosopher_must_eat**<br>

```sh
bin/philo 6 800 200 200 100
```

## Test
```checker.sh``` is provided under ```test```folder.<br>
**Example usage:**
1. Redirect the output of the program to a logfile.<br>
```sh
bin/philo 6 800 200 200 100 > log
```
2.1 Run the checker program against the logfile.<br>
2.2 Provide the number of philos to check.<br>
```sh
test/checker.sh <logfile> <number_of_philos>
```
