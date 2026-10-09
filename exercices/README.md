# C Exercises — Arrays, Statistics and CSV Records

Two standalone exercises exploring numerical arrays and structured text persistence.

## Sources

| File | Scope |
|---|---|
| [`tp1_vecteurs_statistiques.c`](src/tp1_vecteurs_statistiques.c) | Vector handling and elementary statistics |
| [`tp2_fiches_etudiants_csv.c`](src/tp2_fiches_etudiants_csv.c) | Student records and CSV file operations |

## Compilation workflow

From this module directory:

```bash
mkdir -p build
cc -std=c11 -Wall -Wextra -Wpedantic -g src/tp1_vecteurs_statistiques.c -o build/tp1
```

Inspect any emitted diagnostics before execution. The CSV exercise is a draft and should be reviewed before building or using real records.

## Memory and I/O review

Keep file handles as `FILE *`, distinguish line buffers from record structures and check `fopen`, reads and writes. Parsing must bound strings and verify field counts before constructing a record.

The archived CSV exercise contains incompatible pointer declarations and an incomplete reading path. It writes `database.csv` in its working directory. Test only on disposable input after correcting these issues.

## Validation and licence

Compiler diagnostics are the first check of declarations and conversions; runtime inspection then addresses buffer bounds and file-processing behaviour. No project-wide licence has been defined.
