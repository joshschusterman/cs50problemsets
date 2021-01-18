import csv
import sys

# Check to see if all necesary arguments are typed into command line.
if len(sys.argv) != 3:
    print("Usage: python3 dna.py database/size sequences/#.txt")
    sys.exit() # FYI 'break' can't be used in an if statement, only loops.

# Open the databse file, add each row to a dictionary.
with open(sys.argv[1], 'r') as database:
    # Set up the dictionary that will hold the database (names and max counts of consecutive strands)
    db = {}
    # use csv.reader to "read" the contents of the database and store it in a list called dna.
    dna = csv.reader(database)
    # Iterate over each row in the database
    for row in dna:
        # For each row, assign the key of db to the first value in the current databse row (name of the person)
        # Then assign the value that goes with that key (name) to the values, which is everything after the name.
        db[row[0]] = row[1:]
#print(db)

# Open the sequence file (a person's dna sequence), add each letter (nucleotide base) to a list.
with open(sys.argv[2], 'r') as sequence:
    strand = []
    # Assign the contents of the txt file to the variable person.
    person = sequence.read()
    # Get each "row" (in this case each nucleotide letter in the txt file) and add it to the list (strand).
    for row in person:
        strand.append(row)
    # print(strand)

# Initialize a list to hold the max_counter values in the dna sequence to later compare with database.
spot = []

# Iterate over each of the testing strands (3 in small databse, 8 in large).
for i in range(0, len(db["name"])):
    index = 0
    counter = 0
    max_counter = 0
    for letter in strand:
        # create the strand "window", make it as long as the current database strand we're checking.
        window = ''.join(strand[index: index + len(db["name"][i])])
        if window == db["name"][i]:
            index += len(db["name"][i])
            counter += 1
            if counter > max_counter:
                max_counter = counter
        else:
            index += 1
            # IMPORTANT - must reset the counter to 0 here after the consecutive repetition of a sequence is broken.
            counter = 0

    spot.append(str(max_counter))

# Iterate over db (the names with their sequence counts).
# If matches the sequence counts we just got and put into spot, print name of person.
for k, v in db.items():
    if v == spot:
        print(k)
        sys.exit()
print("No match")