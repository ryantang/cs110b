# Assignment 1
## Summary

This first assignment takes in a single command line input in the format of MM/DD/YY.  If the product of the month and day is equal to the two-digit year, it outputs "That is a magic date". Otherwise it outputs "That is not a magic date". 

## Notes

The main insight of this assignment is how `cin` interacts with type `int`. A typical approach would be to read in the string of "MM/DD/YY" and to split along `/`.  Instead, this assignment has us read in `cin` into three `int` variables, requiring a deeper understanding of how to manipulate `cin` and `>>`. To me, the key understanding is that `cin >> myInt` stops reading cin when it hits a non-numeric number. At that point we can use `cin.ignore()` to skip the `/`, and then proceed to `cin >> myNextInt`.

Here's a concrete example. Suppose the input contained `10/8/22\n`.  Then, `cin >> month` (where month is type `int`) would read in `10` and stop at `/`, which cannot be part of an integer.  The contents of `cin` is now `/8/22\n`.  Calling `cin.ignore()` would drop the next character and leave the contents as `8/22\n`. At this point we can proceed with `cin >> day`.