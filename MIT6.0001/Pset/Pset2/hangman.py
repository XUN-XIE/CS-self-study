# Problem Set 2, hangman.py
# Name: 
# Collaborators:
# Time spent:

# Hangman Game
# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)
import random
import string
import os

WORDLIST_FILENAME = "Pset2/words.txt"

def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist



def choose_word(wordlist):
    """
    wordlist (list): list of words (strings)
    
    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code

# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = load_words()


def is_word_guessed(secret_word, letters_guessed):
    '''
    secret_word: string, the word the user is guessing; assumes all letters are
      lowercase
    letters_guessed: list (of letters), which letters have been guessed so far;
      assumes that all letters are lowercase
    returns: boolean, True if all the letters of secret_word are in letters_guessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    for letter in letters_guessed:
        if letter not in secret_word:
            return False
    return True

# test for 1A
# print(is_word_guessed('apple', ['e', 'i', 'k', 'p', 'r', 's']))


def get_guessed_word(secret_word, letters_guessed):
    '''
    secret_word: string, the word the user is guessing
    letters_guessed: list (of letters), which letters have been guessed so far
    returns: string, comprised of letters, underscores (_), and spaces that represents
      which letters in secret_word have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    letter_list = []
    for i in range(len(secret_word)):
        letter = secret_word[i]
        if letter not in letters_guessed:
            letter_list.append('_ ')
        else:
            letter_list.append(letter)

    return ''.join(letter_list)

# test for 1B
# print("'"+get_guessed_word('apple', ['e', 'i', 'k', 'p', 'r', 's'])+"'")


def get_available_letters(letters_guessed):
    '''
    letters_guessed: list (of letters), which letters have been guessed so far
    returns: string (of letters), comprised of letters that represents which letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    all_letter = string.ascii_lowercase
    letter_list = []
    for i in range(len(all_letter)):
        letter = all_letter[i]
        if letter not in letters_guessed:
            letter_list.append(letter)

    return ''.join(letter_list)
    
# test for 1C
# print(get_available_letters(['e', 'i', 'k', 'p', 'r', 's']))


def hangman(secret_word):
    '''
    secret_word: string, the secret word to guess.
    
    Starts up an interactive game of Hangman.
    
    * At the start of the game, let the user know how many 
      letters the secret_word contains and how many guesses s/he starts with.
      
    * The user should start with 6 guesses

    * Before each round, you should display to the user how many guesses
      s/he has left and the letters that the user has not yet guessed.
    
    * Ask the user to supply one guess per round. Remember to make
      sure that the user puts in a letter!
    
    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computer's word.

    * After each guess, you should display to the user the 
      partially guessed word so far.
    
    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    left_guess = 6
    print("Welcome to the game Hangman!")
    length = len(secret_word)
    print("I am thinking of a word that is " + str(length) + " letters long")
    letters_guessed = ['']
    warning_num = 3

    while True:
        print("---------------")
        print("You have " + str(left_guess) + " guesses left")
        available_letters = get_available_letters(letters_guessed)
        print("Available letters: " + available_letters)
        print("you have " + str(warning_num) + " warning left!")
        print("Please input the guessed letter")
        letters_guesse = input()
        if letters_guesse.isalpha():
            letters_guesse = letters_guesse.lower()
            letters_guessed.append(letters_guesse)
        else:
            warning_num -= 1
            if warning_num <= 0:
                left_guess -= 1
            if left_guess <= 0:
                print("Oops! you failed!")
                break
            continue
        
        if is_word_guessed(secret_word, letters_guesse):
            print("Good guess: " + get_guessed_word(secret_word, letters_guessed))
        else:
            print("Oops! That letter is not in my word: " + get_guessed_word(secret_word, letters_guessed))
            if letters_guesse in ['a', 'e', 'i', 'o', 'u']:
                left_guess -= 2
            else:
                left_guess -= 1

        if get_guessed_word(secret_word, letters_guessed) == secret_word:
            print("Congratulations, you won!")
            unique = []
            for i in secret_word:
                if i not in unique:
                    unique.append(i)
            print("your total score for this game is: " + str(left_guess * len(unique)))
            break
        if left_guess <= 0:
            print("Oops! you failed! The word was " + secret_word)
            break



# When you've completed your hangman function, scroll down to the bottom
# of the file and uncomment the first two lines to test
#(hint: you might want to pick your own
# secret_word while you're doing your own testing)


# -----------------------------------



def match_with_gaps(my_word, other_word):
    '''
    my_word: string with _ characters, current guess of secret word
    other_word: string, regular English word
    returns: boolean, True if all the actual letters of my_word match the 
        corresponding letters of other_word, or the letter is the special symbol
        _ , and my_word and other_word are of the same length;
        False otherwise: 
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    my_word_list = list(my_word)
    count_space_or_underscore = 0
    my_alpha_index = []
    alpha_index = []
    other_alpha_index_list = []
    other_alpha_index = 0
    for i in range(len(my_word_list)):
        if my_word_list[i] == " ":
            count_space_or_underscore += 1
            other_alpha_index += 1
        elif my_word_list[i] == "_":
            count_space_or_underscore += 1
        else:
            alpha_index.append(i)
            other_alpha_index_list.append(other_alpha_index)
            other_alpha_index += 1
            
    length_my_word = len(my_word) - count_space_or_underscore / 2
    length_other_word = len(other_word)

    if length_my_word != length_other_word:
        return False

    for i in range(len(alpha_index)):
        if my_word[alpha_index[i]] != other_word[other_alpha_index_list[i]]:
            return False
    
    return True

# test for 3A
# print(match_with_gaps("te_ t", "tact"))
# print(match_with_gaps("a_ pl_ ", "apple"))


def show_possible_matches(my_word):
    '''
    my_word: string with _ characters, current guess of secret word
    returns: nothing, but should print out every word in wordlist that matches my_word
             Keep in mind that in hangman when a letter is guessed, all the positions
             at which that letter occurs in the secret word are revealed.
             Therefore, the hidden letter(_ ) cannot be one of the letters in the word
             that has already been revealed.

    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    match_word = []
    for word in wordlist:
        if match_with_gaps(my_word, word):
            match_word.append(word)
    
    if len(match_word) == 0:
        print("No matches found")
    else:
        print(match_word)

# test for 3B
# print(show_possible_matches("t_ _ t"))
# print(show_possible_matches("abbbb_ "))
# print(show_possible_matches("a_ pl_ "))

def hangman_with_hints(secret_word):
    '''
    secret_word: string, the secret word to guess.
    
    Starts up an interactive game of Hangman.
    
    * At the start of the game, let the user know how many 
      letters the secret_word contains and how many guesses s/he starts with.
      
    * The user should start with 6 guesses
    
    * Before each round, you should display to the user how many guesses
      s/he has left and the letters that the user has not yet guessed.
    
    * Ask the user to supply one guess per round. Make sure to check that the user guesses a letter
      
    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computer's word.

    * After each guess, you should display to the user the 
      partially guessed word so far.
      
    * If the guess is the symbol *, print out all words in wordlist that
      matches the current guessed word. 
    
    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    left_guess = 6
    print("Welcome to the game Hangman!")
    length = len(secret_word)
    print("I am thinking of a word that is " + str(length) + " letters long")
    letters_guessed = ['']
    warning_num = 3

    while True:
        print("---------------")
        print("You have " + str(left_guess) + " guesses left")
        available_letters = get_available_letters(letters_guessed)
        print("Available letters: " + available_letters)
        print("you have " + str(warning_num) + " warning left!")
        print("Please input the guessed letter")
        letters_guesse = input()

        if letters_guesse == "*":
            my_word = get_guessed_word(secret_word, letters_guessed)
            show_possible_matches(my_word)

        if letters_guesse.isalpha():
            letters_guesse = letters_guesse.lower()
            letters_guessed.append(letters_guesse)
        else:
            warning_num -= 1
            if warning_num <= 0:
                left_guess -= 1
            if left_guess <= 0:
                print("Oops! you failed!")
                break
            continue
        
        if is_word_guessed(secret_word, letters_guesse):
            print("Good guess: " + get_guessed_word(secret_word, letters_guessed))
        else:
            print("Oops! That letter is not in my word: " + get_guessed_word(secret_word, letters_guessed))
            if letters_guesse in ['a', 'e', 'i', 'o', 'u']:
                left_guess -= 2
            else:
                left_guess -= 1

        if get_guessed_word(secret_word, letters_guessed) == secret_word:
            print("Congratulations, you won!")
            unique = []
            for i in secret_word:
                if i not in unique:
                    unique.append(i)
            print("your total score for this game is: " + str(left_guess * len(unique)))
            break
        if left_guess <= 0:
            print("Oops! you failed! The word was " + secret_word)
            break
    



# When you've completed your hangman_with_hint function, comment the two similar
# lines above that were used to run the hangman function, and then uncomment
# these two lines and run this file to test!
# Hint: You might want to pick your own secret_word while you're testing.


if __name__ == "__main__":
    # pass

    # To test part 2, comment out the pass line above and
    # uncomment the following two lines.
    
    # secret_word = choose_word(wordlist)
    # hangman(secret_word)
    pass

###############
    
    # To test part 3 re-comment out the above lines and 
    # uncomment the following two lines. 
    
    secret_word = choose_word(wordlist)
    hangman_with_hints(secret_word)
