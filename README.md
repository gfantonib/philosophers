# philosophers
This project aims to create a simulation of the famous 'Dining Philosophers' problem. \
In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.\
It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present form.

<!-- <div style="display: flex; justify-content: center;">
  <div style="text-align: center; margin-right: 5%;">
    <img src="image/edsger_dijkstra.png" alt="Image 1" style="width: 200px;" />
    <p>Edsger Dijkstra</p>
  </div>
  <div style="text-align: center;">
    <img src="image/tony_hoare.png" alt="Image 2" style="width: 200px;" />
    <p>Tony Hoare</p>
  </div>
</div> -->

<p align="center">
  <img src="image/edsger_dijkstra.png" alt="Image 1" width="200" style="margin-right: 10px;">
  <img src="image/tony_hoare.png" alt="Image 2" width="200">
</p>
<p align="center">
  <span>Edsger Dijkstra</span>
  <span style="margin-left: 210px;">Tony Hoare</span>
</p>

##### Rules of the simulation:
- One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep. \
While they are eating, they are not thinking nor sleeping; \
while thinking, they are not eating nor sleeping; \
and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying.

