epsilon = 0.01
k = 25.0
guess = k / 2.0
num_Guess = 0
while abs(guess ** 2 - k) >= epsilon:
    guess -= (((guess**2) - k) / (2 * guess))
    num_Guess += 1
print("Square root of " + str(k) + ' is about ' + str(guess))
print("nuber of guess = " + str(num_Guess))