package main

func Hack(start string) []string {
	finalResult := []string{}

	tempResult := Retrieve(start)
	finalResult = append(finalResult, tempResult...)

	ch := make(chan []string, len(tempResult))

	for _, v := range tempResult {
		go func(str string) {
			ch <- Hack(str)
		}(v)
	}

	for i := 0; i < len(tempResult); i++ {
		finalResult = append(finalResult, (<-ch)...)
	}
	return finalResult
}
