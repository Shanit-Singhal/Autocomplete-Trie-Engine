# Autocomplete Search Engine – C++17

## Features
- Fast prefix-based word suggestions using Trie (O(L) time complexity)
- Frequency-based result ranking using hash maps
- Suggests top-k relevant results (default: 5)
- Fully C++17-compatible with no external dependencies

## Tech Stack
- Language: C++11
- Data Structures: Trie, Hash Map, Vector, Lambda Functions

## Sample Run
Enter prefix to autocomplete (or type 'exit'): co
Suggestions:
 - code
 - coder
 - coding
 - codeforces
 - codex

Enter another prefix (or type 'exit'): cook
Suggestions:
 - cooking
 - cook

## How to Compile and Run

g++ -std=c++17 autocomplete.cpp -o autocomplete
./autocomplete

## Example Dataset

code, coder, coding, codeforces, codex, cooking, cook, cool, company, compare

## Author 

Shanit Singhal
<br>
shanitsinghal31@gmail.com,
<br>
🔗 https://github.com/your-shanit-singhal/autocomplete-engine
