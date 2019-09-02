package main

import "fmt"
import "time"
import "sync"
import "runtime"

type H2O struct {
	H chan int
	O chan int
	finish chan bool
}

func NewH2O() *H2O {
	h2o := new(H2O)
	h2o.H = make(chan int, 2)
	h2o.O = make(chan int, 1)
	return h2o
}


// H2
func (self *H2O) hydrogen(releaseHydrogen func()) {
	self.H <- 2

	// releaseHydrogen() outputs "H". Do not change or remove this line.
	releaseHydrogen();

	<-self.O

	// self.finish <- true
}

// O2
func (self *H2O) oxygen(releaseOxygen func()) {
	self.O <- 2
	// releaseOxygen() outputs "O". Do not change or remove this line.
	releaseOxygen();


	// self.finish <- true
}

func main() {
	input := "OOOOHHHHHHHH"
	// input := "OOHHHH"

	h2o := NewH2O()
	h2o.finish = make(chan bool, len(input))

	count := 0
	output := ""
	mutex := &sync.Mutex{}
	printChar := func(ch int) {
		mutex.Lock()
		count++
		output = output + string(ch)
		fmt.Printf("%d: %c\n", count, ch)
		mutex.Unlock()
	}

	for _, ch := range input {
		// fmt.Println(i, ch)
		if ch == 'H' {
			go h2o.hydrogen(func() { printChar('H') })
		} else {
			go h2o.oxygen(func () { printChar('O') })
		}
	}

	runtime.Gosched()
	time.Sleep(1 * time.Second);

	for i := 0; i < len(input); i++ {
		<-h2o.finish
	}

	fmt.Println("input:", input, len(input))
	fmt.Println("output:", output, len(output))
}