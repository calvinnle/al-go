package main

import (
	"sort"
	"strings"
)

func groupAnagrams(strs []string) [][]string {
	mp := make(map[string][]string) // Equivalent to unordered_map<string, vector<string>> in C++

	for _, str := range strs {
		// Sort the string to create a key
		sortedStr := sortString(str)
		// Add the original string to the map
		mp[sortedStr] = append(mp[sortedStr], str)
	}

	// Convert the map to a slice of slices
	result := [][]string{}
	for _, group := range mp {
		result = append(result, group)
	}

	return result
}

// Helper function to sort a string
func sortString(s string) string {
	runes := []rune(s) // Convert string to a slice of runes
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})
	return string(runes) // Convert the sorted runes back to a string
}

func main() {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	grouped := groupAnagrams(strs)

	for _, group := range grouped {
		println(strings.Join(group, ", "))
	}
}
