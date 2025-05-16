# Text analysis

## This C project contains the analysis of a text, in particular of Romeo and Juliet, but can be used and adapted for any other text. It's entirely written in C.

### The first files have the purpose of cleaning the text before the analysis, since we don't need words between brackets[] or the name of the character speaking. To eliminate the text between brackets it uses the opening one "[" as a flag, until it recognises the closing one "]". Then uses strtok to devide every word, while the function "is_all_upper" checks if the count of upper chars is bigger than 2 ("ACT" needs to be excluded, while "I" does not). It writes in a new file ("RomeoAndJuliet-cleaned.txt") the whole text without those elements, so now it's ready to be analyzed.

##
