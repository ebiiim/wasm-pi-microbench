package main

import (
	"fmt"
	"math/rand"
	"syscall/js"
	"time"
)

func mcpi(loop int) float64 {
	c := 0
	rnd := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := 0; i < loop; i++ {
		x, y := rnd.Float64(), rnd.Float64()
		if x*x+y*y <= 1 {
			c++
		}
	}
	return float64(c) / float64(loop) * 4.0
}

func main() {
	const iter = 100000000
	start := time.Now()
	pi := mcpi(iter)
	elapsed := time.Since(start)
	log1 := fmt.Sprintf("elapsed time: %v ms", elapsed.Nanoseconds()/1000000)
	log2 := fmt.Sprintf("iterations: %d, estimated value: %v", iter, pi)
	fmt.Printf("%s\n%s\n", log1, log2)
	js.Global().Get("document").Call("getElementById", "resultGo").Set("innerHTML", fmt.Sprintf("%s<br>%s", log1, log2))
}
