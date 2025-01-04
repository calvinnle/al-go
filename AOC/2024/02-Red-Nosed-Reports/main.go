package main

func main() {
	file_name := "input.txt"

	file, err := os.Reader(file_name)
	if err != nil {
		fmt.Errorf("error opening file %v\n", err)
	}


}
