# Dynamic-generic-ring-C

A useful Dynamic generic ring structure made in C Language. Maybe is not easy to understand the ring data structure functionality, but whan you start to, you look for data structures likes ring buffer and see the power and potential of this. A ring can be use to perform iterative actions, for example, perform a week representation as a ring is a great idea, just imagine:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; mon → tue → wed → thu → fri → sat → sun

Performing as a ring, the structure look like this... 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ... ⇌ sun ⇌ mon ⇌ tue ⇌ wed ⇌ thu ⇌ fri ⇌ sat ⇌ sun ⇌ mon ⇌ ...

So,... When you want to know the day after the Sunday, you just need to ask! The Sunday itself know the day before and next to it.

This is one simple example of the ring structure functionality, but, any structure that you can loop it and strart from the begining may be a ring, just like the week, a circular buffer, some enum cases and even a voleyball team position representation.
