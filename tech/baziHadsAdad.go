package main

import "fmt"

func GuessMyNumber(game Game) string {
	begin := 1
	end := 360

	for begin <= end {
		mid := (begin + end) / 2
		res := game.CheckNumber(mid)
		if res == "CORRECT" {
			return fmt.Sprintf("Your Number was %d", mid)
		}
		if res == "My Number is Lower" {
			end = mid - 1
		} else if res == "My Number is Greater" {
			begin = mid + 1
		}
	}
	return ""
}
