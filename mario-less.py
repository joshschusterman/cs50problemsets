height = 0

while True:
    try:
        height = int(input("Height: "))
        if height in range(1, 9):
            break
    except:
        continue

for i in range(1, height + 1):
    print((" " * (height - i)) + ("#" * i))