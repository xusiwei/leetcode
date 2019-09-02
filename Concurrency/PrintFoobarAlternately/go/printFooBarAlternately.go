package main

import "fmt"

type FooBar struct {
	n int
	c1 chan bool
	c2 chan bool
	done chan bool
}

func NewFooBar(n int) *FooBar {
	self := new(FooBar)
	self.n = n
	self.c1 = make(chan bool, 1)
	self.c2 = make(chan bool, 1)
	self.done = make(chan bool, 1)
	self.c1 <- true
	return self
}

func (self *FooBar) foo(printFoo func()) {
	for i := 0; i < self.n; i++ {
		<-self.c1
		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo();
		self.c2 <- true
	}
}

func (self *FooBar) bar(printBar func()) {
	for i := 0; i < self.n; i++ {
		<-self.c2
		// printBar() outputs "bar". Do not change or remove this line.
		printBar();
		self.c1 <- true
	}
	self.done <- true
}

func main() {
	fb := NewFooBar(10)
	go fb.foo(func () {
		fmt.Printf("foo")
	})
	go fb.bar(func () {
		fmt.Printf("bar")
	})
	<-fb.done
}