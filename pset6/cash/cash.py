from cs50 import get_float

# Prompt user for input
while True: 
    dollar = get_float("Change owed: ")
    if dollar > 0:
        break

# Change dollar to cents    
cents = round(dollar * 100)         

# Calculate number of coins
coins = 0                                               

while(cents >= 25):
    cents = cents - 25
    coins += 1
    
while(cents >= 10):
    cents = cents - 10
    coins += 1
    
while(cents >= 5):
    cents = cents - 5
    coins += 1
    
while(cents >= 1):
    cents = cents - 1
    coins += 1
    
print(coins)