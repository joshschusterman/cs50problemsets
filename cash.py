change = 0
coins = 0

while True:
    try:
        change = float(input("Change owed: "))
        if float(change) > 0:
            break
    except:
        continue

# I can't find a way to reprompt user if they type a string other than exception handling.

# I don't understand why we can keep this in float (dollars and cents) for it to work.
change = int(change * 100)

while change >= 25:
    coins += 1
    change = change - 25

while change >= 10:
    coins += 1
    change = change - 10

while change >= 5:
    coins += 1
    change = change - 5

while change > 0:
    coins += 1
    change = change - 1

print(coins)