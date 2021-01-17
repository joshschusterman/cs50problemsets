# Input user for text.
text = input("Text: ")

letters = 0
word_count = 0
sentence_count = 0
alphabet = [
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
]

# Get letter count, ignore spaces and punctuation by using alphabet list.
for letter in text:
    if letter.lower() in alphabet:
        letters += 1

# Get word count.
word_count = len(text.split(' '))

# Get sentence count. There may be a cleaner way to do this, but it works, and in one line of code.
sentence_count = (len(text.split('.')) - 1) + (len(text.split('?')) - 1) + (len(text.split('!')) - 1)

# average number of letters per 100 words in the text
l = 100 * letters / word_count
# average number of sentences per 100 words in the text
s = 100 * sentence_count / word_count

# Coleman-Liau index
index = 0.0588 * l - 0.296 * s - 15.8

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")