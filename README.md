
# Philosophers :
  * In this project, you will learn the basics of threading a process.
    You will learn how to make threads. You will discover the mutex.

## Here is a brief explanation of threads & mutex, for more details check this:
https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

### Diffrence between processes :
	1 - A process can contain multiple threads!
	2 - Adress space :
		* threads share the process memory.
		* a child process has its own memory, which is a dup of the parent process.
			==> The fact that all theads, which is being executed at the same time,
			have access to the same memory, make it possible that multiple threads can
			try to change the memory(a var) at the same time.
			==> Race conditions: when threads 1 in its process (read X, icrement X "localy",
			 write X to memory)to change a var X, and thread 2 do that as well, but stoped,
			 for some reason, at reading for a while, let suppose the the read value is 5
			 at that time, thread 2 increment var to 8 while thread 2 is still stopped with
			 a var = 5. then thread 2 is back in incrementing step of var= 5 +1; 
			 and then write var = 6.
			 That s why we should lock the var, or a block of code so it won t be executed
			 by more than 1 thread at the same time. <=> mutex !!

### mutex : Try to use when it s necessary, it makes the prog slower.
	 * we initialize it before we create the thread.
	 * and should be destroyed (the  memory whitch has been allocated).

PS: You will find the subject & the correction sheet.
    The folder test contains two samples examples to test. threads, mutex & gettimeofday.
Good luck :)!
