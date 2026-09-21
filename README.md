# Quera Solutions

Personal solutions to [Quera programming problems](https://quera.org/problemset), organized by topic. New solutions are written in C++; some existing solutions use Python.

## Browse solutions

| Directory | Topic |
| --- | --- |
| [graph](graph/) | Graph algorithms |
| [dp](dp/) | Dynamic programming |
| [ds](ds/) | Data structures |
| [greedy](greedy/) | Greedy algorithms |
| [tech](tech/) | Technology and implementation challenges |

Each source file is a standalone solution. Filenames generally use transliterated problem names.

## Run a solution

Compile and run a C++ solution with a C++17-compatible compiler:

```bash
g++ -std=c++17 -O2 -Wall -Wextra graph/kando.cpp -o /tmp/quera-solution
/tmp/quera-solution < input.txt
```

Run a Python solution:

```bash
python3 ds/ramz.py < input.txt
```

Replace the source path with the problem you want to run and provide its input in `input.txt`.

## Solution workflow

Discuss the model, algorithm, correctness argument, and complexity together. The assistant then writes and tests the implementation. Commit and push each completed, understood solution with its Quera problem URL and concise English explanation in source comments.

The tracked repository contains completed problem solutions and repository metadata. Study plans, lesson notes, problem queues, and learning progress live in a local, Git-ignored `docs/` directory. Documentation and code explanations are in English; learning discussions are in Persian.

Local test results and acceptance by the Quera judge are recorded separately. Existing solutions have not been collectively revalidated.
