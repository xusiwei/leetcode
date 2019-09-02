package main

import "fmt"

type Foo struct {
    c12 chan bool
    c23 chan bool
    done chan bool
}

func NewFoo() *Foo {
    return &Foo {
        c12: make(chan bool, 1),
        c23: make(chan bool, 1),
        done: make(chan bool),
    }
}


func (self *Foo) first(printFirst func()) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    self.c12 <- true
}

func (self *Foo) second(printSecond func()) {
    <- self.c12
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    self.c23 <- true
}

func (self *Foo) third(printThird func()) {
    <- self.c23
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    self.done <- true
}


func main()  {
    foo := NewFoo()
    go foo.first(func() {
        fmt.Printf("first")
    })
    go foo.second(func () {
        fmt.Printf("second")
    })
    go foo.third(func () {
        fmt.Printf("third")
    })

    <- foo.done
}