package main

import "fmt"

type ZeroEvenOdd struct {
	n int
	odd_in chan int
	zero_in chan int
	even_in chan int
	done chan bool
}

func NewZeroEvenOdd(n int) *ZeroEvenOdd {
	self := new(ZeroEvenOdd)
	self.n = n
	self.odd_in = make(chan int, 1)
	self.zero_in = make(chan int, 1)
	self.even_in = make(chan int, 1)
	self.done = make(chan bool, 1)
	self.zero_in <- 1 // tricky for zero routine start
	return self
}

// zero -> odd -> zero -> even -> zero ...

// printNumber(x) outputs "x", where x is an integer.
func (self *ZeroEvenOdd) zero(printNumber func(int)) {
	for i := 0; i < self.n; i++ {
		x := <-self.zero_in
		printNumber(0)
		if x % 2 == 1 {
			self.odd_in <- x
		} else {
			self.even_in <- x
		}
	}
}

func (self *ZeroEvenOdd) odd(printNumber func(int)) {
	for i := 1; i <= self.n; i += 2 {
		x := <-self.odd_in
		printNumber(x)
		if x == self.n {
			self.done <- true
		} else {
			self.zero_in <- x+1
		}
	}
}

func (self *ZeroEvenOdd) even(printNumber func(int)) {
	for i := 2; i <= self.n; i += 2 {
		x := <-self.even_in
		printNumber(x)
		if x == self.n {
			self.done <- true
		} else {
			self.zero_in <- x+1
		}
	}
}

func main() {
	z := NewZeroEvenOdd(10)
	count := 0
	printNumber := func (n int) {
		count++
		fmt.Printf("%d: %d\n", count, n)
	}
	go z.zero(printNumber)
	go z.even(printNumber)
	go z.odd(printNumber)
	<-z.done
}