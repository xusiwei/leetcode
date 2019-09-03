package main

import "fmt"
import "time"
import "sync"
import "runtime"

type H2O struct {
	H int
	O int
	m *sync.Mutex
	c *sync.Cond
}

func NewH2O() *H2O {
	h2o := new(H2O)
	h2o.H = 0
	h2o.O = 0
	h2o.m = &sync.Mutex{}
	h2o.c = sync.NewCond(h2o.m)
	return h2o
}

// H2
func (self *H2O) hydrogen(releaseHydrogen func()) {
	self.m.Lock()
	for self.H >= 2 {
		self.c.Wait()
	}

	// releaseHydrogen() outputs "H". Do not change or remove this line.
	releaseHydrogen()

	self.H += 1
	if self.H == 2 && self.O == 1 {
		self.H = 0
		self.O = 0
		self.c.Broadcast()
	}
	self.m.Unlock()

	// self.finish <- true
}

// O2
func (self *H2O) oxygen(releaseOxygen func()) {
	self.m.Lock()
	for self.O >= 1 {
		self.c.Wait()
	}

	// releaseOxygen() outputs "O". Do not change or remove this line.
	releaseOxygen()

	self.O += 1
	if self.H == 2 && self.O == 1 {
		self.H = 0
		self.O = 0
		self.c.Broadcast()
	}
	self.m.Unlock()
}

func main() {
	input := "OOOOHHHHHHHH"
	// input := "OOHHHH"

	h2o := NewH2O()
	//h2o.finish = make(chan bool, len(input))

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
			go h2o.oxygen(func() { printChar('O') })
		}
	}

	runtime.Gosched()
	time.Sleep(1 * time.Second)

	fmt.Println("input:", input, len(input))
	fmt.Println("output:", output, len(output))
}
