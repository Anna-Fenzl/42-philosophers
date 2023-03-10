# Philosophers
This is a project for [42Heilbronn](https://www.42heilbronn.de/en/curriculum/) school's curriculum.
The goal of the project is to write a program simulating a group of philosophers who sit at a round table and alternately eat, think, or sleep.

## Rules
+ One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
+ The philosophers alternatively eat, think, or sleep.
+ There are as many forks as philosophers.
+ A philosopher needs two forks to eat spagetti.
+ When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
+ Every philosopher needs to eat and should never starve.
+ Philosophers don’t speak with each other.
+ Philosophers don’t know if another philosopher is about to die.
+ No need to say that philosophers should avoid dying!

## Description
**run _`make`_ or __`make_bonus`__**

The program will be executed as follows:

__`./philosophers  num_of_philosopers  time_to_die  time_to_eat  time_to_sleep  [num_of_times_each_philo_must_eat]`__

+ __time_to_die__ (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
+ __time_to_eat__ (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
+ __time_to_sleep__ (in milliseconds): The time a philosopher will spend sleeping.
+ __number_of_times_each_philosopher_must_eat__ (optional argument): If all
philosophers have eaten at least this much times the simulation stops

i.e:
```
$>./philosophers 4 800 200 200 5
```

To visualize the behavior of the philosopers, just insert the output in this [Visualizer](https://nafuka11.github.io/philosophers-visualizer/).
The times shouldn't be smaller than 60 and there shouldn't be more than 200 philosphers. 

## Mandatory part
+ Each of the philosophers is a __thread__.
+ There is the same amount of forks as there are philosophers.
+ Each philosopher has a fork on their __left and their right__ side.
+ The forks state should be protected using __mutexes__.

## Bonus part
+ Each of the philosophers is a __process__.
+ There is the same amount of forks as there are philosophers.
+ The forks are placed in the __middle of the table__.
+ They have no states in memory but the number of available forks is represented by
a __semaphore__.


## What i learned:
+ how to create and use `threads` with the <pthread.h> 
+ using `mutexes` and `semaphores`, to prevent data races.
+ preventing `deadlocks` and `livelocks`
