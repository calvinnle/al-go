package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
	"math"
)

func main() {
	// Open the input file
	file, err := os.Open("input.txt")
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	var list1, list2 []int
	scanner := bufio.NewScanner(file)

	// Read the file line by line
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Fields(line) // Split by whitespace
		if len(parts) != 2 {
			fmt.Println("Invalid line:", line)
			continue
		}
		a, err1 := strconv.Atoi(parts[0]) // Parse first number
		b, err2 := strconv.Atoi(parts[1]) // Parse second number
		if err1 != nil || err2 != nil {
			fmt.Println("Error parsing numbers on line:", line)
			continue
		}
		list1 = append(list1, a)
		list2 = append(list2, b)
	}

	// Sort the two lists
	sort.Ints(list1)
	sort.Ints(list2)

	// Calculate the total distance
	totalDistance := 0
	for i := 0; i < len(list1); i++ {
		totalDistance += int(math.Abs(float64(list1[i] - list2[i])))
	}


	fmt.Println("Total Distance:", totalDistance)
}
