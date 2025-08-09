# Psycho_LI2

I wanted to rewind a bit to the college golden era so I started doing LI2 project again. Teachers sugested we used either unions or ```void*``` to program the Stack. In my second semester, I decided to make the correct choice and chose using a union because it was simpler and allowed for better code. Now, since I have grown up, I decided to go the psycho route and just used void pointers. Also, to make things even worse, the stack struct is not public, so I can only use functions that mess inside the Stack inside stack.c. This is also a wrong choice. However, I am an adult, so I will make it work

## Stack Structure

In order to make this a little less painfull, I decided to use linked lists. This helped me a lot since it made handling the stack very easy, and I wouldn't need to worry a lot about my memory.

I still have memory leaks because of the array if I pop it before the final execution. Many of the functions for G4 are not done. The array is inside the stack, the only indicator it is an array is the last element. It contains a Pointer to the first array element. If I want to pop the array, I just need to pop the first element. If I want to push all elements to the stack, I just need to pop the last one(this in particular is tricky and I have not done it yet, since my pop pops the whole array, not only the last element, which is cool but it means I need to have either 2 diferent pops or a pop that takes a variable number of elements, I have not decided yet since I wanted to use this project to train my C programming).

## Strings & Blocks

Will not do them, take a lot of time and I wanted to finish a good part untill the end of this week. I have other things I wanted to study so I will just leave it as it is for now, and eventually I will make something out of this. 

# Compile and run

It's ugly, I know, but just use ````make```. It compiles and runs the project. It is very poor but for now it works. It is not meant to be final, it is just useful for now.

# Todo

Finish array functions, Free array, finish function hash table and more but I remember. Feel free to look at this and gasp at how ugly it is.
