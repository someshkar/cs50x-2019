from cs50 import get_string
from sys import argv


def main():
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    file = open(argv[1])
    banned_words = set()

    for line in file:
        banned_words.add(line.strip().lower())

    input_str = get_string("What message would you like to censor?\n")
    output_str = ""

    words = input_str.split()

    for word in words:
        if word.lower() in banned_words:
            output_str += "*" * len(word) + " "
        else:
            output_str += word + " "

    print(output_str + "\n")


if __name__ == "__main__":
    main()
