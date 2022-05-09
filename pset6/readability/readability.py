from cs50 import get_string

# Get user input
s = get_string("Text: ")

# Initialize letter word sentences
letters = 0
words = 1
sentences = 0

# Loop over the string
for i in range(len(s)):
    if s[i].isalpha():
        letters += 1
    if s[i].isspace():
        words += 1
    if s[i] == '.' or s[i] == '!' or s[i] == '?':
        sentences += 1

# Calculate grade level
L = letters / (words / 100)
S = sentences / (words / 100)
I = round((0.0588 * L) - (0.296 * S) - 15.8)

# Print grade level
if I < 1:
    print("Before Grade 1")

elif I > 16:
    print("Grade 16+")
    
elif I >= 1 or I <= 16:
    print(f"Grade {I}")