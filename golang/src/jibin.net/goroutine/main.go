package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	ch := make(chan int, 3)
	var wg sync.WaitGroup
	fmt.Println("started")
	wg.Add(2)

	go func() {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			ch <- i
			fmt.Printf("send %d\n", i)
			time.Sleep(time.Millisecond * 100)
		}
		ch <- -1
		fmt.Println("producer done")
	}()

	go func() {
		defer wg.Done()
		x := 100
		for x >= 0 {
			x = <-ch
			fmt.Printf("recv %d\n", x)
			time.Sleep(time.Millisecond * 200)
		}
		fmt.Println("cosumer done")
	}()

	wg.Wait()
	fmt.Println("done")
}
