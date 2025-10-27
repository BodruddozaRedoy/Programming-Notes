# C Programming Methods Collection

A comprehensive collection of C programming examples demonstrating various string, array, and object manipulation methods. Each method is implemented using both raw (manual) approaches and built-in library functions, organized by difficulty levels.

## 📁 Project Structure

```
Phitron/Notes/
├── String Methods/
│   ├── Basic/           # Fundamental string operations
│   ├── Intermediate/    # Intermediate string manipulations
│   └── Advance/         # Advanced string algorithms
├── Array Methods/
│   ├── Basic/           # Basic array operations
│   ├── Intermediate/    # Intermediate array manipulations
│   └── Advance/         # Advanced array algorithms
├── Object Methods/
│   ├── Basic/           # Basic object operations
│   ├── Intermediate/    # Intermediate object manipulations
│   └── Advance/         # Advanced object operations
├── README.md
└── .gitignore
```

## 🎯 Learning Objectives

This collection helps you understand:
- **Raw Implementation**: How to implement functionality from scratch
- **Built-in Functions**: How to use C standard library functions
- **Performance Comparison**: Differences between manual and optimized approaches
- **Best Practices**: When to use which approach

## 📚 String Methods

### Basic Level
- `string_length.c` - Calculate string length (raw vs strlen)
- `string_compare.c` - Compare two strings (raw vs strcmp)
- `string_concatenate.c` - Concatenate strings (raw vs strcat)
- `string_copy.c` - Copy strings (raw vs strcpy)
- `string_reverse.c` - Reverse string characters
- `string_palindrome.c` - Check if string is palindrome

### Intermediate Level
- `string_count_characters.c` - Count specific characters
- `string_remove_spaces.c` - Remove spaces from string
- `string_sort_characters.c` - Sort string characters
- `string_substring_search.c` - Find substring in string
- `string_to_lower.c` - Convert to lowercase (raw vs tolower)
- `string_to_upper.c` - Convert to uppercase (raw vs toupper)
- `string_toggle_case.c` - Toggle character cases
- `string_vowel_count.c` - Count vowels in string
- `string_word_count.c` - Count words in string

### Advance Level
- `string_anagram_check.c` - Check if strings are anagrams
- `string_frequency_of_characters.c` - Calculate character frequency
- `string_join.c` - Join multiple strings
- `string_remove_duplicates.c` - Remove duplicate characters
- `string_replace_substring.c` - Replace substring in string
- `string_split.c` - Split string into tokens

## 📊 Array Methods

### Basic Level
- `array_length.c` - Get array length
- `array_access.c` - Access array elements
- `array_search.c` - Search elements in array
- `array_print.c` - Print array elements
- `array_sum.c` - Calculate array sum

### Intermediate Level
- `array_sort.c` - Sort array elements (bubble sort vs qsort)
- `array_reverse.c` - Reverse array elements
- `array_copy.c` - Copy array elements (raw vs memcpy)
- `array_max_min.c` - Find maximum and minimum values
- `array_duplicate.c` - Check for duplicate elements

### Advance Level
- `array_merge_sort.c` - Merge sort implementation
- `array_binary_search.c` - Binary search algorithm
- `array_matrix_multiply.c` - Matrix multiplication
- `array_quick_sort.c` - Quick sort implementation
- `array_rotate.c` - Array rotation algorithms

## 🏗️ Object Methods

### Basic Level
- `object_create.c` - Create objects (stack vs heap)
- `object_access.c` - Access object properties
- `object_compare.c` - Compare objects
- `object_copy.c` - Copy objects (shallow vs deep)

### Intermediate Level
- `object_array.c` - Object array management
- `object_sort.c` - Sort objects by different fields
- `object_search.c` - Search objects in collections
- `object_filter.c` - Filter objects based on criteria

### Advance Level
- `object_serialize.c` - Object serialization/deserialization
- `object_hash.c` - Object hashing and hash tables
- `object_polymorphism.c` - Polymorphic object behavior
- `object_memory.c` - Advanced memory management

## 🚀 Getting Started

### Prerequisites
- C compiler (GCC, Clang, or MSVC)
- Make (optional, for building)

### Compilation
```bash
# Compile individual files
gcc -o output filename.c

# Compile with all warnings
gcc -Wall -Wextra -o output filename.c

# Compile with debugging info
gcc -g -o output filename.c
```

### Running Examples
```bash
# Run compiled program
./output

# On Windows
output.exe
```

## 📖 Code Structure

Each file follows a consistent pattern:

```c
#include <stdio.h>
#include <string.h>  // or other necessary headers

// RAW METHOD - Manual implementation
return_type function_name_raw(parameters) {
    // Manual implementation
}

// BUILT-IN METHOD - Using library functions
return_type function_name_builtin(parameters) {
    // Built-in implementation
}

int main() {
    // Test both implementations
    // Compare results
    return 0;
}
```

## 🔍 Key Concepts Demonstrated

### Memory Management
- Stack vs Heap allocation
- Dynamic memory allocation
- Memory leaks prevention
- Memory pools

### Algorithm Complexity
- Time complexity analysis
- Space complexity considerations
- Performance comparisons

### Data Structures
- Arrays and dynamic arrays
- Linked lists (in object examples)
- Hash tables
- Stacks and queues

### Advanced Topics
- Function pointers
- Polymorphism in C
- Serialization techniques
- Hashing algorithms

## 🛠️ Development Guidelines

### Code Style
- Consistent naming conventions
- Clear comments and documentation
- Proper error handling
- Memory cleanup

### Testing
- Test with various inputs
- Edge case handling
- Performance benchmarking
- Memory leak detection

## 📈 Performance Notes

- **Raw Methods**: Often more educational, may be less optimized
- **Built-in Methods**: Usually optimized, use standard library functions
- **Memory Usage**: Consider stack vs heap allocation
- **Time Complexity**: Understand Big O notation implications

## 🤝 Contributing

1. Follow the existing code structure
2. Add comprehensive comments
3. Include both raw and built-in implementations
4. Test thoroughly
5. Update documentation

## 📝 License

This project is for educational purposes. Feel free to use and modify for learning.

## 🎓 Learning Path

1. **Start with Basic**: Understand fundamental concepts
2. **Move to Intermediate**: Learn optimization techniques
3. **Advance to Advanced**: Master complex algorithms
4. **Compare Approaches**: Understand trade-offs
5. **Apply Knowledge**: Use in real projects

## 🔗 Additional Resources

- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)
- [C Programming Best Practices](https://www.gnu.org/prep/standards/html_node/Writing-C.html)

---

**Happy Coding! 🚀**

*This collection is designed to help you master C programming through practical examples and comparisons between different implementation approaches.*
