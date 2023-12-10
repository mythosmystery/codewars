package main

import "fmt"

func main() {
	value := ParseDeadfish("iiisdoso")
	fmt.Println(value)
}

func ParseDeadfish(data string) []int {
	value := 0
	output := []int{}

	for _, char := range data {
		switch char {
		case 'i':
			value++
		case 'd':
			value--
		case 's':
			value *= value
		case 'o':
			output = append(output, value)
		}
	}
	return output
}
