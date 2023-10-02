# push_swap
> Sorting numbers between two stacks

</p>
<p align="center">
	<a href="#about">About</a> •
	<a href="#usage">Usage</a> •
	<a href="#norme">Norme</a>
</p>

## About
Development of a sorting algorithm program in the C programming language. The project involves sorting a list of integers using two stacks, named 'a' and 'b,' and a set of operations, including swapping elements, pushing elements between stacks, rotating elements, and more. The goal is to sort the stack 'a' in ascending order with the fewest possible operations.

The objective of this project is to teach the student how to develop a basic algorithm while deepening their knowledge of the C programming language and concepts such as linked lists.

## Usage
#### 1st - Clone the repository
``` bash
git@github.com:MartimPinto/push_swap.git
```
#### 2nd - Enter the project folder and run Make or Make bonus
``` bash
cd push_swap

make
```
#### 3rd - Run the Program
You can run the program with all numbers in one argument or use multiple arguments
```bash
$ ./push_swap [nbr] [nbr] [nbr] [nbr] [nbr] ...
```
or
```bash
$ ./push_swap ["number number number number ...."]
```
### Visualizer
In order to better visualize the program in action, we are going to use the program [**push_swap_visualizer**](https://github.com/o-reo/push_swap_visualizer) which you will have to download from it's Git repository.

#### 1st - Clone the repository
```bash
$ ./git clone git@github.com:o-reo/push_swap_visualizer.git
```
#### 2nd - Move `push_swap_visualizer` into the `push_swap` folder <br>

#### 3rd - Inside push_swap_visualizer:
```bash
$ ./mkdir build
```
#### 4th - Inside build:
```bash
$ ./cmake ..
$ ./make
```
#### 5th - Run the visualizer
```bash
$ ./bin/visualizer
```
<br>

## Norme

All 42 projects must be written following the **Norme**.

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
 	- Each line must be at most 80 columns wide, comments included
	- A function can take 4 named parameters maximum
	- No more than 5 variables in 1 function

