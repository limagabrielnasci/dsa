# Shortest Completing Word

Name: Gabriel Lima Nascimento

## Problem Description
Given a string `licensePlate` and an array of strings `words`, find the shortest word in `words` that contains all the letters from `licensePlate` (ignoring numbers, spaces, and case sensitivity). If there's a tie in length, return the first one found.

## Test Cases
1. `licensePlate` = "1s3 PSt", `words` = ["step", "steps", "stripe", "stepple"]
    Result: "steps"

2. `licensePlate` = "1s3 456", `words` = ["looks", "pest", "stew", "show"]
    Result: "pest"

3. `licensePlate` = "aB2c", `words` = ["ab", "abc", "bca", "bac", "cab"]
    Result: "abc"