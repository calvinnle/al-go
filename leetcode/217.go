package main

func containsDuplicate(a []int) bool {
	visited := make(map[int]int)

	for idx, val := range a {
		_, exists := visited[val]

		if exists {
			return true
		}
		visited[val] = idx 
	}
	return false
}

// func main() {
// 	a := []int{1,2,45,6}
//
// 	res := containsDuplicate(a)
//
// 	fmt.Println(res)
// }
