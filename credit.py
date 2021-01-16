# Prompt user for card number
card = input("Number: ")

# Reverse the credit card number so we can iterate more easily
copy = card[::-1]

# Make the list of every other number * 2.
sum_A = [int(x) * 2 for x in copy[1::2]]
# Make the list of the other numbers (not included in the list above).
sum_B = [int(x) for x in copy[0::2]]

# Initialize index counter
index = 0

# Iterate over each number in sum_A.
for num in sum_A:
    # If it's a 2-digit number, we need each individual digit to add together.
    if len(str(num)) == 2:
        # This iterates over the 2-digit number, converts to a list of integers, then gets their sum.
        double = sum([int(d) for d in str(num)])
        # This takes that sum and replaces this index of sum_A with it.
        sum_A[index] = double
    index += 1

# This adds the total of all the elements in sum_A and sum_B.
final_sum = sum(sum_A) + sum(sum_B)

# If the last digit of the number is 0, it's a valid card. Set boolean.
if str(final_sum)[-1] == "0":
    valid = True
else:
    valid = False

# If card has passed validation (above), figure out if it's AMEX, MASTERCARD, or VISA.
if valid == True:
    if len(card) == 15 and card[0:2] == "37" or card[0:2] == "34":
        print("AMEX")

    elif len(card) == 16 and card[0:2] == "51" or card[0:2] == "52" or card[0:2] == "53" or card[0:2] == "54" or card[0:2] == "55":
        print("MASTERCARD")

    elif len(card) == 13 or len(card) == 16 and card[0] == "4":
        print("VISA")
    # This is in case the card validates (passes the checksum) but isn't any of the above cards.
    else:
        print("INVALID")
# And this one is needed if it doesn't pass the checksum.
else:
    print("INVALID")

# NOTES: I know there are some more pythonic ways of doing parts of this code, including putting certain
# actions into functions. Will revisit later.